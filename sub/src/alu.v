//////////////////////////////////////////////////////////////////////////////////
// Company: MERL-UITU
// Engineer: Abdul Muheet Ghani
// 
// Design Name: RV32IMACZicsr for Linux
// Module Name: ALU
// Project Name: RV32IMACZicsr for linux
// Target Devices: 
// Description: 
// 
//////////////////////////////////////////////////////////////////////////////////

module ALU (
   input             [3:0]  alu_operand_in,
   input             [31:0] operand1_in,
   input             [31:0] operand2_in,
   output reg signed [31:0] alu_result_out
 );

 always @* begin
      case (alu_operand_in)
         `ALU_OP_ADD  : alu_result_out = operand1_in + operand2_in; 
         `ALU_OP_SUB  : alu_result_out = operand1_in - operand2_in;
         `ALU_OP_AND  : alu_result_out = operand1_in & operand2_in;
         `ALU_OP_OR   : alu_result_out = operand1_in | operand2_in;
         `ALU_OP_XOR  : alu_result_out = operand1_in ^ operand2_in;
         `ALU_OP_SLL  : alu_result_out = operand1_in << operand2_in;
         `ALU_OP_SRL  : alu_result_out = operand1_in >> operand2_in;
         `ALU_OP_SLTU : alu_result_out[0] = (operand1_in < operand2_in);
         `ALU_OP_SLT  : alu_result_out[0] = ($signed (operand1_in) < $signed (operand2_in));
         `ALU_OP_SRA  : alu_result_out = operand1_in >>> operand2_in;
         `ALU_OP      : alu_result_out = operand1_in;
         default: alu_result_out = 0;
      endcase
 end

endmodule
