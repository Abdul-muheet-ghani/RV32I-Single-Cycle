// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vwrapper__Syms.h"


//======================

void Vwrapper::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&Vwrapper::traceInit, &Vwrapper::traceFull, &Vwrapper::traceChg, this);
}
void Vwrapper::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vwrapper* t = (Vwrapper*)userthis;
    Vwrapper__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vwrapper::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vwrapper* t = (Vwrapper*)userthis;
    Vwrapper__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void Vwrapper::traceInitThis(Vwrapper__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vwrapper* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vwrapper::traceFullThis(Vwrapper__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vwrapper* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vwrapper::traceInitThis__1(Vwrapper__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vwrapper* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+705,"clk", false,-1);
        vcdp->declBit(c+713,"reset", false,-1);
        vcdp->declBit(c+705,"wrapper clk", false,-1);
        vcdp->declBit(c+713,"wrapper reset", false,-1);
        vcdp->declBit(c+17,"wrapper i_wen", false,-1);
        vcdp->declBit(c+25,"wrapper i_ren", false,-1);
        vcdp->declBus(c+417,"wrapper i_instruction", false,-1, 11,0);
        vcdp->declBus(c+33,"wrapper i_data", false,-1, 11,0);
        vcdp->declBus(c+41,"wrapper i_ram_data", false,-1, 31,0);
        vcdp->declBus(c+729,"wrapper o_dram", false,-1, 31,0);
        vcdp->declBus(c+737,"wrapper o_iram", false,-1, 31,0);
        vcdp->declBus(c+49,"wrapper o_data", false,-1, 31,0);
        vcdp->declBus(c+745,"wrapper o_ar_data", false,-1, 31,0);
        vcdp->declBus(c+57,"wrapper arbiter_addres", false,-1, 12,0);
        vcdp->declBus(c+65,"wrapper o_ram_data", false,-1, 31,0);
        vcdp->declBus(c+73,"wrapper o_rom_data", false,-1, 31,0);
        vcdp->declBus(c+81,"wrapper o_rs2", false,-1, 31,0);
        vcdp->declBit(c+89,"wrapper st", false,-1);
        vcdp->declBit(c+705,"wrapper cl", false,-1);
        vcdp->declBit(c+705,"wrapper top_core clk", false,-1);
        vcdp->declBit(c+713,"wrapper top_core reset", false,-1);
        vcdp->declBus(c+65,"wrapper top_core i_wb", false,-1, 31,0);
        vcdp->declBus(c+73,"wrapper top_core i_instr", false,-1, 31,0);
        vcdp->declBus(c+97,"wrapper top_core data_out", false,-1, 14,0);
        vcdp->declBus(c+417,"wrapper top_core o_pc", false,-1, 11,0);
        vcdp->declBus(c+33,"wrapper top_core o_alu", false,-1, 11,0);
        vcdp->declBus(c+41,"wrapper top_core o_opb", false,-1, 31,0);
        vcdp->declBit(c+17,"wrapper top_core o_ld", false,-1);
        vcdp->declBit(c+25,"wrapper top_core o_sw", false,-1);
        vcdp->declBit(c+105,"wrapper top_core branch_p", false,-1);
        vcdp->declBus(c+113,"wrapper top_core OUT_T", false,-1, 31,0);
        vcdp->declBus(c+1,"wrapper top_core addr", false,-1, 31,0);
        vcdp->declBus(c+425,"wrapper top_core adr", false,-1, 31,0);
        vcdp->declBus(c+433,"wrapper top_core a", false,-1, 31,0);
        vcdp->declBus(c+753,"wrapper top_core b", false,-1, 31,0);
        vcdp->declBus(c+121,"wrapper top_core I", false,-1, 31,0);
        vcdp->declBus(c+129,"wrapper top_core S", false,-1, 31,0);
        vcdp->declBus(c+137,"wrapper top_core SB", false,-1, 31,0);
        vcdp->declBus(c+145,"wrapper top_core UJ", false,-1, 31,0);
        vcdp->declBus(c+153,"wrapper top_core U", false,-1, 31,0);
        vcdp->declBus(c+9,"wrapper top_core op1", false,-1, 31,0);
        vcdp->declBus(c+41,"wrapper top_core op2", false,-1, 31,0);
        vcdp->declBus(c+761,"wrapper top_core faltu", false,-1, 31,0);
        vcdp->declBus(c+161,"wrapper top_core reg_1", false,-1, 31,0);
        vcdp->declBus(c+169,"wrapper top_core reg_2", false,-1, 31,0);
        vcdp->declBus(c+177,"wrapper top_core im", false,-1, 31,0);
        vcdp->declBus(c+185,"wrapper top_core ALU_OUTPUT", false,-1, 31,0);
        vcdp->declBus(c+769,"wrapper top_core write_adder", false,-1, 31,0);
        vcdp->declBus(c+193,"wrapper top_core write_ba", false,-1, 31,0);
        vcdp->declBus(c+201,"wrapper top_core rite_ba", false,-1, 31,0);
        vcdp->declBus(c+777,"wrapper top_core rb1", false,-1, 31,0);
        vcdp->declBus(c+209,"wrapper top_core c", false,-1, 8,0);
        vcdp->declBus(c+217,"wrapper top_core r1", false,-1, 4,0);
        vcdp->declBus(c+225,"wrapper top_core r2", false,-1, 4,0);
        vcdp->declBus(c+233,"wrapper top_core rf", false,-1, 4,0);
        vcdp->declBus(c+417,"wrapper top_core after_PC", false,-1, 11,0);
        vcdp->declBus(c+785,"wrapper top_core re", false,-1, 4,0);
        vcdp->declBus(c+65,"wrapper top_core wb", false,-1, 31,0);
        vcdp->declBus(c+241,"wrapper top_core fun_3", false,-1, 2,0);
        vcdp->declBus(c+793,"wrapper top_core ac", false,-1, 31,0);
        vcdp->declBus(c+801,"wrapper top_core addr1", false,-1, 31,0);
        vcdp->declBus(c+249,"wrapper top_core opa", false,-1, 1,0);
        vcdp->declBus(c+257,"wrapper top_core next_pc", false,-1, 1,0);
        vcdp->declBus(c+265,"wrapper top_core imm_sel", false,-1, 1,0);
        vcdp->declBit(c+273,"wrapper top_core reg_write", false,-1);
        vcdp->declBit(c+17,"wrapper top_core mem_to_reg", false,-1);
        vcdp->declBit(c+25,"wrapper top_core mem_write", false,-1);
        vcdp->declBit(c+281,"wrapper top_core branch1", false,-1);
        vcdp->declBit(c+289,"wrapper top_core opb", false,-1);
        vcdp->declBit(c+297,"wrapper top_core j", false,-1);
        vcdp->declBus(c+305,"wrapper top_core alu_op", false,-1, 3,0);
        vcdp->declBus(c+801,"wrapper top_core zero", false,-1, 31,0);
        vcdp->declBus(c+801,"wrapper top_core adder c", false,-1, 31,0);
        vcdp->declBus(c+425,"wrapper top_core adder adr", false,-1, 31,0);
        vcdp->declBus(c+433,"wrapper top_core adder a", false,-1, 31,0);
        vcdp->declBit(c+705,"wrapper top_core PC clk", false,-1);
        vcdp->declBit(c+713,"wrapper top_core PC we", false,-1);
        vcdp->declBus(c+1,"wrapper top_core PC in", false,-1, 31,0);
        vcdp->declBus(c+425,"wrapper top_core PC out", false,-1, 31,0);
        vcdp->declBus(c+257,"wrapper top_core PC_mux sel", false,-1, 1,0);
        vcdp->declBus(c+433,"wrapper top_core PC_mux a", false,-1, 31,0);
        vcdp->declBus(c+145,"wrapper top_core PC_mux b", false,-1, 31,0);
        vcdp->declBus(c+113,"wrapper top_core PC_mux c", false,-1, 31,0);
        vcdp->declBus(c+313,"wrapper top_core PC_mux d", false,-1, 31,0);
        vcdp->declBus(c+1,"wrapper top_core PC_mux o", false,-1, 31,0);
        vcdp->declBus(c+73,"wrapper top_core control opcode", false,-1, 31,0);
        vcdp->declBus(c+209,"wrapper top_core control dec", false,-1, 8,0);
        vcdp->declBus(c+321,"wrapper top_core control c", false,-1, 6,0);
        vcdp->declBus(c+809,"wrapper top_core control b", false,-1, 31,7);
        vcdp->declBus(c+209,"wrapper top_core unit dec", false,-1, 8,0);
        vcdp->declBus(c+73,"wrapper top_core unit in", false,-1, 31,0);
        vcdp->declBus(c+97,"wrapper top_core unit un", false,-1, 14,0);
        vcdp->declBus(c+241,"wrapper top_core unit fun_3", false,-1, 2,0);
        vcdp->declBit(c+329,"wrapper top_core unit fun_7", false,-1);
        vcdp->declBus(c+337,"wrapper top_core unit a", false,-1, 3,0);
        vcdp->declBus(c+345,"wrapper top_core unit c", false,-1, 3,0);
        vcdp->declBus(c+353,"wrapper top_core unit b", false,-1, 2,0);
        vcdp->declBus(c+361,"wrapper top_core unit d", false,-1, 2,0);
        vcdp->declBit(c+705,"wrapper top_core reg_file clk", false,-1);
        vcdp->declBit(c+713,"wrapper top_core reg_file reset", false,-1);
        vcdp->declBus(c+217,"wrapper top_core reg_file rs1", false,-1, 4,0);
        vcdp->declBus(c+225,"wrapper top_core reg_file rs2", false,-1, 4,0);
        vcdp->declBus(c+233,"wrapper top_core reg_file rd", false,-1, 4,0);
        vcdp->declBus(c+193,"wrapper top_core reg_file inp", false,-1, 31,0);
        vcdp->declBus(c+9,"wrapper top_core reg_file ou1", false,-1, 31,0);
        vcdp->declBus(c+41,"wrapper top_core reg_file ou2", false,-1, 31,0);
        vcdp->declBus(c+441,"wrapper top_core reg_file i", false,-1, 31,0);
        {int i; for (i=0; i<32; i++) {
                vcdp->declBus(c+449+i*1,"wrapper top_core reg_file reg_file1", true,(i+0), 31,0);}}
        vcdp->declBus(c+73,"wrapper top_core immediate instruction", false,-1, 31,0);
        vcdp->declBus(c+425,"wrapper top_core immediate pc", false,-1, 31,0);
        vcdp->declBus(c+129,"wrapper top_core immediate S", false,-1, 31,0);
        vcdp->declBus(c+137,"wrapper top_core immediate SB", false,-1, 31,0);
        vcdp->declBus(c+145,"wrapper top_core immediate UJ", false,-1, 31,0);
        vcdp->declBus(c+153,"wrapper top_core immediate U", false,-1, 31,0);
        vcdp->declBus(c+121,"wrapper top_core immediate I", false,-1, 31,0);
        vcdp->declBus(c+369,"wrapper top_core immediate II", false,-1, 11,0);
        vcdp->declBus(c+377,"wrapper top_core immediate SS", false,-1, 11,0);
        vcdp->declBus(c+385,"wrapper top_core immediate az", false,-1, 11,0);
        vcdp->declBus(c+393,"wrapper top_core immediate ay", false,-1, 20,0);
        vcdp->declBus(c+401,"wrapper top_core immediate ax", false,-1, 31,0);
        vcdp->declBus(c+249,"wrapper top_core opa_mux sel", false,-1, 1,0);
        vcdp->declBus(c+9,"wrapper top_core opa_mux a", false,-1, 31,0);
        vcdp->declBus(c+433,"wrapper top_core opa_mux b", false,-1, 31,0);
        vcdp->declBus(c+113,"wrapper top_core opa_mux c", false,-1, 31,0);
        vcdp->declBus(c+817,"wrapper top_core opa_mux d", false,-1, 31,0);
        vcdp->declBus(c+161,"wrapper top_core opa_mux o", false,-1, 31,0);
        vcdp->declBus(c+265,"wrapper top_core immediate_mux sel", false,-1, 1,0);
        vcdp->declBus(c+817,"wrapper top_core immediate_mux a", false,-1, 31,0);
        vcdp->declBus(c+153,"wrapper top_core immediate_mux b", false,-1, 31,0);
        vcdp->declBus(c+121,"wrapper top_core immediate_mux c", false,-1, 31,0);
        vcdp->declBus(c+129,"wrapper top_core immediate_mux d", false,-1, 31,0);
        vcdp->declBus(c+177,"wrapper top_core immediate_mux o", false,-1, 31,0);
        vcdp->declBit(c+289,"wrapper top_core mux1_20 sel", false,-1);
        vcdp->declBus(c+41,"wrapper top_core mux1_20 a", false,-1, 31,0);
        vcdp->declBus(c+177,"wrapper top_core mux1_20 b", false,-1, 31,0);
        vcdp->declBus(c+169,"wrapper top_core mux1_20 c", false,-1, 31,0);
        vcdp->declBus(c+305,"wrapper top_core ALU op", false,-1, 3,0);
        vcdp->declBus(c+161,"wrapper top_core ALU op1", false,-1, 31,0);
        vcdp->declBus(c+169,"wrapper top_core ALU op2", false,-1, 31,0);
        vcdp->declBus(c+185,"wrapper top_core ALU res", false,-1, 31,0);
        vcdp->declBus(c+161,"wrapper top_core branch op1", false,-1, 31,0);
        vcdp->declBus(c+169,"wrapper top_core branch op2", false,-1, 31,0);
        vcdp->declBus(c+241,"wrapper top_core branch fu_3", false,-1, 2,0);
        vcdp->declBit(c+281,"wrapper top_core branch en", false,-1);
        vcdp->declBit(c+105,"wrapper top_core branch re", false,-1);
        vcdp->declBit(c+17,"wrapper top_core mux1_21 sel", false,-1);
        vcdp->declBus(c+185,"wrapper top_core mux1_21 a", false,-1, 31,0);
        vcdp->declBus(c+65,"wrapper top_core mux1_21 b", false,-1, 31,0);
        vcdp->declBus(c+193,"wrapper top_core mux1_21 c", false,-1, 31,0);
        vcdp->declBit(c+25,"wrapper top_core mux1_22 sel", false,-1);
        vcdp->declBus(c+193,"wrapper top_core mux1_22 a", false,-1, 31,0);
        vcdp->declBus(c+817,"wrapper top_core mux1_22 b", false,-1, 31,0);
        vcdp->declBus(c+201,"wrapper top_core mux1_22 c", false,-1, 31,0);
        vcdp->declBit(c+105,"wrapper top_core branch_mux sel", false,-1);
        vcdp->declBus(c+433,"wrapper top_core branch_mux a", false,-1, 31,0);
        vcdp->declBus(c+137,"wrapper top_core branch_mux b", false,-1, 31,0);
        vcdp->declBus(c+113,"wrapper top_core branch_mux c", false,-1, 31,0);
        vcdp->declBit(c+705,"wrapper arbiter clk", false,-1);
        vcdp->declBit(c+17,"wrapper arbiter i_ld", false,-1);
        vcdp->declBit(c+25,"wrapper arbiter i_str", false,-1);
        vcdp->declBus(c+417,"wrapper arbiter i_ins_addr", false,-1, 11,0);
        vcdp->declBus(c+33,"wrapper arbiter i_data_addr", false,-1, 11,0);
        vcdp->declBus(c+57,"wrapper arbiter o_addr", false,-1, 12,0);
        vcdp->declBus(c+49,"wrapper arbiter i_data", false,-1, 31,0);
        vcdp->declBus(c+65,"wrapper arbiter o_ram_data", false,-1, 31,0);
        vcdp->declBus(c+73,"wrapper arbiter o_rom_data", false,-1, 31,0);
        vcdp->declBus(c+41,"wrapper arbiter i_opb", false,-1, 31,0);
        vcdp->declBus(c+81,"wrapper arbiter o_opb", false,-1, 31,0);
        vcdp->declBit(c+89,"wrapper arbiter write", false,-1);
        vcdp->declBit(c+705,"wrapper arbiter we", false,-1);
        vcdp->declBit(c+721,"wrapper arbiter re", false,-1);
        vcdp->declBit(c+409,"wrapper arbiter i_ack", false,-1);
        vcdp->declBus(c+57,"wrapper ram i_addre", false,-1, 12,0);
        vcdp->declBus(c+81,"wrapper ram i_data", false,-1, 31,0);
        vcdp->declBit(c+89,"wrapper ram i_wr", false,-1);
        vcdp->declBus(c+49,"wrapper ram o_data", false,-1, 31,0);
        vcdp->declBit(c+825,"wrapper ram en", false,-1);
    }
}

void Vwrapper::traceFullThis__1(Vwrapper__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vwrapper* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBus(c+1,(((2U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__next_pc))
                             ? ((1U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__next_pc))
                                 ? (vlTOPp->wrapper__DOT__top_core__DOT__I 
                                    + vlTOPp->wrapper__DOT__top_core__DOT__reg_1)
                                 : vlTOPp->wrapper__DOT__top_core__DOT__OUT_T)
                             : ((1U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__next_pc))
                                 ? vlTOPp->wrapper__DOT__top_core__DOT__UJ
                                 : ((IData)(4U) + vlTOPp->wrapper__DOT__top_core__DOT__adr)))),32);
        vcdp->fullBus(c+9,(((0U != (0x1fU & (vlTOPp->wrapper__DOT__o_rom_data 
                                             >> 0xfU)))
                             ? vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1
                            [(0x1fU & (vlTOPp->wrapper__DOT__o_rom_data 
                                       >> 0xfU))] : 0U)),32);
        vcdp->fullBit(c+17,((1U & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out) 
                                   >> 0xdU))));
        vcdp->fullBit(c+25,((1U & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out) 
                                   >> 0xcU))));
        vcdp->fullBus(c+33,((0xfffU & vlTOPp->wrapper__DOT__top_core__DOT__ALU_OUTPUT)),12);
        vcdp->fullBus(c+41,(vlTOPp->wrapper__DOT__top_core__DOT__op2),32);
        vcdp->fullBus(c+49,(vlTOPp->wrapper__DOT__o_data),32);
        vcdp->fullBus(c+57,(vlTOPp->wrapper__DOT__arbiter_addres),13);
        vcdp->fullBus(c+65,(vlTOPp->wrapper__DOT__o_ram_data),32);
        vcdp->fullBus(c+73,(vlTOPp->wrapper__DOT__o_rom_data),32);
        vcdp->fullBus(c+81,(vlTOPp->wrapper__DOT__o_rs2),32);
        vcdp->fullBit(c+89,(vlTOPp->wrapper__DOT__st));
        vcdp->fullBus(c+97,(vlTOPp->wrapper__DOT__top_core__DOT__data_out),15);
        vcdp->fullBit(c+105,(vlTOPp->wrapper__DOT__top_core__DOT__branch_p));
        vcdp->fullBus(c+113,(vlTOPp->wrapper__DOT__top_core__DOT__OUT_T),32);
        vcdp->fullBus(c+121,(vlTOPp->wrapper__DOT__top_core__DOT__I),32);
        vcdp->fullBus(c+129,(vlTOPp->wrapper__DOT__top_core__DOT__S),32);
        vcdp->fullBus(c+137,(vlTOPp->wrapper__DOT__top_core__DOT__SB),32);
        vcdp->fullBus(c+145,(vlTOPp->wrapper__DOT__top_core__DOT__UJ),32);
        vcdp->fullBus(c+153,(vlTOPp->wrapper__DOT__top_core__DOT__U),32);
        vcdp->fullBus(c+161,(vlTOPp->wrapper__DOT__top_core__DOT__reg_1),32);
        vcdp->fullBus(c+169,(vlTOPp->wrapper__DOT__top_core__DOT__reg_2),32);
        vcdp->fullBus(c+177,(((2U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out))
                               ? ((1U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out))
                                   ? vlTOPp->wrapper__DOT__top_core__DOT__S
                                   : vlTOPp->wrapper__DOT__top_core__DOT__I)
                               : ((1U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out))
                                   ? vlTOPp->wrapper__DOT__top_core__DOT__U
                                   : 0U))),32);
        vcdp->fullBus(c+185,(vlTOPp->wrapper__DOT__top_core__DOT__ALU_OUTPUT),32);
        vcdp->fullBus(c+193,(vlTOPp->wrapper__DOT__top_core__DOT__write_ba),32);
        vcdp->fullBus(c+201,(vlTOPp->wrapper__DOT__top_core__DOT__rite_ba),32);
        vcdp->fullBus(c+209,(vlTOPp->wrapper__DOT__top_core__DOT__c),9);
        vcdp->fullBus(c+217,((0x1fU & (vlTOPp->wrapper__DOT__o_rom_data 
                                       >> 0xfU))),5);
        vcdp->fullBus(c+225,((0x1fU & (vlTOPp->wrapper__DOT__o_rom_data 
                                       >> 0x14U))),5);
        vcdp->fullBus(c+233,((0x1fU & (vlTOPp->wrapper__DOT__o_rom_data 
                                       >> 7U))),5);
        vcdp->fullBus(c+241,((7U & (vlTOPp->wrapper__DOT__o_rom_data 
                                    >> 0xcU))),3);
        vcdp->fullBus(c+249,((3U & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out) 
                                    >> 9U))),2);
        vcdp->fullBus(c+257,(vlTOPp->wrapper__DOT__top_core__DOT__next_pc),2);
        vcdp->fullBus(c+265,((3U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out))),2);
        vcdp->fullBit(c+273,((1U & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out) 
                                    >> 0xeU))));
        vcdp->fullBit(c+281,((1U & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out) 
                                    >> 0xbU))));
        vcdp->fullBit(c+289,((1U & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out) 
                                    >> 8U))));
        vcdp->fullBit(c+297,((1U & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__c) 
                                    >> 3U))));
        vcdp->fullBus(c+305,((0xfU & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out) 
                                      >> 2U))),4);
        vcdp->fullBus(c+313,((vlTOPp->wrapper__DOT__top_core__DOT__I 
                              + vlTOPp->wrapper__DOT__top_core__DOT__reg_1)),32);
        vcdp->fullBus(c+321,((0x7fU & vlTOPp->wrapper__DOT__o_rom_data)),7);
        vcdp->fullBit(c+329,((1U & (vlTOPp->wrapper__DOT__o_rom_data 
                                    >> 0x1eU))));
        vcdp->fullBus(c+337,((0xfU & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__c))),4);
        vcdp->fullBus(c+345,((0xfU & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__c) 
                                      >> 5U))),4);
        vcdp->fullBus(c+353,((7U & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__c) 
                                    >> 2U))),3);
        vcdp->fullBus(c+361,(vlTOPp->wrapper__DOT__top_core__DOT__unit__DOT__d),3);
        vcdp->fullBus(c+369,(vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__II),12);
        vcdp->fullBus(c+377,(vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__SS),12);
        vcdp->fullBus(c+385,(vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__az),12);
        vcdp->fullBus(c+393,(vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__ay),21);
        vcdp->fullBus(c+401,(vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__ax),32);
        vcdp->fullBit(c+409,(vlTOPp->wrapper__DOT__arbiter__DOT__i_ack));
        vcdp->fullBus(c+417,((0xfffU & (vlTOPp->wrapper__DOT__top_core__DOT__adr 
                                        >> 2U))),12);
        vcdp->fullBus(c+425,(vlTOPp->wrapper__DOT__top_core__DOT__adr),32);
        vcdp->fullBus(c+433,(((IData)(4U) + vlTOPp->wrapper__DOT__top_core__DOT__adr)),32);
        vcdp->fullBus(c+441,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__i),32);
        vcdp->fullBus(c+449,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[0]),32);
        vcdp->fullBus(c+450,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[1]),32);
        vcdp->fullBus(c+451,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[2]),32);
        vcdp->fullBus(c+452,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[3]),32);
        vcdp->fullBus(c+453,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[4]),32);
        vcdp->fullBus(c+454,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[5]),32);
        vcdp->fullBus(c+455,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[6]),32);
        vcdp->fullBus(c+456,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[7]),32);
        vcdp->fullBus(c+457,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[8]),32);
        vcdp->fullBus(c+458,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[9]),32);
        vcdp->fullBus(c+459,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[10]),32);
        vcdp->fullBus(c+460,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[11]),32);
        vcdp->fullBus(c+461,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[12]),32);
        vcdp->fullBus(c+462,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[13]),32);
        vcdp->fullBus(c+463,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[14]),32);
        vcdp->fullBus(c+464,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[15]),32);
        vcdp->fullBus(c+465,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[16]),32);
        vcdp->fullBus(c+466,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[17]),32);
        vcdp->fullBus(c+467,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[18]),32);
        vcdp->fullBus(c+468,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[19]),32);
        vcdp->fullBus(c+469,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[20]),32);
        vcdp->fullBus(c+470,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[21]),32);
        vcdp->fullBus(c+471,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[22]),32);
        vcdp->fullBus(c+472,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[23]),32);
        vcdp->fullBus(c+473,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[24]),32);
        vcdp->fullBus(c+474,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[25]),32);
        vcdp->fullBus(c+475,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[26]),32);
        vcdp->fullBus(c+476,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[27]),32);
        vcdp->fullBus(c+477,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[28]),32);
        vcdp->fullBus(c+478,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[29]),32);
        vcdp->fullBus(c+479,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[30]),32);
        vcdp->fullBus(c+480,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[31]),32);
        vcdp->fullBit(c+705,(vlTOPp->clk));
        vcdp->fullBit(c+713,(vlTOPp->reset));
        vcdp->fullBit(c+721,((1U & (~ (IData)(vlTOPp->clk)))));
        vcdp->fullBus(c+729,(vlTOPp->wrapper__DOT__o_dram),32);
        vcdp->fullBus(c+737,(vlTOPp->wrapper__DOT__o_iram),32);
        vcdp->fullBus(c+745,(vlTOPp->wrapper__DOT__o_ar_data),32);
        vcdp->fullBus(c+753,(vlTOPp->wrapper__DOT__top_core__DOT__b),32);
        vcdp->fullBus(c+761,(vlTOPp->wrapper__DOT__top_core__DOT__faltu),32);
        vcdp->fullBus(c+769,(vlTOPp->wrapper__DOT__top_core__DOT__write_adder),32);
        vcdp->fullBus(c+777,(vlTOPp->wrapper__DOT__top_core__DOT__rb1),32);
        vcdp->fullBus(c+785,(vlTOPp->wrapper__DOT__top_core__DOT__re),5);
        vcdp->fullBus(c+793,(vlTOPp->wrapper__DOT__top_core__DOT__ac),32);
        vcdp->fullBus(c+801,(0U),32);
        vcdp->fullBus(c+809,(vlTOPp->wrapper__DOT__top_core__DOT__control__DOT__b),25);
        vcdp->fullBus(c+817,(0U),32);
        vcdp->fullBit(c+825,(0U));
    }
}
