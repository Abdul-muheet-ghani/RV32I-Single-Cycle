module branch (
   operand1_in,operand2_in,function_3_in,branch_en_in,branch_taken_out
 );

 input [31:0]operand1_in,operand2_in;
 input [2:0]function_3_in;
 input branch_en_in;
 output reg branch_taken_out;
 wire function_3_in;

 always @* begin
    if(branch_en_in==1)begin
       case (function_3_in)
          3'b000 : branch_taken_out = (operand1_in == operand2_in) ? 1 : 0 ;
          3'b001 : branch_taken_out = (operand1_in != operand2_in) ? 1 : 0 ;
          3'b100 : branch_taken_out = ($signed (operand1_in) < $signed (operand2_in)) ? 1 : 0 ;
          3'b101 : branch_taken_out = ($signed (operand1_in) >= $signed (operand2_in)) ? 1 : 0 ;
          3'b110 : branch_taken_out = (operand1_in < operand2_in) ? 1 : 0 ;
          3'b111 : branch_taken_out = (operand1_in >= operand2_in) ? 1 : 0 ;
       endcase
    end
 end
   
endmodule
