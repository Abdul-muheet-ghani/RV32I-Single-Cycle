// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vwrapper.h for the primary calling header

#include "Vwrapper.h"
#include "Vwrapper__Syms.h"

//==========
SData/*8:0*/ Vwrapper::__Vtable1_wrapper__DOT__top_core__DOT__c[128];

VL_CTOR_IMP(Vwrapper) {
    Vwrapper__Syms* __restrict vlSymsp = __VlSymsp = new Vwrapper__Syms(this, name());
    Vwrapper* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vwrapper::__Vconfigure(Vwrapper__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vwrapper::~Vwrapper() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vwrapper::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vwrapper::eval\n"); );
    Vwrapper__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vwrapper* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("../src/rv_1.0.1/rtl/wrapper.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vwrapper::_eval_initial_loop(Vwrapper__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("../src/rv_1.0.1/rtl/wrapper.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vwrapper::_initial__TOP__1(Vwrapper__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwrapper::_initial__TOP__1\n"); );
    Vwrapper* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*543:0*/ __Vtemp1[17];
    // Body
    __Vtemp1[0U] = 0x2e6d656dU;
    __Vtemp1[1U] = 0x636f6566U;
    __Vtemp1[2U] = 0x72746c2fU;
    __Vtemp1[3U] = 0x636c652fU;
    __Vtemp1[4U] = 0x655f6379U;
    __Vtemp1[5U] = 0x696e676cU;
    __Vtemp1[6U] = 0x65732f73U;
    __Vtemp1[7U] = 0x72617269U;
    __Vtemp1[8U] = 0x5f6c6962U;
    __Vtemp1[9U] = 0x65736f63U;
    __Vtemp1[0xaU] = 0x2f667573U;
    __Vtemp1[0xbU] = 0x6f6c6f66U;
    __Vtemp1[0xcU] = 0x616e692fU;
    __Vtemp1[0xdU] = 0x742d6768U;
    __Vtemp1[0xeU] = 0x75686565U;
    __Vtemp1[0xfU] = 0x6d652f6dU;
    __Vtemp1[0x10U] = 0x2f686fU;
    VL_READMEM_N(true, 32, 8192, 0, VL_CVT_PACK_STR_NW(17, __Vtemp1)
                 , vlTOPp->wrapper__DOT__ram__DOT__mem
                 , 0, ~VL_ULL(0));
    vlTOPp->wrapper__DOT__top_core__DOT__next_pc = 0U;
}

VL_INLINE_OPT void Vwrapper::_sequent__TOP__2(Vwrapper__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwrapper::_sequent__TOP__2\n"); );
    Vwrapper* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->reset) {
        vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__i = 0x20U;
    }
    if (vlTOPp->reset) {
        vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[0U] = 0U;
        vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[1U] = 0U;
        vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[2U] = 0U;
        vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[3U] = 0U;
        vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[4U] = 0U;
        vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[5U] = 0U;
        vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[6U] = 0U;
        vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[7U] = 0U;
        vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[8U] = 0U;
        vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[9U] = 0U;
        vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[0xaU] = 0U;
        vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[0xbU] = 0U;
        vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[0xcU] = 0U;
        vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[0xdU] = 0U;
        vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[0xeU] = 0U;
        vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[0xfU] = 0U;
        vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[0x10U] = 0U;
        vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[0x11U] = 0U;
        vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[0x12U] = 0U;
        vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[0x13U] = 0U;
        vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[0x14U] = 0U;
        vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[0x15U] = 0U;
        vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[0x16U] = 0U;
        vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[0x17U] = 0U;
        vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[0x18U] = 0U;
        vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[0x19U] = 0U;
        vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[0x1aU] = 0U;
        vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[0x1bU] = 0U;
        vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[0x1cU] = 0U;
        vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[0x1dU] = 0U;
        vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[0x1eU] = 0U;
        vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[0x1fU] = 0U;
    } else {
        vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[(0x1fU 
                                                                       & (vlTOPp->wrapper__DOT__o_rom_data 
                                                                          >> 7U))] 
            = vlTOPp->wrapper__DOT__top_core__DOT__write_ba;
    }
    vlTOPp->wrapper__DOT__top_core__DOT__adr = ((IData)(vlTOPp->reset)
                                                 ? 0U
                                                 : vlTOPp->wrapper__DOT__top_core__DOT__addr);
}

VL_INLINE_OPT void Vwrapper::_settle__TOP__3(Vwrapper__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwrapper::_settle__TOP__3\n"); );
    Vwrapper* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->clk) {
        vlTOPp->wrapper__DOT__o_rom_data = vlTOPp->wrapper__DOT__o_data;
    }
    vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__ax 
        = ((0xfff00000U & vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__ax) 
           | (0xfffffU & (vlTOPp->wrapper__DOT__o_rom_data 
                          >> 0xcU)));
    vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__ax 
        = (0xfffffU & vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__ax);
    vlTOPp->wrapper__DOT__top_core__DOT__U = (vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__ax 
                                              << 0xcU);
    vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__SS 
        = ((0xfe0U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__SS)) 
           | (0x1fU & (vlTOPp->wrapper__DOT__o_rom_data 
                       >> 7U)));
    vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__SS 
        = ((0x1fU & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__SS)) 
           | (0xfe0U & (vlTOPp->wrapper__DOT__o_rom_data 
                        >> 0x14U)));
    vlTOPp->wrapper__DOT__top_core__DOT__S = ((0xfffff000U 
                                               & (VL_NEGATE_I((IData)(
                                                                      (1U 
                                                                       & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__SS) 
                                                                          >> 0xbU)))) 
                                                  << 0xcU)) 
                                              | (IData)(vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__SS));
    vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__II 
        = (0xfffU & (vlTOPp->wrapper__DOT__o_rom_data 
                     >> 0x14U));
    vlTOPp->wrapper__DOT__top_core__DOT__I = ((0xfffff000U 
                                               & (VL_NEGATE_I((IData)(
                                                                      (1U 
                                                                       & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__II) 
                                                                          >> 0xbU)))) 
                                                  << 0xcU)) 
                                              | (IData)(vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__II));
    vlTOPp->wrapper__DOT__top_core__DOT__op2 = ((0U 
                                                 != 
                                                 (0x1fU 
                                                  & (vlTOPp->wrapper__DOT__o_rom_data 
                                                     >> 0x14U)))
                                                 ? 
                                                vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1
                                                [(0x1fU 
                                                  & (vlTOPp->wrapper__DOT__o_rom_data 
                                                     >> 0x14U))]
                                                 : 0U);
    vlTOPp->__Vtableidx1 = (0x7fU & vlTOPp->wrapper__DOT__o_rom_data);
    vlTOPp->wrapper__DOT__top_core__DOT__c = vlTOPp->__Vtable1_wrapper__DOT__top_core__DOT__c
        [vlTOPp->__Vtableidx1];
    vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__az 
        = (0xffeU & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__az));
    vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__az 
        = ((0xfe1U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__az)) 
           | (0x1eU & (vlTOPp->wrapper__DOT__o_rom_data 
                       >> 7U)));
    vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__az 
        = ((0x81fU & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__az)) 
           | (0x7e0U & (vlTOPp->wrapper__DOT__o_rom_data 
                        >> 0x14U)));
    vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__az 
        = ((0x7ffU & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__az)) 
           | (0x800U & (vlTOPp->wrapper__DOT__o_rom_data 
                        << 4U)));
    vlTOPp->wrapper__DOT__top_core__DOT__SB = (vlTOPp->wrapper__DOT__top_core__DOT__adr 
                                               + VL_EXTENDS_II(32,12, (IData)(vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__az)));
    vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__ay 
        = (0x1ffffeU & vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__ay);
    vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__ay 
        = ((0x1ff801U & vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__ay) 
           | (0x7feU & (vlTOPp->wrapper__DOT__o_rom_data 
                        >> 0x14U)));
    vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__ay 
        = ((0x1ff7ffU & vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__ay) 
           | (0x800U & (vlTOPp->wrapper__DOT__o_rom_data 
                        >> 9U)));
    vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__ay 
        = ((0x100fffU & vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__ay) 
           | (0xff000U & vlTOPp->wrapper__DOT__o_rom_data));
    vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__ay 
        = ((0xfffffU & vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__ay) 
           | (0x100000U & (vlTOPp->wrapper__DOT__o_rom_data 
                           >> 0xbU)));
    vlTOPp->wrapper__DOT__top_core__DOT__UJ = (vlTOPp->wrapper__DOT__top_core__DOT__adr 
                                               + VL_EXTENDS_II(32,21, vlTOPp->wrapper__DOT__top_core__DOT__immediate__DOT__ay));
    vlTOPp->wrapper__DOT__top_core__DOT__unit__DOT__d 
        = ((6U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__unit__DOT__d)) 
           | (1U & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__c) 
                    >> 5U)));
    vlTOPp->wrapper__DOT__top_core__DOT__unit__DOT__d 
        = ((5U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__unit__DOT__d)) 
           | (2U & (((IData)(vlTOPp->wrapper__DOT__top_core__DOT__c) 
                     << 1U) | (0xfffffffeU & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__c)))));
    vlTOPp->wrapper__DOT__top_core__DOT__unit__DOT__d 
        = ((3U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__unit__DOT__d)) 
           | (4U & (((0xfffffffcU & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__c)) 
                     | (0xffffffcU & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__c) 
                                      >> 4U))) | (0x7fffffcU 
                                                  & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__c) 
                                                     >> 5U)))));
    vlTOPp->wrapper__DOT__top_core__DOT__data_out = 
        ((0x3fffU & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out)) 
         | (0x4000U & ((((((((IData)(vlTOPp->wrapper__DOT__top_core__DOT__c) 
                             << 0xeU) | (0xffffc000U 
                                         & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__c) 
                                            << 0xdU))) 
                           | (0xffffc000U & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__c) 
                                             << 0xcU))) 
                          | (0xffffc000U & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__c) 
                                            << 0xbU))) 
                         | (0xffffc000U & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__c) 
                                           << 8U))) 
                        | (0xffffc000U & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__c) 
                                          << 7U))) 
                       | (0xffffc000U & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__c) 
                                         << 6U)))));
    vlTOPp->wrapper__DOT__top_core__DOT__data_out = 
        ((0x5fffU & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out)) 
         | (0x2000U & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__c) 
                       << 7U)));
    vlTOPp->wrapper__DOT__top_core__DOT__data_out = 
        ((0x6fffU & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out)) 
         | (0x1000U & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__c) 
                       << 7U)));
    vlTOPp->wrapper__DOT__top_core__DOT__data_out = 
        ((0x77ffU & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out)) 
         | (0x800U & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__c) 
                      << 7U)));
    vlTOPp->wrapper__DOT__top_core__DOT__data_out = 
        ((0x79ffU & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out)) 
         | (((1U == (0xfU & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__c)))
              ? 1U : ((0xaU == (0xfU & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__c)))
                       ? 3U : 0U)) << 9U));
    vlTOPp->wrapper__DOT__top_core__DOT__data_out = 
        ((0x7effU & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out)) 
         | (0x100U & (((((((IData)(vlTOPp->wrapper__DOT__top_core__DOT__c) 
                           << 8U) | (0xffffff00U & 
                                     ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__c) 
                                      << 7U))) | (0xffffff00U 
                                                  & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__c) 
                                                     << 3U))) 
                        | (0xffffff00U & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__c) 
                                          << 1U))) 
                       | (0xffffff00U & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__c) 
                                         << 2U))) | 
                      (0xffffff00U & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__c) 
                                      << 6U)))));
    vlTOPp->wrapper__DOT__top_core__DOT__data_out = 
        ((0x7f3fU & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out)) 
         | (((1U == (7U & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__c) 
                           >> 2U))) ? 3U : ((2U == 
                                             (7U & 
                                              ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__c) 
                                               >> 2U)))
                                             ? 1U : 
                                            ((4U == 
                                              (7U & 
                                               ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__c) 
                                                >> 2U)))
                                              ? 2U : 0U))) 
            << 6U));
    if ((0x100U == (IData)(vlTOPp->wrapper__DOT__top_core__DOT__c))) {
        vlTOPp->wrapper__DOT__top_core__DOT__data_out 
            = ((0x7fc3U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out)) 
               | (((0x40000000U & vlTOPp->wrapper__DOT__o_rom_data)
                    ? ((0x4000U & vlTOPp->wrapper__DOT__o_rom_data)
                        ? ((0x2000U & vlTOPp->wrapper__DOT__o_rom_data)
                            ? 3U : ((0x1000U & vlTOPp->wrapper__DOT__o_rom_data)
                                     ? 9U : 5U)) : 
                       ((0x2000U & vlTOPp->wrapper__DOT__o_rom_data)
                         ? ((0x1000U & vlTOPp->wrapper__DOT__o_rom_data)
                             ? 9U : 7U) : ((0x1000U 
                                            & vlTOPp->wrapper__DOT__o_rom_data)
                                            ? 0xdU : 1U)))
                    : ((0x4000U & vlTOPp->wrapper__DOT__o_rom_data)
                        ? ((0x2000U & vlTOPp->wrapper__DOT__o_rom_data)
                            ? ((0x1000U & vlTOPp->wrapper__DOT__o_rom_data)
                                ? 2U : 3U) : ((0x1000U 
                                               & vlTOPp->wrapper__DOT__o_rom_data)
                                               ? 6U
                                               : 4U))
                        : ((0x2000U & vlTOPp->wrapper__DOT__o_rom_data)
                            ? ((0x1000U & vlTOPp->wrapper__DOT__o_rom_data)
                                ? 8U : 7U) : ((0x1000U 
                                               & vlTOPp->wrapper__DOT__o_rom_data)
                                               ? 5U
                                               : 0U)))) 
                  << 2U));
    }
    if ((0x80U == (IData)(vlTOPp->wrapper__DOT__top_core__DOT__c))) {
        vlTOPp->wrapper__DOT__top_core__DOT__data_out 
            = ((0x7fc3U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out)) 
               | (((0x40000000U & vlTOPp->wrapper__DOT__o_rom_data)
                    ? ((0x4000U & vlTOPp->wrapper__DOT__o_rom_data)
                        ? ((0x2000U & vlTOPp->wrapper__DOT__o_rom_data)
                            ? ((0x1000U & vlTOPp->wrapper__DOT__o_rom_data)
                                ? 2U : 3U) : ((0x1000U 
                                               & vlTOPp->wrapper__DOT__o_rom_data)
                                               ? 9U
                                               : 4U))
                        : ((0x2000U & vlTOPp->wrapper__DOT__o_rom_data)
                            ? ((0x1000U & vlTOPp->wrapper__DOT__o_rom_data)
                                ? 8U : 7U) : ((0x1000U 
                                               & vlTOPp->wrapper__DOT__o_rom_data)
                                               ? 0xdU
                                               : 0U)))
                    : ((0x4000U & vlTOPp->wrapper__DOT__o_rom_data)
                        ? ((0x2000U & vlTOPp->wrapper__DOT__o_rom_data)
                            ? ((0x1000U & vlTOPp->wrapper__DOT__o_rom_data)
                                ? 2U : 3U) : ((0x1000U 
                                               & vlTOPp->wrapper__DOT__o_rom_data)
                                               ? 6U
                                               : 4U))
                        : ((0x2000U & vlTOPp->wrapper__DOT__o_rom_data)
                            ? ((0x1000U & vlTOPp->wrapper__DOT__o_rom_data)
                                ? 8U : 7U) : ((0x1000U 
                                               & vlTOPp->wrapper__DOT__o_rom_data)
                                               ? 5U
                                               : 0U)))) 
                  << 2U));
    }
    if ((0x40U == (IData)(vlTOPp->wrapper__DOT__top_core__DOT__c))) {
        if ((2U == (7U & (vlTOPp->wrapper__DOT__o_rom_data 
                          >> 0xcU)))) {
            vlTOPp->wrapper__DOT__top_core__DOT__data_out 
                = (0x7fc3U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out));
        }
    }
    if (((0x20U == (IData)(vlTOPp->wrapper__DOT__top_core__DOT__c)) 
         & (2U == (7U & (vlTOPp->wrapper__DOT__o_rom_data 
                         >> 0xcU))))) {
        vlTOPp->wrapper__DOT__top_core__DOT__data_out 
            = (0x7fc3U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out));
    }
    if ((8U == (IData)(vlTOPp->wrapper__DOT__top_core__DOT__c))) {
        vlTOPp->wrapper__DOT__top_core__DOT__data_out 
            = (0x3cU | (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out));
    }
    if (((4U == (IData)(vlTOPp->wrapper__DOT__top_core__DOT__c)) 
         & (0U == (7U & (vlTOPp->wrapper__DOT__o_rom_data 
                         >> 0xcU))))) {
        vlTOPp->wrapper__DOT__top_core__DOT__data_out 
            = (0x3cU | (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out));
    }
    if ((2U == (IData)(vlTOPp->wrapper__DOT__top_core__DOT__c))) {
        vlTOPp->wrapper__DOT__top_core__DOT__data_out 
            = (0x7fc3U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out));
    }
    if ((1U == (IData)(vlTOPp->wrapper__DOT__top_core__DOT__c))) {
        vlTOPp->wrapper__DOT__top_core__DOT__data_out 
            = (0x7fc3U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out));
    }
    vlTOPp->wrapper__DOT__top_core__DOT__data_out = 
        ((0x7ffcU & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out)) 
         | ((1U == (IData)(vlTOPp->wrapper__DOT__top_core__DOT__unit__DOT__d))
             ? 3U : ((2U == (IData)(vlTOPp->wrapper__DOT__top_core__DOT__unit__DOT__d))
                      ? 1U : ((4U == (IData)(vlTOPp->wrapper__DOT__top_core__DOT__unit__DOT__d))
                               ? 2U : 0U))));
    vlTOPp->wrapper__DOT__top_core__DOT__next_pc = 
        (3U & ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out) 
               >> 6U));
    if ((0x100U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out))) {
        if ((0x100U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out))) {
            vlTOPp->wrapper__DOT__top_core__DOT__reg_2 
                = ((2U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out))
                    ? ((1U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out))
                        ? vlTOPp->wrapper__DOT__top_core__DOT__S
                        : vlTOPp->wrapper__DOT__top_core__DOT__I)
                    : ((1U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out))
                        ? vlTOPp->wrapper__DOT__top_core__DOT__U
                        : 0U));
        }
    } else {
        vlTOPp->wrapper__DOT__top_core__DOT__reg_2 
            = vlTOPp->wrapper__DOT__top_core__DOT__op2;
    }
    vlTOPp->wrapper__DOT__top_core__DOT__reg_1 = ((0x400U 
                                                   & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out))
                                                   ? 
                                                  ((0x200U 
                                                    & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out))
                                                    ? 0U
                                                    : vlTOPp->wrapper__DOT__top_core__DOT__OUT_T)
                                                   : 
                                                  ((0x200U 
                                                    & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out))
                                                    ? 
                                                   ((IData)(4U) 
                                                    + vlTOPp->wrapper__DOT__top_core__DOT__adr)
                                                    : 
                                                   ((0U 
                                                     != 
                                                     (0x1fU 
                                                      & (vlTOPp->wrapper__DOT__o_rom_data 
                                                         >> 0xfU)))
                                                     ? 
                                                    vlTOPp->wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1
                                                    [
                                                    (0x1fU 
                                                     & (vlTOPp->wrapper__DOT__o_rom_data 
                                                        >> 0xfU))]
                                                     : 0U)));
    vlTOPp->wrapper__DOT__arbiter__DOT__i_ack = (1U 
                                                 & (((IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out) 
                                                     >> 0xdU) 
                                                    | ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out) 
                                                       >> 0xcU)));
    vlTOPp->wrapper__DOT__top_core__DOT__addr = ((2U 
                                                  & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__next_pc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__next_pc))
                                                   ? 
                                                  (vlTOPp->wrapper__DOT__top_core__DOT__I 
                                                   + vlTOPp->wrapper__DOT__top_core__DOT__reg_1)
                                                   : vlTOPp->wrapper__DOT__top_core__DOT__OUT_T)
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__next_pc))
                                                   ? vlTOPp->wrapper__DOT__top_core__DOT__UJ
                                                   : 
                                                  ((IData)(4U) 
                                                   + vlTOPp->wrapper__DOT__top_core__DOT__adr)));
    if ((0x800U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out))) {
        if ((0U == (7U & (vlTOPp->wrapper__DOT__o_rom_data 
                          >> 0xcU)))) {
            vlTOPp->wrapper__DOT__top_core__DOT__branch_p 
                = ((vlTOPp->wrapper__DOT__top_core__DOT__reg_1 
                    == vlTOPp->wrapper__DOT__top_core__DOT__reg_2)
                    ? 1U : 0U);
        } else {
            if ((1U == (7U & (vlTOPp->wrapper__DOT__o_rom_data 
                              >> 0xcU)))) {
                vlTOPp->wrapper__DOT__top_core__DOT__branch_p 
                    = ((vlTOPp->wrapper__DOT__top_core__DOT__reg_1 
                        != vlTOPp->wrapper__DOT__top_core__DOT__reg_2)
                        ? 1U : 0U);
            } else {
                if ((4U == (7U & (vlTOPp->wrapper__DOT__o_rom_data 
                                  >> 0xcU)))) {
                    vlTOPp->wrapper__DOT__top_core__DOT__branch_p 
                        = (VL_LTS_III(1,32,32, vlTOPp->wrapper__DOT__top_core__DOT__reg_1, vlTOPp->wrapper__DOT__top_core__DOT__reg_2)
                            ? 1U : 0U);
                } else {
                    if ((5U == (7U & (vlTOPp->wrapper__DOT__o_rom_data 
                                      >> 0xcU)))) {
                        vlTOPp->wrapper__DOT__top_core__DOT__branch_p 
                            = (VL_GTES_III(1,32,32, vlTOPp->wrapper__DOT__top_core__DOT__reg_1, vlTOPp->wrapper__DOT__top_core__DOT__reg_2)
                                ? 1U : 0U);
                    } else {
                        if ((6U == (7U & (vlTOPp->wrapper__DOT__o_rom_data 
                                          >> 0xcU)))) {
                            vlTOPp->wrapper__DOT__top_core__DOT__branch_p 
                                = ((vlTOPp->wrapper__DOT__top_core__DOT__reg_1 
                                    < vlTOPp->wrapper__DOT__top_core__DOT__reg_2)
                                    ? 1U : 0U);
                        } else {
                            if ((7U == (7U & (vlTOPp->wrapper__DOT__o_rom_data 
                                              >> 0xcU)))) {
                                vlTOPp->wrapper__DOT__top_core__DOT__branch_p 
                                    = ((vlTOPp->wrapper__DOT__top_core__DOT__reg_1 
                                        >= vlTOPp->wrapper__DOT__top_core__DOT__reg_2)
                                        ? 1U : 0U);
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->wrapper__DOT__top_core__DOT__ALU_OUTPUT 
        = ((0x20U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out))
            ? ((0x10U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out))
                ? ((8U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out))
                    ? ((4U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out))
                        ? vlTOPp->wrapper__DOT__top_core__DOT__reg_1
                        : 0U) : 0U) : ((8U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out))
                                        ? 0U : ((4U 
                                                 & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out))
                                                 ? 
                                                ((0x1fU 
                                                  >= vlTOPp->wrapper__DOT__top_core__DOT__reg_2)
                                                  ? 
                                                 (vlTOPp->wrapper__DOT__top_core__DOT__reg_1 
                                                  >> vlTOPp->wrapper__DOT__top_core__DOT__reg_2)
                                                  : 0U)
                                                 : 
                                                ((0xfffffffeU 
                                                  & vlTOPp->wrapper__DOT__top_core__DOT__ALU_OUTPUT) 
                                                 | (VL_LTS_III(1,32,32, vlTOPp->wrapper__DOT__top_core__DOT__reg_1, vlTOPp->wrapper__DOT__top_core__DOT__reg_2)
                                                     ? 1U
                                                     : 0U)))))
            : ((0x10U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out))
                ? ((8U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out))
                    ? ((4U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out))
                        ? ((0xfffffffeU & vlTOPp->wrapper__DOT__top_core__DOT__ALU_OUTPUT) 
                           | ((vlTOPp->wrapper__DOT__top_core__DOT__reg_1 
                               < vlTOPp->wrapper__DOT__top_core__DOT__reg_2)
                               ? 1U : 0U)) : ((0x1fU 
                                               >= vlTOPp->wrapper__DOT__top_core__DOT__reg_2)
                                               ? (vlTOPp->wrapper__DOT__top_core__DOT__reg_1 
                                                  >> vlTOPp->wrapper__DOT__top_core__DOT__reg_2)
                                               : 0U))
                    : ((4U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out))
                        ? ((0x1fU >= vlTOPp->wrapper__DOT__top_core__DOT__reg_2)
                            ? (vlTOPp->wrapper__DOT__top_core__DOT__reg_1 
                               << vlTOPp->wrapper__DOT__top_core__DOT__reg_2)
                            : 0U) : (vlTOPp->wrapper__DOT__top_core__DOT__reg_1 
                                     ^ vlTOPp->wrapper__DOT__top_core__DOT__reg_2)))
                : ((8U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out))
                    ? ((4U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out))
                        ? (vlTOPp->wrapper__DOT__top_core__DOT__reg_1 
                           | vlTOPp->wrapper__DOT__top_core__DOT__reg_2)
                        : (vlTOPp->wrapper__DOT__top_core__DOT__reg_1 
                           & vlTOPp->wrapper__DOT__top_core__DOT__reg_2))
                    : ((4U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out))
                        ? (vlTOPp->wrapper__DOT__top_core__DOT__reg_1 
                           - vlTOPp->wrapper__DOT__top_core__DOT__reg_2)
                        : (vlTOPp->wrapper__DOT__top_core__DOT__reg_1 
                           + vlTOPp->wrapper__DOT__top_core__DOT__reg_2)))));
    if ((1U & (~ (IData)(vlTOPp->clk)))) {
        if (vlTOPp->wrapper__DOT__arbiter__DOT__i_ack) {
            if ((0x1000U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out))) {
                vlTOPp->wrapper__DOT__st = 1U;
            }
        }
    }
    if (vlTOPp->clk) {
        vlTOPp->wrapper__DOT__st = 0U;
    }
    if ((1U & (~ (IData)(vlTOPp->clk)))) {
        if (vlTOPp->wrapper__DOT__arbiter__DOT__i_ack) {
            if ((0x1000U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out))) {
                vlTOPp->wrapper__DOT__o_rs2 = vlTOPp->wrapper__DOT__top_core__DOT__op2;
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->clk)))) {
        if (vlTOPp->wrapper__DOT__arbiter__DOT__i_ack) {
            if ((1U & (~ ((IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out) 
                          >> 0xcU)))) {
                vlTOPp->wrapper__DOT__o_ram_data = vlTOPp->wrapper__DOT__o_data;
            }
        }
    }
    if (vlTOPp->wrapper__DOT__top_core__DOT__branch_p) {
        if (vlTOPp->wrapper__DOT__top_core__DOT__branch_p) {
            vlTOPp->wrapper__DOT__top_core__DOT__OUT_T 
                = vlTOPp->wrapper__DOT__top_core__DOT__SB;
        }
    } else {
        vlTOPp->wrapper__DOT__top_core__DOT__OUT_T 
            = ((IData)(4U) + vlTOPp->wrapper__DOT__top_core__DOT__adr);
    }
    if ((1U & (~ (IData)(vlTOPp->clk)))) {
        if (vlTOPp->wrapper__DOT__arbiter__DOT__i_ack) {
            vlTOPp->wrapper__DOT__arbiter_addres = 
                (((IData)(vlTOPp->wrapper__DOT__arbiter__DOT__i_ack) 
                  << 0xcU) | (0xfffU & vlTOPp->wrapper__DOT__top_core__DOT__ALU_OUTPUT));
        }
    }
    if (vlTOPp->clk) {
        vlTOPp->wrapper__DOT__arbiter_addres = (0xfffU 
                                                & (vlTOPp->wrapper__DOT__top_core__DOT__adr 
                                                   >> 2U));
    }
    if ((0x2000U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out))) {
        if ((0x2000U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out))) {
            vlTOPp->wrapper__DOT__top_core__DOT__write_ba 
                = vlTOPp->wrapper__DOT__o_ram_data;
        }
    } else {
        vlTOPp->wrapper__DOT__top_core__DOT__write_ba 
            = vlTOPp->wrapper__DOT__top_core__DOT__ALU_OUTPUT;
    }
    if (vlTOPp->wrapper__DOT__st) {
        vlTOPp->wrapper__DOT__ram__DOT__mem[vlTOPp->wrapper__DOT__arbiter_addres] 
            = vlTOPp->wrapper__DOT__o_rs2;
    }
    if ((0x1000U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out))) {
        if ((0x1000U & (IData)(vlTOPp->wrapper__DOT__top_core__DOT__data_out))) {
            vlTOPp->wrapper__DOT__top_core__DOT__rite_ba = 0U;
        }
    } else {
        vlTOPp->wrapper__DOT__top_core__DOT__rite_ba 
            = vlTOPp->wrapper__DOT__top_core__DOT__write_ba;
    }
    vlTOPp->wrapper__DOT__o_data = vlTOPp->wrapper__DOT__ram__DOT__mem
        [vlTOPp->wrapper__DOT__arbiter_addres];
}

void Vwrapper::_eval(Vwrapper__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwrapper::_eval\n"); );
    Vwrapper* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_settle__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vwrapper::_eval_initial(Vwrapper__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwrapper::_eval_initial\n"); );
    Vwrapper* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vwrapper::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwrapper::final\n"); );
    // Variables
    Vwrapper__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vwrapper* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vwrapper::_eval_settle(Vwrapper__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwrapper::_eval_settle\n"); );
    Vwrapper* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

VL_INLINE_OPT QData Vwrapper::_change_request(Vwrapper__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwrapper::_change_request\n"); );
    Vwrapper* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->wrapper__DOT__o_data ^ vlTOPp->__Vchglast__TOP__wrapper__DOT__o_data)
         | (vlTOPp->wrapper__DOT__top_core__DOT__OUT_T ^ vlTOPp->__Vchglast__TOP__wrapper__DOT__top_core__DOT__OUT_T));
    VL_DEBUG_IF( if(__req && ((vlTOPp->wrapper__DOT__o_data ^ vlTOPp->__Vchglast__TOP__wrapper__DOT__o_data))) VL_DBG_MSGF("        CHANGE: ../src/rv_1.0.1/rtl/wrapper.v:13: wrapper.o_data\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->wrapper__DOT__top_core__DOT__OUT_T ^ vlTOPp->__Vchglast__TOP__wrapper__DOT__top_core__DOT__OUT_T))) VL_DBG_MSGF("        CHANGE: ../src/rv_1.0.1/rtl/top.v:47: wrapper.top_core.OUT_T\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__wrapper__DOT__o_data = vlTOPp->wrapper__DOT__o_data;
    vlTOPp->__Vchglast__TOP__wrapper__DOT__top_core__DOT__OUT_T 
        = vlTOPp->wrapper__DOT__top_core__DOT__OUT_T;
    return __req;
}

#ifdef VL_DEBUG
void Vwrapper::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwrapper::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG

void Vwrapper::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwrapper::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    wrapper__DOT__o_dram = VL_RAND_RESET_I(32);
    wrapper__DOT__o_iram = VL_RAND_RESET_I(32);
    wrapper__DOT__o_data = VL_RAND_RESET_I(32);
    wrapper__DOT__o_ar_data = VL_RAND_RESET_I(32);
    wrapper__DOT__arbiter_addres = VL_RAND_RESET_I(13);
    wrapper__DOT__o_ram_data = VL_RAND_RESET_I(32);
    wrapper__DOT__o_rom_data = VL_RAND_RESET_I(32);
    wrapper__DOT__o_rs2 = VL_RAND_RESET_I(32);
    wrapper__DOT__st = VL_RAND_RESET_I(1);
    wrapper__DOT__top_core__DOT__data_out = VL_RAND_RESET_I(15);
    wrapper__DOT__top_core__DOT__branch_p = VL_RAND_RESET_I(1);
    wrapper__DOT__top_core__DOT__OUT_T = VL_RAND_RESET_I(32);
    wrapper__DOT__top_core__DOT__addr = VL_RAND_RESET_I(32);
    wrapper__DOT__top_core__DOT__adr = VL_RAND_RESET_I(32);
    wrapper__DOT__top_core__DOT__b = VL_RAND_RESET_I(32);
    wrapper__DOT__top_core__DOT__I = VL_RAND_RESET_I(32);
    wrapper__DOT__top_core__DOT__S = VL_RAND_RESET_I(32);
    wrapper__DOT__top_core__DOT__SB = VL_RAND_RESET_I(32);
    wrapper__DOT__top_core__DOT__UJ = VL_RAND_RESET_I(32);
    wrapper__DOT__top_core__DOT__U = VL_RAND_RESET_I(32);
    wrapper__DOT__top_core__DOT__op2 = VL_RAND_RESET_I(32);
    wrapper__DOT__top_core__DOT__faltu = VL_RAND_RESET_I(32);
    wrapper__DOT__top_core__DOT__reg_1 = VL_RAND_RESET_I(32);
    wrapper__DOT__top_core__DOT__reg_2 = VL_RAND_RESET_I(32);
    wrapper__DOT__top_core__DOT__ALU_OUTPUT = VL_RAND_RESET_I(32);
    wrapper__DOT__top_core__DOT__write_adder = VL_RAND_RESET_I(32);
    wrapper__DOT__top_core__DOT__write_ba = VL_RAND_RESET_I(32);
    wrapper__DOT__top_core__DOT__rite_ba = VL_RAND_RESET_I(32);
    wrapper__DOT__top_core__DOT__rb1 = VL_RAND_RESET_I(32);
    wrapper__DOT__top_core__DOT__c = VL_RAND_RESET_I(9);
    wrapper__DOT__top_core__DOT__re = VL_RAND_RESET_I(5);
    wrapper__DOT__top_core__DOT__ac = VL_RAND_RESET_I(32);
    wrapper__DOT__top_core__DOT__next_pc = VL_RAND_RESET_I(2);
    wrapper__DOT__top_core__DOT__control__DOT__b = VL_RAND_RESET_I(25);
    wrapper__DOT__top_core__DOT__unit__DOT__d = VL_RAND_RESET_I(3);
    wrapper__DOT__top_core__DOT__reg_file__DOT__i = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
            wrapper__DOT__top_core__DOT__reg_file__DOT__reg_file1[__Vi0] = VL_RAND_RESET_I(32);
    }}
    wrapper__DOT__top_core__DOT__immediate__DOT__II = VL_RAND_RESET_I(12);
    wrapper__DOT__top_core__DOT__immediate__DOT__SS = VL_RAND_RESET_I(12);
    wrapper__DOT__top_core__DOT__immediate__DOT__az = VL_RAND_RESET_I(12);
    wrapper__DOT__top_core__DOT__immediate__DOT__ay = VL_RAND_RESET_I(21);
    wrapper__DOT__top_core__DOT__immediate__DOT__ax = VL_RAND_RESET_I(32);
    wrapper__DOT__arbiter__DOT__i_ack = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<8192; ++__Vi0) {
            wrapper__DOT__ram__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    __Vtableidx1 = 0;
    __Vtable1_wrapper__DOT__top_core__DOT__c[0] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[1] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[2] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[3] = 0x40U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[4] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[5] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[6] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[7] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[8] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[9] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[10] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[11] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[12] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[13] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[14] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[15] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[16] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[17] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[18] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[19] = 0x80U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[20] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[21] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[22] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[23] = 1U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[24] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[25] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[26] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[27] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[28] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[29] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[30] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[31] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[32] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[33] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[34] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[35] = 0x20U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[36] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[37] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[38] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[39] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[40] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[41] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[42] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[43] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[44] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[45] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[46] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[47] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[48] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[49] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[50] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[51] = 0x100U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[52] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[53] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[54] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[55] = 2U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[56] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[57] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[58] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[59] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[60] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[61] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[62] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[63] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[64] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[65] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[66] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[67] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[68] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[69] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[70] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[71] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[72] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[73] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[74] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[75] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[76] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[77] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[78] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[79] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[80] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[81] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[82] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[83] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[84] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[85] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[86] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[87] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[88] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[89] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[90] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[91] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[92] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[93] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[94] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[95] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[96] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[97] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[98] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[99] = 0x10U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[100] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[101] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[102] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[103] = 4U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[104] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[105] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[106] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[107] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[108] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[109] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[110] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[111] = 8U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[112] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[113] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[114] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[115] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[116] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[117] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[118] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[119] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[120] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[121] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[122] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[123] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[124] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[125] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[126] = 0U;
    __Vtable1_wrapper__DOT__top_core__DOT__c[127] = 0U;
    __Vchglast__TOP__wrapper__DOT__o_data = VL_RAND_RESET_I(32);
    __Vchglast__TOP__wrapper__DOT__top_core__DOT__OUT_T = VL_RAND_RESET_I(32);
    __Vm_traceActivity = 0;
}
