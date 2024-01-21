module data_mem (
    clk,addr,d,str,ld,resu
 );

 input clk,str,ld;
 input [31:0]d;
 input [12:0]addr;
 output logic [31:0] resu;
 reg [11:0]ad1 ;
 logic [31:0] data_rom[8192-1:0];
   
 always @(clk) begin
    if (str) begin
       data_rom[addr] = d;
    end
    if (ld) begin
      resu = data_rom[addr];
   end
 end

endmodule
