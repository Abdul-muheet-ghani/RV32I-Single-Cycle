//////////////////////////////////////////////////////////////////////////////////
// Company: MERL-UITU
// Engineer: Abdul Muheet Ghani
// 
// Design Name: RV32IMACZicsr for Linux
// Module Name: Data Memory
// Project Name: RV32IMACZicsr for linux
// Target Devices: 
// Description: 
// 
//////////////////////////////////////////////////////////////////////////////////

module data_mem (
    input             clk_in,
    input             store_en_in,
    input             load_en_in,
    input      [31:0] address_in,
    input      [31:0] store_data_in,
    output reg [31:0] data_out
 );

 reg [11:0]ad1 ;
 reg [31:0] data_ram[1024-1:0];
   
 always @(clk_in) begin
    if (store_en_in) begin
       data_ram[address_in] <= store_data_in;
    end
    if (load_en_in) begin
      data_out = data_ram[address_in];
   end
 end

endmodule
