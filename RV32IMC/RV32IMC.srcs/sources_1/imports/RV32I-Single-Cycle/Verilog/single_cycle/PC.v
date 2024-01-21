module adder (clk,adr,a,we);


 input we,clk;
 input [31:0]adr;
 output [31:0]a;

  assign a = (we) ? 0 : adr + 4;
    
endmodule