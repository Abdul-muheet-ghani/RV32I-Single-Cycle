//////////////////////////////////////////////////////////////////////////////////
// Company: MERL-UITU
// Engineer: Abdul Muheet Ghani
// 
// Design Name: RV32IMACZicsr for Linux
// Module Name: Instruction Memory
// Project Name: RV32IMACZicsr for linux
// Target Devices: 
// Description: 
// 
//////////////////////////////////////////////////////////////////////////////////

module ram #(
   parameter address = 12, size = 32
 ) (
    input             clk_in,
    input             we_in,
    input      [11:0] address_in,
    input      [31:0] data_in,
    output reg [31:0] instruction_out
   );

   /////////////////////////////////////////////////////////
   //ports
   /////////////////////////////////////////////////////////   

   reg [31:0] mem[2**address-1:0];

   /////////////////////////////////////////////////////////
   //procedural assignment
   /////////////////////////////////////////////////////////

   initial begin
      $readmemh("coef.mem",mem);
   end
    
   /////////////////////////////////////////////////////////
   //always block
   /////////////////////////////////////////////////////////

    always @(*) begin
       if (we_in==1) begin
          mem[address_in]=data_in;
       end 
       else begin
          instruction_out = mem[address_in];
       end
         
    end
endmodule
