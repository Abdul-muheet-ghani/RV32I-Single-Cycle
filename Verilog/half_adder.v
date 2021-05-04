`timescale 1ns/1ps
module half_adder (
    a,b,sum,carry
);

  input wire a,b;
  output wire sum,carry;

  xor x1(sum,a,b);
  and x2(carry,a,b);
    
endmodule