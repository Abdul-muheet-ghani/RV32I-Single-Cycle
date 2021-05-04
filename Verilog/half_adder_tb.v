`timescale 1ns/1ps
`include "half_adder.v"

module half_adder_tb ;
   initial begin
       $dumpfile("test.vcd");
       $dumpvars(0,half_adder_tb);
   end

   reg A,B;
   wire SUM,COUNT;

   half_adder adder(
       A,B,SUM,COUNT
   );

   initial begin
      A=1'b0;
      B=1'b0;
      #5;

      A=1'b1;
      B=1'b0;
      #5;

      A=1'b0;
      B=1'b1;
      #5;

      A=1'b1;
      B=1'b1;
      #5;
      $finish; 
   end
endmodule