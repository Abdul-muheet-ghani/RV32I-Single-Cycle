`timescale 1ns/1ns
module top_tb;

reg        clk=1;
reg        reset;

wrapper m0(clk,reset);

always  begin
    #5; clk = ~clk;
end

initial begin
    $dumpfile("asdasd788.vcd");
    $dumpvars(0,top_tb);
    reset=1;                  //processor
    #10;
    reset=0; 

end

endmodule
