module CSR #(
    parameter XLEN = 32;
)
(
    input wire clk,
    input wire reset,

    // Interrupts
    input wire i_external_int, //interrupt from external source
    input wire i_software_int, //interrupt from software (inter-processor interrupt)
    input wire i_timer_int, //interrupt from timer

    /// Exceptions ///
    input wire i_is_inst_illegal, //illegal instruction
    input wire i_is_ecall, //ecall instruction
    input wire i_is_ebreak, //ebreak instruction
    input wire i_is_mret, //mret (return from trap) instruction

    /// Instruction/Load/Store Misaligned Exception///
    input wire[`OPCODE_WIDTH-1:0] i_opcode, //opcode types
    input wire[XLEN-1:0]          i_y, //y value from ALU (address used in load/store/jump/branch)

    /// CSR instruction ///
    input wire[2:0]      i_funct3, // CSR instruction operation
    input wire[11:0]     i_csr_index, // immediate value from decoder
    input wire[XLEN-1:0] i_imm, //unsigned immediate for immediate type of CSR instruction (new value to be stored to CSR)
    input wire[XLEN-1:0] i_rs1, //Source register 1 value (new value to be stored to CSR)
    output reg[XLEN-1:0] o_csr_out, //CSR value to be loaded to basereg

    // Trap-Handler 
    input  wire[XLEN-1:0] i_pc, //Program Counter 
    input  wire           writeback_change_pc, //high if writeback will issue change_pc (which will override this stage)
    output reg[XLEN-1:0]  o_return_address, //mepc CSR
    output reg[XLEN-1:0]  o_trap_address, //mtvec CSR
    output reg            o_go_to_trap_q, //high before going to trap (if exception/interrupt detected)
    output reg            o_return_from_trap_q, //high before returning from trap (via mret)
    input  wire           i_minstret_inc //increment minstret after executing an instruction
);

               //CSR operation type
    localparam CSRRW = 3'b001,
               CSRRS = 3'b010,
               CSRRC = 3'b011,
               CSRRWI = 3'b101,
               CSRRSI = 3'b110,
               CSRRCI = 3'b111;
               
               //CSR addresses
               //machine info
    localparam MVENDORID = 12'hF11,  
               MARCHID = 12'hF12,
               MIMPID = 12'hF13,
               MHARTID = 12'hF14,
               //machine trap setup
               MSTATUS = 12'h300, 
               MISA = 12'h301,
               MIE = 12'h304,
               MTVEC = 12'h305,
               //machine trap handling
               MSCRATCH = 12'h340, 
               MEPC = 12'h341,
               MCAUSE = 12'h342,
               MTVAL = 12'h343,
               MIP = 12'h344,
               //machine counters/timers
               MCYCLE = 12'hB00,
               MCYCLEH = 12'hB80,
               //TIME = 12'hC01,
               //TIMEH = 12'hC81,
               MINSTRET = 12'hB02,
               MINSTRETH = 12'hBB2,
               MCOUNTINHIBIT = 12'h320;
                
               //mcause codes
    localparam MACHINE_SOFTWARE_INTERRUPT =3,
               MACHINE_TIMER_INTERRUPT = 7,
               MACHINE_EXTERNAL_INTERRUPT = 11,
               INSTRUCTION_ADDRESS_MISALIGNED = 0,
               ILLEGAL_INSTRUCTION = 2,
               EBREAK = 3,
               LOAD_ADDRESS_MISALIGNED = 4,
               STORE_ADDRESS_MISALIGNED = 6,
               ECALL = 11;

    //Machine mode info reg
    //read-only register
    reg [XLEN-1:0] mvendorid;
    reg [XLEN-1:0] marchid;
    reg [XLEN-1:0] mipid;
    reg [XLEN-1:0] mhartid;

    //Trap Setup
    //Read-Write register
    reg [XLEN-1:0] mstatus;
    reg [XLEN-1:0] misa;
    reg [XLEN-1:0] mie;
    reg [XLEN-1:0] mtvec;

    //Trap handling
    //Read write register
    reg [XLEN-1:0] mscratch;
    reg [XLEN-1:0] mepc;
    reg [XLEN-1:0] mcause;
    reg [XLEN-1:0] mtval;
    reg [XLEN-1:0] mip;

    //counter/timer register
    //Read write register
    reg [XLEN-1:0] mcycle;
    reg [XLEN-1:0] mcycleh;

    //instruction retired
    //read write register
    reg [XLEN-1:0] minstret;
    reg [XLEN-1:0] minstreth;
    reg [XLEN-1:0] mcountinhibit;

    always @(posedge clk or negedge reset)
    begin
        if(reset)
        begin
            mvendorid <= '0;
            marchid   <= '0;
            mipid     <= '0;
            mhartid   <= '0;

            mstatus   <= '0;
            misa      <= '0;
            mie       <= '0;
            mstatus   <= '0;

            mscratch  <= '0;
            mepc      <= '0;
            mcause    <= '0;
            mtval     <= '0;
            mip       <= '0;

            mcycle    <= '0;
            mcycleh   <= '0;
            minstret  <= '0;
            minstreth <= '0;
            mcountinhibit <= '0;
        end
        else begin
            case(i_csr_index)
                
            endcase
        end
    end
