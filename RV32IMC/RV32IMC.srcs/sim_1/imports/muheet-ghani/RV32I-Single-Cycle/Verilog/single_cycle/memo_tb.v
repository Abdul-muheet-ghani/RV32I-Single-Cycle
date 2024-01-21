`timescale 1ns/1ns
//`include "memo.v"

module memo_tb;

reg clk=1,we,reset;
reg [31:0]data_in;
wire [31:0]d1,d2;
wire [14:0]data_out;


as m(clk,data_in,data_out,we,reset);

always begin
    #5;
    clk = ~clk;
    reset = 0;
end
    

initial begin
    $dumpfile("fetch.vcd");
    $dumpvars(0,memo_tb);
    we = 1;
    #10;
    /*
    data_in = 32'h00200113;    #10;
    
    data_in = 32'h00300193;     #10;

    data_in = 32'h00310233 ;    #10;
    
    data_in = 32'h40218233;     #10;

    data_in = 32'h00001697;     #10;

    data_in = 32'h00001737;     #10;
//
    data_in = 32'h003172B3;    #10;
    
    data_in = 32'h00117293;     #10;

    data_in = 32'h00316333 ;    #10;
    
    data_in = 32'h00116313;     #10;

    data_in = 32'h003143B3;     #10;

    data_in = 32'h00114393;     #10;
//
    data_in = 32'h00311433;     #10;

    data_in = 32'h00111413;     #10;

    data_in = 32'h003154B3;     #10;*/
    we = 0;
    #1000;
    $finish();
end
    
endmodule

/*

00200113  addi x2,x0,2
00300193  addi x3,x0,3
00310233  add x4,x2,x3
40218233  sub x4,x3,x2
00001697  auipc x13,1
00001737  lui x14,1

003172B3  and x5,x2,x3
00117293  andi x5,x2,1
00316333  or x6,x2,x3
00116313  ori x6,x2,1
003143B3  xor x7,x2,x3
00114393  xori x7,x2,1

00311433  sll x8,x2,x3
00111413  slli x8,x2,1
003154B3  srl x9,x2,x3

004000EF  jal up
00628A63  beq x5,x6,label
00115493  srli x9,x2,1
00312533  slt x10,x2,x3
00112513  slti x10,x2,1
003135B3  sltu x11,x2,x3
00113593  sltiu x11,x2,1
40315633  sra x12,x2,x3
40115613  srai x12,x2,1
06400167  jalr x2,x0,0x64
00422023  sw x4,0x0(x4)
00022203  lw x4,0x0(x4)

*/
