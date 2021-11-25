module ram  (
    input [12:0] i_addre,
    input [31:0] i_data,
    input        i_wr,
    output wire [31:0] o_data
 );

 reg en = 0; 

    reg [31:0] mem[2**13-1:0] ;

    initial begin
        $readmemh("/home/muheet-ghani/olof/fusesoc_libraries/single_cycle/rtl/coef.mem",mem);
    end
    
    always @(*) begin
          if (i_wr) begin
             mem[i_addre] = i_data;
          end
    end
   assign  o_data = mem[i_addre];
endmodule
