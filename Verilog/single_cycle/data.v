module data_mem (
    clk,addr,d,str,ld,resu
 );

 input clk,str,ld;
 input [31:0]addr,d;
 output reg[31:0] resu;
 reg [31:0] data_rom[2^32-1:0];

 always @(*) begin
    if (str == 1) begin
       data_rom[addr] <= d;
    end
    if (ld == 1) begin
      resu = data_rom[addr];
   end
 end
 

    
endmodule
