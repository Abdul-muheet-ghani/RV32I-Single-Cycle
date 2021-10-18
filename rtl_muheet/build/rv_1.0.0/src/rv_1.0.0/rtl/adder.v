module adder (adr,a);


 reg [31:0]c=0;
 input [31:0]adr;
 output reg [31:0]a;

  always @(*) begin
     a = adr + 4;
  end
    
endmodule