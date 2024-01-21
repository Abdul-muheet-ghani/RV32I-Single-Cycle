module as (
    clk,data_in,data_out,we,reset
 );

 input clk,we,reset;
 input [31:0]data_in ;
 output [14:0]data_out ;
 wire [31:0]OUT_T,addr,adr,a,b,I,S,SB,UJ,U,op1,op2,faltu,reg_1,reg_2,im,ALU_OUTPUT,write_adder,write_ba,rite_ba,rb1 ;
 wire [8:0]c ;
 wire [4:0]r1,r2,rf ;
 reg [4:0]re;
 reg [31:0]wb ;
 wire [11:0]after_PC ;
 wire branch_p;
 reg [2:0]fun_3 ;
 reg [31:0]ac,addr1=0 ;
 reg [1:0]opa,next_pc=0,imm_sel ;

 //output [31:0]op1,op2;
 
 adder adder(clk,adr,a,we);
 mux2_4 mux2_4(next_pc,a,UJ,OUT_T,I + reg_1,addr);
 PC PC(addr,adr,clk,reset);
 assign after_PC[11:0] = adr[13:2];
 ram ram(clk,after_PC,data_in,b,we);
 control control(b,c);
 unit unit(c,b,data_out);
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
    fun_3 = b[14:12];
    j = c[3];
    if (j == 1) begin
       re = 5'b00001;
       wb = adr + 4;
    end else begin
       re = b[11:7];
       wb = rite_ba;
    end
 end
 assign r1 = b[19:15];
 assign r2 = b[24:20];
 assign rf = re;

 reg_file reg_file(r1,r2,rf,wb,op1,op2,clk,reset);
 immediate immediate(b,adr,I,S,SB,UJ,U);
 mux2_4 mux2_40(opa,op1,a,OUT_T,zero,reg_1);
 mux2_4 mux2_42(imm_sel,zero,U,I,S,im);
 mux1_2 mux1_20(opb,op2,im,reg_2);
 ALU ALU(alu_op,reg_1,reg_2,ALU_OUTPUT);
 branch branch(reg_1,reg_2,fun_3,branch1,branch_p);
 data_mem data_mem(clk,ALU_OUTPUT,op2,mem_write,mem_to_reg,write_adder);
 mux1_2 mux1_21(mem_to_reg,ALU_OUTPUT,write_adder,write_ba);
 mux1_2 mux1_22(mem_write,write_ba,zero,rite_ba);
 mux1_2 mux1_23(branch_p,a,SB,OUT_T);
endmodule
