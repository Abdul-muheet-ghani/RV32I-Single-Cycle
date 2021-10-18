module mux2_4 (
   sel,a,b,c,d,o
 );

 input [1:0]sel;
 input [31:0]a,b,c,d;
 output reg [31:0]o ;

 always @* begin
   case (sel)
      2'b00 : o = a;
      2'b01 : o = b;
      2'b10 : o = c;
      2'b11 : o = d; 
   endcase
 end
   
endmodule