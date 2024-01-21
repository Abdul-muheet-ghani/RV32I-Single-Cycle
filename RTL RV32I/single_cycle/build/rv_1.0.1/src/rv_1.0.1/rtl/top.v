module top (
    clk,
    reset,
    o_pc,
    o_alu,
    o_opb,
    o_ld,
    o_sw,
    i_wb,
    i_instr

 `ifdef RISCV_FORMAL
   output reg 		            rvfi_valid = 1'b0,
   output reg [63:0] 	      rvfi_order = 64'd0,
   output reg [31:0] 	      rvfi_insn = 32'd0,
   output reg 		            rvfi_trap = 1'b0,
   output reg 		            rvfi_halt = 1'b0,
   output reg 		            rvfi_intr = 1'b0,
   output reg [1:0] 	         rvfi_mode = 2'b11,
   output reg [1:0] 	         rvfi_ixl = 2'b01,
   output reg [4:0] 	         rvfi_rs1_addr,
   output reg [4:0] 	         rvfi_rs2_addr,
   output reg [31:0] 	      rvfi_rs1_rdata,
   output reg [31:0] 	      rvfi_rs2_rdata,
   output reg [4:0] 	         rvfi_rd_addr,
   output reg [31:0] 	      rvfi_rd_wdata,
   output reg [31:0] 	      rvfi_pc_rdata,
   output reg [31:0] 	      rvfi_pc_wdata,
   output reg [11:0] 	      rvfi_mem_addr,
   output reg [3:0] 	         rvfi_mem_rmask,
   output reg [3:0] 	         rvfi_mem_wmask,
   output reg [31:0] 	      rvfi_mem_rdata,
   output reg [31:0] 	      rvfi_mem_wdata,
`endif
);
 input        clk;
 input        reset;
 input        [31:0]i_wb;
 input        [31:0]i_instr;
 wire         [14:0]data_out ;
 inout       [11:0]o_pc;
 output       [11:0]o_alu;
 output       [31:0]o_opb;
 output       signed o_ld;
 output       o_sw;
 wire         branch_p;
 /* verilator lint_off UNOPTFLAT */wire         [31:0]OUT_T;
 wire         [31:0]addr;
 wire         [31:0]adr;
 wire         [31:0]a;
 wire         [31:0]b;
 wire         [31:0]I;
 wire         [31:0]S;
 wire         [31:0]SB;
 wire         [31:0]UJ;
 wire         [31:0]U;
 wire         [31:0]op1;
 wire         [31:0]op2;
 wire         [31:0]faltu;
 wire         [31:0]reg_1;
 wire         [31:0]reg_2;
 wire         [31:0]im;
 wire         [31:0]ALU_OUTPUT;
 wire         [31:0]write_adder;
 wire         [31:0]write_ba;
 wire         [31:0]rite_ba;
 wire         [31:0]rb1 ;
 wire         [8:0]c ;
 wire         [4:0]r1,r2,rf ;
 wire         [11:0]after_PC ;
 reg          [4:0]re;
 reg          [31:0]wb ;
 reg          [2:0]fun_3 ;
 reg          [31:0]ac,addr1=0 ;
 reg          [1:0]opa,next_pc=0,imm_sel ;
 
 adder            adder(.adr(adr),
                        .a(a));


 PC               PC(.in(addr),
                     .out(adr),
                     .clk(clk),
                     .we(reset));
                     
 assign after_PC[11:0] = adr[13:2];
 assign o_pc = after_PC;



 mux2_4 PC_mux(.sel(next_pc),
               .a(a),
               .b(UJ),
               .c(OUT_T),
               .d(I + reg_1),
               .o(addr));



 control control(.opcode(i_instr),
                 .dec(c));


 unit unit(.dec(c),
           .in(i_instr),
           .un(data_out));


 reg reg_write,mem_to_reg,mem_write,branch1,opb,j;
 reg [3:0]alu_op;
 wire [31:0]zero = 0 ;

 

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
    fun_3 = i_instr[14:12];
    j = c[3];
    if (j == 1) begin
       wb = adr + 4;
    end else begin
       wb = rite_ba;
    end
    wb = i_wb;
 end

 assign o_ld=mem_to_reg;
 assign o_sw=mem_write;

 `ifdef RISCV_FORMAL
 always @(*) begin
    
  //  if (conditions) begin
       rvfi_rs1_addr     <=   r1;
       rvfi_rs2_addr     <=   r2;
       rvfi_rd_addr      <=   rf;
       rvfi_rs1_rdata    <=   op1;
       rvfi_rs2_rdata    <=   op2;
       rvfi_rd_wdata     <=   wb;
       rvfi_pc_rdata     <=   adr;
       rvfi_pc_wdata     <=   addr;
       rvfi_mem_addr     <=   after_PC;
       rvfi_mem_rdata    <=   write_adder;
       rvfi_mem_wdata    <=   op2;
    end
 
 
 `endif

 assign r1 = i_instr[19:15];
 assign r2 = i_instr[24:20];
 assign rf = i_instr[11:7];

 reg_file reg_file(r1,r2,rf,write_ba,op1,op2,clk,reset);
 
 assign o_opb = op2;

 immediate immediate(i_instr,adr,I,S,SB,UJ,U);
 mux2_4 opa_mux(.sel(opa),
                .a(op1),
                .b(a),
                .c(OUT_T),
                .d(zero),
                .o(reg_1));


 mux2_4 immediate_mux(.sel(imm_sel),
                .a(zero),
                .b(U),
                .c(I),
                .d(S),
                .o(im));


 mux1_2 mux1_20(.sel(opb),
                .a(op2),
                .b(im),
                .c(reg_2));

 ALU ALU(.op(alu_op),
         .op1(reg_1),
         .op2(reg_2),
         .res(ALU_OUTPUT));

         
         
/* verilator lint_off WIDTH */assign o_alu=ALU_OUTPUT;

 branch branch(.op1(reg_1),
               .op2(reg_2),
               .fu_3(fun_3),
               .en(branch1),
               .re(branch_p));


 mux1_2 mux1_21(.sel(mem_to_reg),
                .a(ALU_OUTPUT),
                .b(i_wb),
                .c(write_ba));


 mux1_2 mux1_22(.sel(mem_write),
                .a(write_ba),
                .b(zero),
                .c(rite_ba));


 mux1_2 branch_mux(.sel(branch_p),
                .a(a),
                .b(SB),
                .c(OUT_T));
endmodule
