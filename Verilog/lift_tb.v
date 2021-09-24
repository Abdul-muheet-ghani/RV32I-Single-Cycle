
`timescale 1ns/1ns
`include "lift.v"

module elevator_tb;

reg clk=1;
reg [3:0]floor;
wire [3:0]y;

elevator m0(clk,floor,y);

always  begin
    #4; clk = ~clk;
end

initial begin
    $dumpfile("lift.vcd");
    $dumpvars(0,elevator_tb);

    floor = 4'b0000; #8;
    floor = 4'b1000; #8;
    floor = 4'b0111; #8;
    floor = 4'b0100; #8;  

end
    
endmodule
