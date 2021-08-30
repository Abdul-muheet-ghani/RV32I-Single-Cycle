module reg_file (
   clk,rs1,rs2,rd,write_back,op_rs1,op_rs2,wr
 );

 input clk,wr;
 input [31:0]write_back;
 input [4:0]rs1,rs2,rd;
 output wire[31:0]op_rs1,op_rs2;
 reg [31:0] reg_mem[32-1:0];

 always @(*) begin
    reg_mem[rd]<=write_back;
 end
   assign op_rs1=reg_mem[rs1];
   assign op_rs2=reg_mem[rs2];
endmodule


