//////////////////////////////////////////////////////////////////////////////////
// Company: MERL-UITU
// Engineer: Abdul Muheet Ghani
// 
// Design Name: RV32IMACZicsr for Linux
// Module Name: RV32-pkg
// Project Name: RV32IMACZicsr for linux
// Target Devices: 
// Description: 
// 
//////////////////////////////////////////////////////////////////////////////////

`define OPCODE_RTYPE  7'b0110011 
`define OPCODE_ITYPE  7'b0010011
`define OPCODE_LOAD   7'b0000011
`define OPCODE_STORE  7'b0100011
`define OPCODE_BRANCH 7'b1100011
`define OPCODE_JAL    7'b1101111
`define OPCODE_JALR   7'b1100111
`define OPCODE_LUI    7'b0110111
`define OPCODE_AUIPC  7'b0010111
`define OPCODE_SYSTEM 7'b1110011

`define ALU_OP_ADD  4'b0000
`define ALU_OP_SUB  4'b0001
`define ALU_OP_AND  4'b0010
`define ALU_OP_OR   4'b0011
`define ALU_OP_XOR  4'b0100
`define ALU_OP_SLL  4'b0101
`define ALU_OP_SRL  4'b0110
`define ALU_OP_SLTU 4'b0111
`define ALU_OP_SLT  4'b1000
`define ALU_OP_SRA  4'b1001
`define ALU_OP      4'b1111

`define FUNCT3_BEQ 3'b000
`define FUNCT3_BNEQ 3'b001
`define FUNCT3_BLT 3'b100
`define FUNCT3_BGE 3'b101
`define FUNCT3_BLTU 3'b110
`define FUNCT3_BGEU 3'b111 

`define FUNCT3_ADD  3'b000
`define FUNCT3_SLT  3'b010 
`define FUNCT3_SLTU 3'b011
`define FUNCT3_XOR  3'b100
`define FUNCT3_OR   3'b110
`define FUNCT3_AND  3'b111
`define FUNCT3_SLL  3'b001
`define FUNCT3_SRA  3'b101

//CSR addresses
//machine info
`define MVENDORID   12'hF11  
`define MARCHID     12'hF12
`define MIMPID  12'hF13
`define MHARTID     12'hF14

//machine trap setup
`define MSTATUS     12'h300 
`define MISA    12'h301
`define MIE     12'h304
`define MTVEC   12'h305

//machine trap handling
`define MSCRATCH    12'h340
`define MEPC    12'h341
`define MCAUSE      12'h342
`define MTVAL   12'h343
`define MIP     12'h344

//machine counters/timers
`define MCYCLE 12'hB00
`define MCYCLEH 12'hB80
//TIME = 12'hC01,
//TIMEH = 12'hC81,
`define MINSTRET 12'hB02
`define MINSTRETH 12'hBB2
`define MCOUNTINHIBIT 12'h320

`define CSRRW   3'b001
`define CSRRS   3'b010
`define CSRRC   3'b011
`define CSRRWI  3'b101
`define CSRRSI  3'b110
`define CSRRCI  3'b111

//Volume II table 3.6
`define MACHINE_SOFTWARE_INTERRUPT      3
`define MACHINE_TIMER_INTERRUPT         7
`define MACHINE_EXTERNAL_INTERRUPT      11
`define INSTRUCTION_ADDRESS_MISALIGNED      0
`define ILLEGAL_INSTRUCTION         2
`define EBREAK      3
`define LOAD_ADDRESS_MISALIGNED         4
`define STORE_ADDRESS_MISALIGNED        6
`define ECALL       11
