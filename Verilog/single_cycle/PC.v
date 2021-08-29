module adder (clk,a);


 reg [31:0]c=0;
 output reg [31:0]a;
 input clk;

    always @(posedge clk ) begin
       a <= c;
    end

    always @* begin
       c <= a+4;
    end
endmodule
