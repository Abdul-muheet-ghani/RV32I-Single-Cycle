//////////////////////////////////////////////////////////////////////////////////
// Company: MERL-UITU
// Engineer: Abdul Muheet Ghani
// 
// Design Name: RV32IMACZicsr for Linux
// Module Name: type decoder
// Project Name: RV32IMACZicsr for linux
// Target Devices: 
// Description: 
// 
//////////////////////////////////////////////////////////////////////////////////

module control (
   input      [31:0]opcode_in,
   output reg [8:0] decoded_out
 );

   /////////////////////////////////////////////////////////
   //always block
   /////////////////////////////////////////////////////////

   always @* begin
      case (opcode_in[6:0])
         7'b0110011 : decoded_out = 9'b100000000;
         7'b0010011 : decoded_out = 9'b010000000;
         7'b0000011 : decoded_out = 9'b001000000;
         7'b0100011 : decoded_out = 9'b000100000;
         7'b1100011 : decoded_out = 9'b000010000;
         7'b1101111 : decoded_out = 9'b000001000;
         7'b1100111 : decoded_out = 9'b000000100;
         7'b0110111 : decoded_out = 9'b000000010;
         7'b0010111 : decoded_out = 9'b000000001; 
         default: decoded_out = 0;
      endcase
   end

endmodule
