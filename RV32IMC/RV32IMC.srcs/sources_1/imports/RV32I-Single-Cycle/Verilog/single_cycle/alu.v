module ALU (
   alu_operand_in,operand1_in,operand2_in,alu_result_out
 );
   input [3:0]alu_operand_in;
   input [31:0]operand1_in,operand2_in;
   output reg signed [31:0]alu_result_out ;


 always @* begin
      case (alu_operand_in)
         4'b0000 : alu_result_out = operand1_in + operand2_in; 
         4'b0001 : alu_result_out = operand1_in - operand2_in;
         4'b0010 : alu_result_out = operand1_in & operand2_in;
         4'b0011 : alu_result_out = operand1_in | operand2_in;
         4'b0100 : alu_result_out = operand1_in ^ operand2_in;
         4'b0101 : alu_result_out = operand1_in << operand2_in;
         4'b0110 : alu_result_out = operand1_in >> operand2_in;
         4'b0111 : alu_result_out[0] = (operand1_in < operand2_in) ? 1 : 0;
         4'b1000 : alu_result_out[0] = ($signed (operand1_in) < $signed (operand2_in)) ? 1 : 0;
         4'b1001 : alu_result_out = operand1_in >>> operand2_in;
         4'b1111 : alu_result_out = operand1_in ;
         default: alu_result_out = 0;
      endcase
 end

endmodule
