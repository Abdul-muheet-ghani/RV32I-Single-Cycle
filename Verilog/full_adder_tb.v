`timescale 1ns/1ps
`include "full_adder.v"

module full_adder_tb;
  initial begin
      $dumpfile("full_adder_test.vcd");
      $dumpvars(0,full_adder_tb);
  end
    
  reg A,B,C;
  wire SUM,CARRY;

  full_adder h1(
      .inp_a(A),
      .inp_b(B),
      .inp_cin(C),
      .out_sum(SUM),
      .out_carry(CARRY)
      );

      initial begin
          A=1'b0;
          B=1'b0;
          C=1'b0;
          #5;

          A=1'b1;
          B=1'b0;
          C=1'b0;
          #5;

          A=1'b0;
          B=1'b1;
          C=1'b0;
          #5;

          A=1'b1;
          B=1'b1;
          C=1'b0;
          #5;

          A=1'b0;
          B=1'b0;
          C=1'b1;
          #5;

          A=1'b1;
          B=1'b0;
          C=1'b1;
          #5;

          A=1'b0;
          B=1'b1;
          C=1'b1;
          #5;

          A=1'b1;
          B=1'b1;
          C=1'b1;
          #5;
      end

endmodule