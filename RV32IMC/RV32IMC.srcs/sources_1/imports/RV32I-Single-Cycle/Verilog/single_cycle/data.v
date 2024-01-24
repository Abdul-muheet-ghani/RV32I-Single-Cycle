module data_mem (
    clk_in,address_in,store_data_in,store_en_in,load_en_in,data_out
 );

 input clk_in,store_en_in,load_en_in;
 input [31:0]address_in,store_data_in;
 output reg [31:0] data_out;
 reg [11:0]ad1 ;
 reg [31:0] data_rom[1024-1:0];
   
 always @(clk_in) begin
    if (store_en_in) begin
       data_rom[address_in] <= store_data_in;
    end
    if (load_en_in) begin
      data_out = data_rom[address_in];
   end
 end

endmodule
