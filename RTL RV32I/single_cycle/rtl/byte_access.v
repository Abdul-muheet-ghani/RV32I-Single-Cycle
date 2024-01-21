module byte_acces (
   byte_address,Byte_access,word
 );

 input [1:0]byte_address;
 input [31:0]word;
 output reg [7:0]Byte_access;

 always @(*) begin
   case (byte_address)
      2'b00 :  Byte_access = word[7:0];
      2'b01 :  Byte_access = word[15:8];
      2'b10 :  Byte_access = word[23:16];
      2'b11 :  Byte_access = word[31:24];
   endcase
 end
   
endmodule