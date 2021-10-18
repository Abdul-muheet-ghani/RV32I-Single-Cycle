module ram #(
   parameter address = 12, size = 32
 ) (
    addre,din,dout,we
 );
    input we;
    input [31:0]din;
    input [11:0]addre;
    output reg [31:0]dout ;

    reg [31:0] mem[2**address-1:0] ;

    initial begin
        $readmemh("/home/muheet-ghani/olof/fusesoc_libraries/rtl_muheet/rtl/coef.mem",mem);
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