module control (
   input [31:0]opcode,output reg [8:0]dec
 );
 reg [6:0]c ;
 reg [31:7]b;

 always @* begin
    c = opcode[6:0];
 end


 always @* begin
   case (c)
      7'b0110011 : dec = 9'b100000000;
      7'b0010011 : dec = 9'b010000000;
      7'b0000011 : dec = 9'b001000000;
      7'b0100011 : dec = 9'b000100000;
      7'b1100011 : dec = 9'b000010000;
      7'b1101111 : dec = 9'b000001000;
      7'b1100111 : dec = 9'b000000100;
      7'b0110111 : dec = 9'b000000010;
      7'b0010111 : dec = 9'b000000001; 
      default: dec = 0;
   endcase
end

endmodule
