`timescale 1ns/1ns
module Soc_core_tb;

reg        clk=1;
reg        reset;


Soc_core m0(.clk(clk),
            .reset(reset));

always  begin
    #5; clk = ~clk;
end

initial begin
    $dumpfile("Soc_core.vcd");
    $dumpvars(0,Soc_core_tb);
    reset=1;                  //processor
    #10;
    reset=0; 

end

endmodule
