`timescale 1ns/1ps
`include "half_adder.v"

module full_adder (
    inp_a,inp_b,inp_cin,out_sum,out_carry
);

input  inp_a,inp_b,inp_cin;
output  out_sum,out_carry;
wire sum_1,carry_1,carry_2;

half_adder h1(inp_a,inp_b,sum_1,carry_1);
half_adder h2(inp_cin,carry_1,out_sum,carry_2);
or h3(out_carry,carry_1,carry_2);

    
endmodule