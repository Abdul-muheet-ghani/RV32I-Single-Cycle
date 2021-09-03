module ram (
    clk,addr,data_in,data_out
 );

 input clk;
 input [31:0]addr,data_in;
 output wire[31:0] data_out;
 reg [31:0] mem[1024-1:0];


   always @* begin
     mem[addr]=data_in;
   end
  assign data_out=mem[addr];
    
endmodule
