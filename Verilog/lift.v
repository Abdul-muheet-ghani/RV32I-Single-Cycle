
`timescale 1ns/1ns
module elevator (
    input clk, input [3:0]floor, output [3:0]y
);

reg [3:0] cf = 4'd1 ;
reg clk2=0;
integer i;

always @(posedge clk) begin
    for begin
        #1; clk2 = ~clk2;
    end
end

always @(posedge clk2 ) begin
    if (floor<cf) begin
        if (cf==4'd1) begin
            cf = 4'd1 ;
        end
        else begin
            cf = cf >> 1;
        end
    end
    else if (floor > cf) begin
        cf = cf << 1;
    end
    else if (floor == cf)begin
        cf = floor;
    end
    
 end
assign y = cf;
    
endmodule
