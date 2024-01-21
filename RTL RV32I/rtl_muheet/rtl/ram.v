module ram  (
    input [12:0] i_addre,
    input [31:0] i_data,
    input        i_wr,
    output wire [31:0] o_data
 );
 
 parameter memfile = "/home/muheet-ghani/olof/riscv-compliance/work/rv32i/I-ADD-01.elf.hex";

 reg en = 0; 

    reg [31:0] mem[2**13-1:0] ;

    initial
     if(|memfile) begin
`ifndef ISE
	$display("Preloading %m from %s", memfile);
`endif
	$readmemh(memfile, mem);
     end
    
    always @(*) begin
          if (i_wr) begin
             mem[i_addre] = i_data;
          end
    end
   assign  o_data = mem[i_addre];
endmodule
