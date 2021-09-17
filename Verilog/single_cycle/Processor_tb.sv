`timescale 1ns/1ns
`include "memo.sv"

module read_tb;

reg clk=1,we;
reg [31:0]din ;
reg [31:0]addre ;
wire [14:0]dout ;

/*
reg clk=1,we;
reg [31:0]din1,din ;
reg [31:0]addre ;
wire [31:0]dout ;
*/
as m0(clk,din,dout,we);
//ram m0(clk,din1,din,dout,we);

always  begin
    #5; clk = ~clk;
end

initial begin
    $dumpfile("asdasd788.vcd");
    $dumpvars(0,read_tb);
    we=1;                  //processor
    #10;
    we=0; #10;

/*
    we=1;                     //ram
    #10;
    we=0; din1 = 0; #10;
    we=0; din1 = 4; #10;
    we=0; din1 = 8; #10;
    we=0; din1 = 0; #10;
*/
end

endmodule
