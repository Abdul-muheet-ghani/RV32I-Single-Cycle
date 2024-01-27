//////////////////////////////////////////////////////////////////////////////////
// Company: MERL-UITU
// Engineer: Abdul Muheet Ghani
// 
// Design Name: RV32IMACZicsr for Linux
// Module Name: top_tb
// Project Name: RV32IMACZicsr for linux
// Target Devices: 
// Description: 
// 
//////////////////////////////////////////////////////////////////////////////////
`timescale 1ns/1ns

module top_tb;

    /////////////////////////////////////////////////////////
    //ports
    /////////////////////////////////////////////////////////

    reg         clk=1,we,reset;
    reg  [31:0] data_in;
    wire [31:0] d1,d2;
    wire [14:0] data_out;

    /////////////////////////////////////////////////////////
    //Module Instantiation
    /////////////////////////////////////////////////////////

    RV32I_top RV32I_i(.clk                (clk),
                      .we                 (we),
                      .reset              (reset),
                      .data_in            (data_in),
                      .control_unit_out   (data_out)
    );

    /////////////////////////////////////////////////////////
    //always block
    /////////////////////////////////////////////////////////

    always begin
        #5;
        clk = ~clk;
        reset = 0;
    end
    
    /////////////////////////////////////////////////////////
    //procedural assignment
    /////////////////////////////////////////////////////////

    initial begin
        $dumpfile("fetch.vcd");
        $dumpvars(0,top_tb);
        we = 1;
        #10;
        we = 0;
        #1000;
        $finish();
    end
    
endmodule