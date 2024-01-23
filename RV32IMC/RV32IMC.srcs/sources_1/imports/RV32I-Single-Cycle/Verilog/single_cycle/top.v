module RV32I (
    input         clk,
    input         we,
    input         reset,
    input  [31:0] data_in,
    output [31:0] data_out
);

   /////////////////////////////////////////////////////////
   //ports
   /////////////////////////////////////////////////////////

 wire [31:0]OUT_T,addr,offset_adder,b,I,S,SB,UJ,U,op1,op2,reg_1,reg_2,im,ALU_OUTPUT,write_adder,write_ba,rite_ba,rb1 ;
 wire [8:0]c ;
 wire [4:0]r1,r2,rf ;
 reg [4:0]re;
 reg [31:0]wb,address_q ;
 wire branch_p;
 reg [2:0]fun_3 ;
 reg [31:0]ac,addr1=0 ;
 reg [1:0]opa,next_pc=0,imm_sel ;
 reg reg_write,mem_to_reg,mem_write,branch1,opb,j;
 reg [3:0]alu_op;
 wire [31:0]zero = 0 ;

   assign offset_adder = (we) ? 0 : address_q + 4; 
   assign addr = (next_pc == 2'b00) ? offset_adder :
                 (next_pc == 2'b01) ? UJ :
                 (next_pc == 2'b10) ? OUT_T :
                 (next_pc == 2'b11) ? I + reg_1 : 0;

   assign reg_1 = (opa == 2'b00) ? op1 :
                 (opa == 2'b01) ? offset_adder :
                 (opa == 2'b10) ? OUT_T :
                 (opa == 2'b11) ? zero : 0;

   assign im    = (imm_sel == 2'b00) ? zero :
                  (imm_sel == 2'b01) ? U :
                  (imm_sel == 2'b10) ? I :
                  (imm_sel == 2'b11) ? S : 0;
               
   assign reg_2 = (opb) ? im : op2;
   assign write_ba = (mem_to_reg) ? write_adder : ALU_OUTPUT;
   assign rite_ba = (mem_write) ? zero : write_ba;
   assign OUT_T = (branch_p) ? SB : offset_adder;

   assign r1 = b[19:15];
   assign r2 = b[24:20];
   assign rf = re;
 
   //Address of instruction_mem from 2 to 13 because of offset = 4
   ram instruction_mem(clk,address_q[13:2],data_in,b,we); 
   control control(b,c);
   unit unit(c,b,data_out);
   ALU ALU(alu_op,reg_1,reg_2,ALU_OUTPUT);
   branch branch(reg_1,reg_2,fun_3,branch1,branch_p);
   data_mem data_mem(clk,ALU_OUTPUT,op2,mem_write,mem_to_reg,write_adder);
   reg_file reg_file(r1,r2,rf,wb,op1,op2,clk,reset);
   immediate immediate(b,address_q,I,S,SB,UJ,U);

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
      imm_sel = data_out[1:0];
      alu_op = data_out[5:2];
      next_pc = data_out[7:6];
      opb = data_out[8];
      opa = data_out[10:9];
      branch1 = data_out[11];
      mem_write = data_out[12];
      mem_to_reg = data_out[13];
      reg_write = data_out[14];
      fun_3 = b[14:12];
      j = c[3];
      if (j == 1) begin
         re = 5'b00001;
         wb = address_q + 4;
      end else begin
         re = b[11:7];
         wb = rite_ba;
      end
   end 

endmodule
