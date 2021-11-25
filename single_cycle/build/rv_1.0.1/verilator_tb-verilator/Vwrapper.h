// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VWRAPPER_H_
#define _VWRAPPER_H_  // guard

#include "verilated_heavy.h"

//==========

class Vwrapper__Syms;
class Vwrapper_VerilatedVcd;


//----------

VL_MODULE(Vwrapper) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ wrapper__DOT__st;
    CData/*0:0*/ wrapper__DOT__top_core__DOT__branch_p;
    CData/*4:0*/ wrapper__DOT__top_core__DOT__re;
    CData/*1:0*/ wrapper__DOT__top_core__DOT__next_pc;
    CData/*2:0*/ wrapper__DOT__top_core__DOT__unit__DOT__d;
    CData/*0:0*/ wrapper__DOT__arbiter__DOT__i_ack;
    SData/*12:0*/ wrapper__DOT__arbiter_addres;
    SData/*14:0*/ wrapper__DOT__top_core__DOT__data_out;
    SData/*8:0*/ wrapper__DOT__top_core__DOT__c;
    SData/*11:0*/ wrapper__DOT__top_core__DOT__immediate__DOT__II;
    SData/*11:0*/ wrapper__DOT__top_core__DOT__immediate__DOT__SS;
    SData/*11:0*/ wrapper__DOT__top_core__DOT__immediate__DOT__az;
    IData/*31:0*/ wrapper__DOT__o_dram;
    IData/*31:0*/ wrapper__DOT__o_iram;
    IData/*31:0*/ wrapper__DOT__o_data;
    IData/*31:0*/ wrapper__DOT__o_ar_data;
    IData/*31:0*/ wrapper__DOT__o_ram_data;
    IData/*31:0*/ wrapper__DOT__o_rom_data;
    IData/*31:0*/ wrapper__DOT__o_rs2;
    IData/*31:0*/ wrapper__DOT__top_core__DOT__OUT_T;
    IData/*31:0*/ wrapper__DOT__top_core__DOT__addr;
    IData/*31:0*/ wrapper__DOT__top_core__DOT__adr;
    IData/*31:0*/ wrapper__DOT__top_core__DOT__b;
    IData/*31:0*/ wrapper__DOT__top_core__DOT__I;
    IData/*31:0*/ wrapper__DOT__top_core__DOT__S;
    IData/*31:0*/ wrapper__DOT__top_core__DOT__SB;
    IData/*31:0*/ wrapper__DOT__top_core__DOT__UJ;
    IData/*31:0*/ wrapper__DOT__top_core__DOT__U;
    IData/*31:0*/ wrapper__DOT__top_core__DOT__op2;
    IData/*31:0*/ wrapper__DOT__top_core__DOT__faltu;
    IData/*31:0*/ wrapper__DOT__top_core__DOT__reg_1;
    IData/*31:0*/ wrapper__DOT__top_core__DOT__reg_2;
    IData/*31:0*/ wrapper__DOT__top_core__DOT__ALU_OUTPUT;
    IData/*31:0*/ wrapper__DOT__top_core__DOT__write_adder;
    IData/*31:0*/ wrapper__DOT__top_core__DOT__write_ba;
    IData/*31:0*/ wrapper__DOT__top_core__DOT__rite_ba;
    IData/*31:0*/ wrapper__DOT__top_core__DOT__rb1;
    IData/*31:0*/ wrapper__DOT__top_core__DOT__ac;
    IData/*24:0*/ wrapper__DOT__top_core__DOT__control__DOT__b;
    IData/*31:0*/ wrapper__DOT__top_core__DOT__reg_file__DOT__i;
    IData/*20:0*/ wrapper__DOT__top_core__DOT__immediate__DOT__ay;
    IData/*31:0*/ wrapper__DOT__top_core__DOT__immediate__DOT__ax;
    IData/*31:0*/ wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[32];
    IData/*31:0*/ wrapper__DOT__ram__DOT__mem[8192];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*6:0*/ __Vtableidx1;
    CData/*0:0*/ __Vclklast__TOP__clk;
    IData/*31:0*/ __Vchglast__TOP__wrapper__DOT__o_data;
    IData/*31:0*/ __Vchglast__TOP__wrapper__DOT__top_core__DOT__OUT_T;
    IData/*31:0*/ __Vm_traceActivity;
    static SData/*8:0*/ __Vtable1_wrapper__DOT__top_core__DOT__c[128];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vwrapper__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vwrapper);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vwrapper(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vwrapper();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vwrapper__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vwrapper__Syms* symsp, bool first);
  private:
    static QData _change_request(Vwrapper__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vwrapper__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vwrapper__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vwrapper__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vwrapper__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(Vwrapper__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(Vwrapper__Syms* __restrict vlSymsp);
    static void traceChgThis(Vwrapper__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(Vwrapper__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(Vwrapper__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__4(Vwrapper__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__5(Vwrapper__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(Vwrapper__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceFullThis__1(Vwrapper__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis(Vwrapper__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis__1(Vwrapper__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
