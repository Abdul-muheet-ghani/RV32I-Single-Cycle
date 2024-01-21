`include "data_ram.v"
`include "instruction_ram.v"

module ram_top (
   clk,
   reset,
   i_pc,
   i_alu,
   i_opb,
   i_ld,
   i_sw,
   o_wb,
   o_instr
);
   input clk;
   input reset;
   input i_ld;
   input i_sw;
   input [11:0]i_alu;
   input [31:0]i_opb;
   output [31:0]o_wb;
   //instruction 
   inout [11:0]i_pc;
   output [31:0]o_instr;

   data_ram data_memory(
      .clk(clk),
      .addr(i_alu),
      .d(i_opb),
      .str(i_sw),
      .ld(i_ld),
      .resu(o_wb)
   );

   instruction_ram ram(
      .addre(i_pc),
      .dout(o_instr)
   );

endmodule
