//////////////////////////////////////////////////////////////////////////////////
// Company: MERL-UITU
// Engineer: Abdul Muheet Ghani
// 
// Design Name: RV32IMACZicsr for Linux
// Module Name: Branch
// Project Name: RV32IMACZicsr for linux
// Target Devices: 
// Description: 
// 
//////////////////////////////////////////////////////////////////////////////////

`include "RV32_pkg.vh"

module branch (
   input [31:0] operand1_in,
   input [31:0] operand2_in,
   input [2:0]  function_3_in,
   input        branch_en_in,
   output reg   branch_taken_out
 );

 always @* begin
    if(branch_en_in)begin
       case (function_3_in)
          `FUNCT3_BEQ  : branch_taken_out = (operand1_in == operand2_in);
          `FUNCT3_BNEQ : branch_taken_out = (operand1_in != operand2_in);
          `FUNCT3_BLT  : branch_taken_out = ($signed (operand1_in) < $signed (operand2_in));
          `FUNCT3_BGE  : branch_taken_out = ($signed (operand1_in) >= $signed (operand2_in));
          `FUNCT3_BLTU : branch_taken_out = (operand1_in < operand2_in);
          `FUNCT3_BGEU : branch_taken_out = (operand1_in >= operand2_in);
       endcase
    end
 end
   
endmodule
