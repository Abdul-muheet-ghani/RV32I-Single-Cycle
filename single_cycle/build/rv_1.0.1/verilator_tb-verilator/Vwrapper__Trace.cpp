// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vwrapper__Syms.h"


//======================

void Vwrapper::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vwrapper* t = (Vwrapper*)userthis;
    Vwrapper__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void Vwrapper::traceChgThis(Vwrapper__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vwrapper* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
                                | (vlTOPp->__Vm_traceActivity 
                                   >> 1U)) | (vlTOPp->__Vm_traceActivity 
                                              >> 2U))))) {
            vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 2U))))) {
            vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vwrapper::traceChgThis__2(Vwrapper__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vwrapper* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+1,(((2U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__next_pc))
                            ? ((1U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__next_pc))
                                ? (vlTOPp->wrapper__DOT__top_core__DOT__I 
                                   + vlTOPp->wrapper__DOT__top_core__DOT__reg_1)
                                : vlTOPp->wrapper__DOT__top_core__DOT__OUT_T)
                            : ((1U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__next_pc))
                                ? vlTOPp->wrapper__DOT__top_core__DOT__UJ
                                : ((IData)(4U) + vlTOPp->wrapper__DOT__top_core__DOT__adr)))),32);
        vcdp->chgBus(c+9,(((0U != (0x1fU & (vlTOPp->wrapper__DOT__o_rom_data 
                                            >> 0xfU)))
                            ? vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1
                           [(0x1fU & (vlTOPp->wrapper__DOT__o_rom_data 
                                      >> 0xfU))] : 0U)),32);
    }
}

void Vwrapper::traceChgThis__3(Vwrapper__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vwrapper* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+17,((1U & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out) 
                                  >> 0xdU))));
        vcdp->chgBit(c+25,((1U & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out) 
                                  >> 0xcU))));
        vcdp->chgBus(c+33,((0xfffU & vlTOPp->wrapper__DOT__top_core__DOT__ALU_OUTPUT)),12);
        vcdp->chgBus(c+41,(vlTOPp->wrapper__DOT__top_core__DOT__op2),32);
        vcdp->chgBus(c+49,(vlTOPp->wrapper__DOT__o_data),32);
        vcdp->chgBus(c+57,(vlTOPp->wrapper__DOT__arbiter_addres),13);
        vcdp->chgBus(c+65,(vlTOPp->wrapper__DOT__o_ram_data),32);
        vcdp->chgBus(c+73,(vlTOPp->wrapper__DOT__o_rom_data),32);
        vcdp->chgBus(c+81,(vlTOPp->wrapper__DOT__o_rs2),32);
        vcdp->chgBit(c+89,(vlTOPp->wrapper__DOT__st));
        vcdp->chgBus(c+97,(vlTOPp->wrapper__DOT__top_core__DOT__data_out),15);
        vcdp->chgBit(c+105,(vlTOPp->wrapper__DOT__top_core__DOT__branch_p));
        vcdp->chgBus(c+113,(vlTOPp->wrapper__DOT__top_core__DOT__OUT_T),32);
        vcdp->chgBus(c+121,(vlTOPp->wrapper__DOT__top_core__DOT__I),32);
        vcdp->chgBus(c+129,(vlTOPp->wrapper__DOT__top_core__DOT__S),32);
        vcdp->chgBus(c+137,(vlTOPp->wrapper__DOT__top_core__DOT__SB),32);
        vcdp->chgBus(c+145,(vlTOPp->wrapper__DOT__top_core__DOT__UJ),32);
        vcdp->chgBus(c+153,(vlTOPp->wrapper__DOT__top_core__DOT__U),32);
        vcdp->chgBus(c+161,(vlTOPp->wrapper__DOT__top_core__DOT__reg_1),32);
        vcdp->chgBus(c+169,(vlTOPp->wrapper__DOT__top_core__DOT__reg_2),32);
        vcdp->chgBus(c+177,(((2U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out))
                              ? ((1U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out))
                                  ? vlTOPp->wrapper__DOT__top_core__DOT__S
                                  : vlTOPp->wrapper__DOT__top_core__DOT__I)
                              : ((1U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out))
                                  ? vlTOPp->wrapper__DOT__top_core__DOT__U
                                  : 0U))),32);
        vcdp->chgBus(c+185,(vlTOPp->wrapper__DOT__top_core__DOT__ALU_OUTPUT),32);
        vcdp->chgBus(c+193,(vlTOPp->wrapper__DOT__top_core__DOT__write_ba),32);
        vcdp->chgBus(c+201,(vlTOPp->wrapper__DOT__top_core__DOT__rite_ba),32);
        vcdp->chgBus(c+209,(vlTOPp->wrapper__DOT__top_core__DOT__c),9);
        vcdp->chgBus(c+217,((0x1fU & (vlTOPp->wrapper__DOT__o_rom_data 
                                      >> 0xfU))),5);
        vcdp->chgBus(c+225,((0x1fU & (vlTOPp->wrapper__DOT__o_rom_data 
                                      >> 0x14U))),5);
        vcdp->chgBus(c+233,((0x1fU & (vlTOPp->wrapper__DOT__o_rom_data 
                                      >> 7U))),5);
        vcdp->chgBus(c+241,((7U & (vlTOPp->wrapper__DOT__o_rom_data 
                                   >> 0xcU))),3);
        vcdp->chgBus(c+249,((3U & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out) 
                                   >> 9U))),2);
        vcdp->chgBus(c+257,(vlTOPp->wrapper__DOT__top_core__DOT__next_pc),2);
        vcdp->chgBus(c+265,((3U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out))),2);
        vcdp->chgBit(c+273,((1U & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out) 
                                   >> 0xeU))));
        vcdp->chgBit(c+281,((1U & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out) 
                                   >> 0xbU))));
        vcdp->chgBit(c+289,((1U & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out) 
                                   >> 8U))));
        vcdp->chgBit(c+297,((1U & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__c) 
                                   >> 3U))));
        vcdp->chgBus(c+305,((0xfU & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out) 
                                     >> 2U))),4);
        vcdp->chgBus(c+313,((vlTOPp->wrapper__DOT__top_core__DOT__I 
                             + vlTOPp->wrapper__DOT__top_core__DOT__reg_1)),32);
        vcdp->chgBus(c+321,((0x7fU & vlTOPp->wrapper__DOT__o_rom_data)),7);
        vcdp->chgBit(c+329,((1U & (vlTOPp->wrapper__DOT__o_rom_data 
                                   >> 0x1eU))));
        vcdp->chgBus(c+337,((0xfU & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__c))),4);
        vcdp->chgBus(c+345,((0xfU & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__c) 
                                     >> 5U))),4);
        vcdp->chgBus(c+353,((7U & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__c) 
                                   >> 2U))),3);
        vcdp->chgBus(c+361,(vlTOPp->wrapper__DOT__top_core__DOT__unit__DOT__d),3);
        vcdp->chgBus(c+369,(vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__II),12);
        vcdp->chgBus(c+377,(vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__SS),12);
        vcdp->chgBus(c+385,(vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__az),12);
        vcdp->chgBus(c+393,(vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__ay),21);
        vcdp->chgBus(c+401,(vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__ax),32);
        vcdp->chgBit(c+409,(vlTOPp->wrapper__DOT__arbiter__DOT__i_ack));
    }
}

void Vwrapper::traceChgThis__4(Vwrapper__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vwrapper* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+417,((0xfffU & (vlTOPp->wrapper__DOT__top_core__DOT__adr 
                                       >> 2U))),12);
        vcdp->chgBus(c+425,(vlTOPp->wrapper__DOT__top_core__DOT__adr),32);
        vcdp->chgBus(c+433,(((IData)(4U) + vlTOPp->wrapper__DOT__top_core__DOT__adr)),32);
        vcdp->chgBus(c+441,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__i),32);
        vcdp->chgBus(c+449,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[0]),32);
        vcdp->chgBus(c+450,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[1]),32);
        vcdp->chgBus(c+451,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[2]),32);
        vcdp->chgBus(c+452,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[3]),32);
        vcdp->chgBus(c+453,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[4]),32);
        vcdp->chgBus(c+454,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[5]),32);
        vcdp->chgBus(c+455,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[6]),32);
        vcdp->chgBus(c+456,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[7]),32);
        vcdp->chgBus(c+457,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[8]),32);
        vcdp->chgBus(c+458,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[9]),32);
        vcdp->chgBus(c+459,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[10]),32);
        vcdp->chgBus(c+460,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[11]),32);
        vcdp->chgBus(c+461,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[12]),32);
        vcdp->chgBus(c+462,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[13]),32);
        vcdp->chgBus(c+463,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[14]),32);
        vcdp->chgBus(c+464,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[15]),32);
        vcdp->chgBus(c+465,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[16]),32);
        vcdp->chgBus(c+466,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[17]),32);
        vcdp->chgBus(c+467,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[18]),32);
        vcdp->chgBus(c+468,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[19]),32);
        vcdp->chgBus(c+469,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[20]),32);
        vcdp->chgBus(c+470,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[21]),32);
        vcdp->chgBus(c+471,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[22]),32);
        vcdp->chgBus(c+472,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[23]),32);
        vcdp->chgBus(c+473,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[24]),32);
        vcdp->chgBus(c+474,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[25]),32);
        vcdp->chgBus(c+475,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[26]),32);
        vcdp->chgBus(c+476,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[27]),32);
        vcdp->chgBus(c+477,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[28]),32);
        vcdp->chgBus(c+478,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[29]),32);
        vcdp->chgBus(c+479,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[30]),32);
        vcdp->chgBus(c+480,(vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[31]),32);
    }
}

void Vwrapper::traceChgThis__5(Vwrapper__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vwrapper* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+705,(vlTOPp->clk));
        vcdp->chgBit(c+713,(vlTOPp->reset));
        vcdp->chgBit(c+721,((1U & (~ (IData)(vlTOPp->clk)))));
    }
}
