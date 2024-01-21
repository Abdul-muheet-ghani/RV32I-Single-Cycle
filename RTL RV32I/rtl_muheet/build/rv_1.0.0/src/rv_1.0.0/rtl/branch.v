module branch (
   op1,op2,fu_3,en,re
 );

 input [31:0]op1,op2;
 input [2:0]fu_3;
 input en;
 output reg re;
 wire fu_3;

 always @* begin
    if(en==1)begin
       case (fu_3)
          3'b000 : re = (op1 == op2) ? 1 : 0 ;
          3'b001 : re = (op1 != op2) ? 1 : 0 ;
          3'b100 : re = ($signed (op1) < $signed (op2)) ? 1 : 0 ;
          3'b101 : re = ($signed (op1) >= $signed (op2)) ? 1 : 0 ;
          3'b110 : re = (op1 < op2) ? 1 : 0 ;
          3'b111 : re = (op1 >= op2) ? 1 : 0 ;
       endcase
    end
 end
   
endmodule