module reg_file (
   rs1,rs2,rd,inp,ou1,ou2,clk,reset
 );

 input clk,reset;
 input [4:0]rs1,rs2,rd;
 input [31:0]inp;
 output wire [31:0]ou1,ou2;
 integer i;
 
 reg [31:0] reg_file1[31:0];

 always @(posedge clk ) begin
    if (reset == 1) begin
      for (i = 0 ; i<=31 ; i++) begin
         reg_file1[i]=0;
      end 
    end else begin
      reg_file1[rd] = inp;
    end
    
 end
    assign ou1 = (rs1 != 0) ? reg_file1[rs1] : 0;
    assign ou2 = (rs2 != 0) ? reg_file1[rs2] : 0;

endmodule