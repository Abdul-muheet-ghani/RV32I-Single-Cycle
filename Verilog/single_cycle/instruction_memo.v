module ram #(
   parameter address = 12, size = 32
 ) (
    clk,addre,din,dout,we
 );
    input clk,we;
    input [31:0]din;
    input [11:0]addre;
    output reg [31:0]dout ;

    reg [31:0] mem[2**address-1:0] ;

    initial begin
        $readmemh("coef.mem",mem);
    end
    
    always @(*) begin
       if (we==1) begin
          mem[addre]=din;
       end 
       else begin
          dout = mem[addre];
       end
         
    end
endmodule
