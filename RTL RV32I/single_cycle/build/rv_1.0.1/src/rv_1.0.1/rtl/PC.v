module PC (
   in,out,clk,we
);

 input clk,we;
 input logic [31:0] in;
 output logic [31:0] out;

 always @(posedge clk) begin
   if (we==1) begin
      out <= 0;
   end else begin
      out <= in;
   end
end   
endmodule