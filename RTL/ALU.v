module ALU (
   op,op1,op2,res
); //Module ALU
   input [3:0]op;
   input [31:0]op1,op2;
   output reg signed [31:0]res ;


 always @* begin
      case (op)
         4'b0000 : res = op1 + op2; 
         4'b0001 : res = op1 - op2;
         4'b0010 : res = op1 & op2;
         4'b0011 : res = op1 | op2;
         4'b0100 : res = op1 ^ op2;
         4'b0101 : res = op1 << op2;
         4'b0110 : res = op1 >> op2;
         4'b0111 : res[0] = (op1 < op2) ? 1 : 0;
         4'b1000 : res[0] = ($signed (op1) < $signed (op2)) ? 1 : 0;
         4'b1001 : res = op1 >>> op2;
         4'b1111 : res = op1 ;
         default: res = 0;
      endcase
 end

endmodule
