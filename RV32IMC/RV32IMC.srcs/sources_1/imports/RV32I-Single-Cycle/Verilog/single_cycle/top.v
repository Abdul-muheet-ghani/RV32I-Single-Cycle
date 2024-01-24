//////////////////////////////////////////////////////////////////////////////////
// Company: MERL-UITU
// Engineer: Abdul Muheet Ghani
// 
// Design Name: RV32IMACZicsr for Linux
// Module Name: RV32I-top
// Project Name: RV32IMACZicsr for linux
// Target Devices: 
// Description: 
// 
//////////////////////////////////////////////////////////////////////////////////

module RV32I_top #(parameter XLEN = 32)
(
    input             clk,
    input             we,
    input             reset,
    input  [XLEN-1:0] data_in,
    output [XLEN-1:0] control_unit_out
);

   /////////////////////////////////////////////////////////
   //ports
   /////////////////////////////////////////////////////////

   wire [XLEN-1:0] OUT_T;
   wire [XLEN-1:0] addr;
   wire [XLEN-1:0] offset_adder;
   wire [XLEN-1:0] inst_out;
   wire [XLEN-1:0] I_type;
   wire [XLEN-1:0] S_type;
   wire [XLEN-1:0] SB_type;
   wire [XLEN-1:0] UJ_type;
   wire [XLEN-1:0] U_type;
   wire [XLEN-1:0] operand1;
   wire [XLEN-1:0] operand2;
   wire [XLEN-1:0] reg_1;
   wire [XLEN-1:0] reg_2;
   wire [XLEN-1:0] immediate;
   wire [XLEN-1:0] ALU_OUTPUT;
   wire [XLEN-1:0] write_adder;
   wire [XLEN-1:0] write_back;
   wire [8:0]      contrl_decoder;
   wire [4:0]      rd ;          //destination register
   wire            branch_p;
   reg [XLEN-1:0]  wb,address_q;
   reg [1:0]       next_pc=0;

   /////////////////////////////////////////////////////////
   //procedural assignment
   /////////////////////////////////////////////////////////

   assign offset_adder = (we) ? 0 : address_q + 4; 
   assign addr = (next_pc == 2'b00) ? offset_adder :
                 (next_pc == 2'b01) ? UJ_type :
                 (next_pc == 2'b10) ? OUT_T :
                 (next_pc == 2'b11) ? I_type + reg_1 : 0;

   // output of control unit 10:9 is for operand a selection
   assign reg_1 = (control_unit_out[10:9] == 2'b00) ? operand1 :
                  (control_unit_out[10:9] == 2'b01) ? offset_adder :
                  (control_unit_out[10:9] == 2'b10) ? OUT_T :
                  (control_unit_out[10:9] == 2'b11) ? 32'b0 : 0;

   // output of control unit [1:0] is for immediate select
   assign immediate = (control_unit_out[1:0] == 2'b00) ? 32'b0 :
                      (control_unit_out[1:0] == 2'b01) ? U_type :
                      (control_unit_out[1:0] == 2'b10) ? I_type :
                      (control_unit_out[1:0] == 2'b11) ? S_type : 0;
               
   // Output of control unit bit 8 presents operand b selection 
   // either be it immediate or reg2            
   assign reg_2 = (control_unit_out[8]) ? immediate : operand2;

   // Output of control unit control_unit_out[12] present mem_write enable
   // Output of control unit control_unit_out[13] present mem_to_reg enable
   assign write_back = (control_unit_out[12]) ? 32'b0 : 
                       (control_unit_out[13]) ? write_adder : ALU_OUTPUT;

   assign OUT_T = (branch_p) ? SB_type : offset_adder;

   // 11:7 destination register
   assign rd = contrl_decoder[3] ? 5'b00001 : inst_out[11:7];;

   /////////////////////////////////////////////////////////
   //Module Instantiation
   /////////////////////////////////////////////////////////

   //Address of instruction_mem from 2 to 13 because of offset = 4
   ram instruction_mem(.clk_in          (clk),
                       .address_in      (address_q[13:2]),
                       .data_in         (data_in),
                       .instruction_out (inst_out),
                       .we_in           (we)
                     ); 

   control control_decoder(.opcode_in  (inst_out),
                           .decoded_out(contrl_decoder)
                           );

   unit control_unit(.type_decode_in  (contrl_decoder),
                     .function_3_in   (inst_out[14:12]),
                     .function_7_in   (inst_out[30]),
                     .control_unit_out(control_unit_out)
                     );

   // Output of control unit 5:2 is ALU operand for selecting operation (i.e +,-,or,xor etc)
   ALU ALU(.alu_operand_in(control_unit_out[5:2]),
           .operand1_in   (reg_1),
           .operand2_in   (reg_2),
           .alu_result_out(ALU_OUTPUT)
           );

   // 14:12 function 3
   // Ouput of control unit bit 11 presents branch enable
   branch branch(.operand1_in     (reg_1),
                 .operand2_in     (reg_2),
                 .function_3_in   (inst_out[14:12]),
                 .branch_en_in    (control_unit_out[11]),
                 .branch_taken_out(branch_p)
                 );

   // Output of control unit control_unit_out[12] present mem_write enable
   // output of control unit control_unit_out[13] present mem_to_reg enable
   data_mem data_mem(.clk_in        (clk),
                     .address_in    (ALU_OUTPUT),
                     .store_data_in (operand2),
                     .store_en_in   (control_unit_out[12]),
                     .load_en_in    (control_unit_out[13]),
                     .data_out      (write_adder)
                     );

   // 19:15 rs1 address
   // 24:20 rs2 address
   reg_file reg_file(.clk_in                 (clk),
                     .reset_in               (reset),
                     .rs1_address_in         (inst_out[19:15]),
                     .rs2_address_in         (inst_out[24:20]),
                     .destination_register_in(rd),
                     .input_data_in          (wb),
                     .rs1_data_out           (operand1),
                     .rs2_data_out           (operand2)
                     );

   immediate immediate(.instruction_in    (inst_out),
                       .pc_in             (address_q),
                       .I_type_imm_out    (I_type),
                       .S_type_imm_out    (S_type),
                       .SB_type_imm_out   (SB_type),
                       .UJ_type_imm_out   (UJ_type),
                       .U_type_imm_out    (U_type)
                       );

   /////////////////////////////////////////////////////////
   //always block
   /////////////////////////////////////////////////////////

   always @(posedge clk) begin
      if(reset)
      begin
         address_q = 32'b0;
      end
      else begin
         address_q = addr;
      end
   end

   always @* begin
      next_pc = control_unit_out[7:6];

      // bit 3 is for jump
      if (contrl_decoder[3]) begin
         wb = address_q + 4;
      end else begin
         wb = write_back;
      end
   end 

endmodule