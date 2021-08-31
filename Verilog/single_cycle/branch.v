module branch (
   op1,op2,fu_3,en,re
 );

 input [31:0]op1,op2;
 input [2:0]fu_3;
 input en;
 output reg re;
 wire fu_3;

 always @* begin
   if (fu_3 == 3'b000) begin
   if (op1 == op2) begin
      re = 1;
   end else begin
      re = 0;
   end
 end
   if (fu_3 == 3'b001) begin
   if (op1 != op2) begin
      re = 1;
   end else begin
      re = 0;
   end
 end
   if (fu_3 == 3'b100) begin
   if (op1 < op2) begin
      re = 1;
   end else begin
      re = 0;
   end
 end
   if (fu_3 == 3'b101) begin
   if (op1 >= op2) begin
      re = 1;
   end else begin
      re = 0;
   end
 end 
   if (fu_3 == 3'b110) begin
   if (op1 < op2) begin
      re = 1;
   end else begin
      re = 0;
   end
 end
   if (fu_3 == 3'b111) begin
   if (op1 >= op2) begin
      re = 1;
   end else begin
      re = 0;
   end
 end


 end
   
endmodule
