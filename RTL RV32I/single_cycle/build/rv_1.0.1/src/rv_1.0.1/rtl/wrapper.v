module wrapper(clk,reset);

input clk;
input reset;

wire i_wen;
wire i_ren;
wire [11:0]i_instruction;
wire [11:0]i_data;
wire [31:0]i_ram_data;
wire [31:0]o_dram;
wire [31:0]o_iram;
/* verilator lint_off UNOPTFLAT */wire [31:0]o_data;
wire [31:0]o_ar_data;
wire  [12:0]arbiter_addres;
wire  [31:0]o_ram_data;
wire  [31:0]o_rom_data;
wire  [31:0]o_rs2;
wire  st;

top top_core(
    .clk(clk),
    .reset(reset),
    .o_pc(i_instruction),
    .o_alu(i_data),
    .o_opb(i_ram_data),
    .o_ld(i_wen),
    .o_sw(i_ren),
    .i_wb(o_ram_data),
    .i_instr(o_rom_data)
    `ifdef RISCV_FORMAL
    .rvfi_valid(),
    .rvfi_order(),
    .rvfi_insn (),
    .rvfi_trap (),
    .rvfi_halt (),
    .rvfi_intr (),
    .rvfi_mode (),
    .rvfi_ixl  (),
    .rvfi_rs1_addr(),
    .rvfi_rs2_addr(),
    .rvfi_rs1_rdata(),
    .rvfi_rs2_rdata(),
    .rvfi_rd_addr(),
    
    .rvfi_rd_wdata(),
    .rvfi_pc_rdata(),
    .rvfi_pc_wdata(),
    .rvfi_mem_addr(),
    .rvfi_mem_rmask(),
    .rvfi_mem_wmask(),
    .rvfi_mem_rdata(),
    .rvfi_mem_wdata()
    `endif 
 );

 wire cl = clk;

 arbiter arbiter(
    .clk(cl),
    .i_ld(i_wen),
    .i_str(i_ren),

    .i_ins_addr(i_instruction),
    .i_data_addr(i_data),
    .o_addr(arbiter_addres),

    .i_data(o_data),
    .o_ram_data(o_ram_data),
    .o_rom_data(o_rom_data),

    .i_opb(i_ram_data),
    .o_opb(o_rs2),

    .write(st)
 );
 
ram ram(
   .i_addre(arbiter_addres),
   .i_data(o_rs2),
   .i_wr(st),
   .o_data(o_data)   
); 


endmodule
