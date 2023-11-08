// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfsm.h for the primary calling header

#include "verilated.h"

#include "Vfsm___024root.h"

VL_INLINE_OPT void Vfsm___024root___sequent__TOP__0(Vfsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsm___024root___sequent__TOP__0\n"); );
    // Init
    CData/*7:0*/ __Vdly__lfsr7__DOT__sreg;
    // Body
    __Vdly__lfsr7__DOT__sreg = vlSelf->lfsr7__DOT__sreg;
    if (vlSelf->rst) {
        __Vdly__lfsr7__DOT__sreg = 1U;
    } else if (vlSelf->en) {
        __Vdly__lfsr7__DOT__sreg = ((0xffU == (IData)(vlSelf->lfsr7__DOT__sreg))
                                     ? 0U : (0xffU 
                                             & (1U 
                                                | ((IData)(vlSelf->lfsr7__DOT__sreg) 
                                                   << 1U))));
    }
    vlSelf->lfsr7__DOT__sreg = __Vdly__lfsr7__DOT__sreg;
    vlSelf->data_out = vlSelf->lfsr7__DOT__sreg;
}

void Vfsm___024root___eval(Vfsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsm___024root___eval\n"); );
    // Body
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->rst) & (~ (IData)(vlSelf->__Vclklast__TOP__rst))))) {
        Vfsm___024root___sequent__TOP__0(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
}

#ifdef VL_DEBUG
void Vfsm___024root___eval_debug_assertions(Vfsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsm___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
}
#endif  // VL_DEBUG
