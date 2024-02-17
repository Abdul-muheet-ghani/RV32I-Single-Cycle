//////////////////////////////////////////////////////////////////////////////////
// Company: MERL-UITU
// Engineer: Abdul Muheet Ghani
// 
// Design Name: RV32IMACZicsr for Linux
// Module Name: M-CSR
// Project Name: RV32IMACZicsr for linux
// Target Devices: 
// Description: 
// 
//////////////////////////////////////////////////////////////////////////////////

`include "RV32_pkg.vh"

module CSR #(
    parameter XLEN = 32
)
(
    input wire clk,
    input wire reset,

    // Interrupts
    input wire external_int_in, //interrupt from external source
    input wire software_int_in, //interrupt from software (inter-processor interrupt)
    input wire timer_int_in,    //interrupt from timer

    /// Exceptions ///
    input wire illegal_instruction_in, //illegal instruction
    input wire ecall_in,               //ecall instruction
    input wire ebreak_in,              //ebreak instruction
    input wire mret_in,                //mret (return from trap) instruction

    /// Instruction/Load/Store Misaligned Exception///
    input wire[6:0] opcode_in, //opcode types from type decoder
    //input wire[XLEN-1:0]          alu_out, //y value from ALU (address used in load/store/jump/branch)

    /// CSR instruction ///
    input wire[2:0]      funct3_in, // CSR instruction operation
    input wire[11:0]     instruction_in, // 12 MSB for CSR index Table 2.5: Currently allocated RISC-V machine-level CSR addresses Volume II
    input wire[XLEN-1:0] csr_immediate_in, //unsigned immediate for immediate type of CSR instruction (new value to be stored to CSR)
    input wire[XLEN-1:0] rs1_in, //Source register 1 value (new value to be stored to CSR)
    output reg[XLEN-1:0] csr_data_out, //CSR value to be loaded to basereg

    // Trap-Handler 
    input  wire[XLEN-1:0] pc_in, //Program Counter 
    output reg[XLEN-1:0]  return_address_out, //mepc CSR
    output reg[XLEN-1:0]  trap_address_out, //mtvec CSR
    output reg            trap_true_out, //high before going to trap (if exception/interrupt detected)
    output reg            return_trap_out, //high before returning from trap (via mret)
    input  wire           minstret_inc_in //increment minstret after executing an instruction
);


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

    wire csr_en;
    reg external_interrut_pending;
    reg timer_interrut_pending;
    reg software_interrut_pending;
    reg is_interrupt,is_exception;

    assign csr_en = (opcode_in == `OPCODE_SYSTEM) && (funct3_in != 3'b0);

    always @(posedge clk or negedge reset)
    begin
        if(reset)
        begin
            mvendorid <= 'b0;
            marchid   <= 'b0;
            mipid     <= 'b0;
            mhartid   <= 'b0;

            mstatus   <= 'b0;
            misa      <= 'b0;
            mie       <= 'b0;
            mtvec     <= 'b0;
            mstatus   <= 'b0;

            mscratch  <= 'b0;
            mepc      <= 'b0;
            mcause    <= 'b0;
            mtval     <= 'b0;
            mip       <= 'b0;

            mcycle    <= 'b0;
            mcycleh   <= 'b0;
            minstret  <= 'b0;
            minstreth <= 'b0;
            mcountinhibit <= 'b0;
        end
        else begin
            if(csr_en)
            begin
                if(instruction_in == `MSTATUS)
                begin
                    mstatus <= csr_data_out;
                end
                else begin
                    /*When a trap is taken from privilege mode y into privilege mode x,xPIE is set to the value of x IE;
                    x IE is set to 0; and xPP is set to y.*/
                    // Volume II pg.21
                    if(trap_true_out)
                    begin
                        mstatus[3] <= 1'b0; // mie bit, for not allowed to nested
                        mstatus[7] <= mstatus[3]; // mpie 
                        mstatus[12:11] <= 2'b11; //MPP, machine previous privilage value stored.
                    end
                    //MRET When executing an xRET instruction, supposing xPP holds the value y, xIE is set to xPIE;
                    //xPIE is set to 1;
                    //Volume II pg.21
                    else if(return_trap_out)
                    begin
                        mstatus[3] <= mstatus[7]; // mie bit, for not allowed to nested
                        mstatus[7] <= 1'b1; // mpie 
                        mstatus[12:11] <= 2'b11; //MPP, machine previous privilage value stored.
                    end
                end

                if(instruction_in == `MIE)begin
                    mie <= csr_data_out;
                end

                if(instruction_in == `MTVEC)
                begin
                    mtvec <= csr_data_out;
                end

                if(instruction_in == `MSCRATCH)
                begin
                    mscratch <= csr_data_out;
                end

                if(instruction_in == `MEPC)
                begin
                    mepc <= {csr_data_out[31:2],2'b0};
                end

                if(instruction_in == `MCAUSE)
                begin
                    mcause <= csr_data_out;
                end

                if(instruction_in == `MTVAL)
                begin
                    mtval <= csr_data_out;
                end

                if(instruction_in == `MCYCLE)
                begin
                    mcycle <= csr_data_out;
                end

                if(instruction_in == `MCYCLEH)
                begin
                    mcycleh <= csr_data_out;
                end

                if(instruction_in == `MINSTRET)
                begin
                    minstret <= csr_data_out;
                end

                if(instruction_in == `MINSTRETH)
                begin
                    minstreth <= csr_data_out;
                end

                if(instruction_in == `MCOUNTINHIBIT)
                begin
                    mcountinhibit <= csr_data_out;
                end

                if(trap_true_out) begin
                    mepc <= pc_in;
                end

                //mcause[3:0] = code, mcause[31] = intbit. 
                //Volume II pg.38. Interrupts priority first then synchronous traps
                if(trap_true_out)
                begin
                    if(external_int_in) begin
                        mcause[3:0] <= `MACHINE_EXTERNAL_INTERRUPT;
                        mcause[31]  <= 1'b1;
                    end
                    else if(software_int_in) begin
                        mcause[3:0] <= `MACHINE_SOFTWARE_INTERRUPT;
                        mcause[31]  <= 1'b1;
                    end
                    else if(timer_int_in) begin
                        mcause[3:0] <= `MACHINE_TIMER_INTERRUPT;
                        mcause[31]  <= 1'b1;
                    end
                    else if(illegal_instruction_in) begin
                        mcause[3:0] <= `ILLEGAL_INSTRUCTION;
                        mcause[31]  <= 1'b0;
                    end
                    else if(ecall_in) begin
                        mcause[3:0] <= `ECALL;
                        mcause[31]  <= 1'b0;
                    end
                    else if(ebreak_in) begin
                        mcause[3:0] <= `EBREAK;
                        mcause[31]  <= 1'b0;
                    end
                end

                mcycle <= mcountinhibit[0] ? mcycle : mcycle + 1;

                mip[3] <= software_int_in;
                mip[7] <= timer_int_in;
                mip[11]<= external_int_in;

                return_address_out <= mepc;

                /* Volume 2 pg. 30: When MODE=Direct (0), all traps into machine mode cause the i_pc to be set to the address in the  
                 BASE field. When MODE=Vectored (1), all synchronous exceptions into machine mode cause the i_pc to be set to the address 
                 in the BASE field, whereas interrupts cause the i_pc to be set to the address in the BASE field plus four times the
                 interrupt cause number */
                 if(mtvec[1] && is_interrupt) trap_address_out <= {mtvec,2'b00} + {28'b0,mcause<<2};
                 else trap_address_out <= {mtvec,2'b00};
            end
        end
    end
    

    always @(*)
    begin
        external_interrut_pending   = mstatus[3] && mie[11] && mip[11];
        timer_interrut_pending      = mstatus[3] && mie[7]  && mip[7];
        software_interrut_pending   = mstatus[3] && mie[3]  && mip[3];

        is_interrupt = external_interrut_pending || timer_interrut_pending || software_interrut_pending;
        is_exception = ecall_in || ebreak_in || illegal_instruction_in;

        trap_true_out = is_interrupt || is_exception;
        return_trap_out = mret_in;
    end

    always @(*)
    begin
        if(csr_en)
        begin
            case(instruction_in)
                `MVENDORID  : csr_data_out = mvendorid;
                `MARCHID    : csr_data_out = marchid;
                `MIMPID     : csr_data_out = mipid;
                `MHARTID    : csr_data_out = mhartid;

                `MSTATUS    : csr_data_out = mstatus; 
                `MISA       : csr_data_out = misa;
                `MIE        : csr_data_out = mie;
                `MTVEC      : csr_data_out = mstatus;
                
                `MSCRATCH   : csr_data_out = mscratch;   
                `MEPC       : csr_data_out = mepc;  
                `MCAUSE     : csr_data_out = mcause;  
                `MTVAL      : csr_data_out = mtval;  
                `MIP        : csr_data_out = mip;  
                
                `MCYCLE     : csr_data_out = mcycle;
                `MCYCLEH    : csr_data_out = mcycleh;
                `MINSTRET   : csr_data_out = minstret;
                `MINSTRETH  : csr_data_out = minstreth;
                `MCOUNTINHIBIT : csr_data_out = mcountinhibit;
            endcase

            case(funct3_in)
                `CSRRW  : csr_data_out = rs1_in;  //Read and Write.
                `CSRRS  : csr_data_out = csr_data_out | rs1_in;
                `CSRRC  : csr_data_out = csr_data_out & (~rs1_in);
                `CSRRWI : csr_data_out = csr_immediate_in;
                `CSRRSI : csr_data_out = csr_data_out | csr_immediate_in;
                `CSRRCI : csr_data_out = csr_data_out | (~csr_immediate_in);
            endcase
        end
    end
endmodule