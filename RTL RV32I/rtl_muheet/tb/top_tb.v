`timescale 1ns/1ns
module top_tb;

reg        clk=1;
reg        we;
reg        reset;
reg        [31:0]din ;
wire       [14:0]dout ;

top m0(clk,din,dout,we,reset);

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
