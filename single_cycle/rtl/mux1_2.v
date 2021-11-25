module mux1_2 (
   sel,a,b,c
 );
   input sel;
   input [31:0]a,b;
   output reg [31:0]c ;
   
 always @* begin
   case (sel)
      1'b0 : c = a;
      1'b1 : c = b; 
      
   endcase
 end


endmodule