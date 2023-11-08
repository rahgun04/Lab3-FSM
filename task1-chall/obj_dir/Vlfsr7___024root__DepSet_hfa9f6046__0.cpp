// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vlfsr7.h for the primary calling header

#include "verilated.h"

#include "Vlfsr7___024root.h"

extern const VlUnpacked<CData/*6:0*/, 512> Vlfsr7__ConstPool__TABLE_h1a19c207_0;

VL_INLINE_OPT void Vlfsr7___024root___sequent__TOP__0(Vlfsr7___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlfsr7__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr7___024root___sequent__TOP__0\n"); );
    // Init
    SData/*8:0*/ __Vtableidx1;
    // Body
    __Vtableidx1 = (((IData)(vlSelf->lfsr7__DOT__sreg) 
                     << 2U) | (((IData)(vlSelf->en) 
                                << 1U) | (IData)(vlSelf->rst)));
    vlSelf->lfsr7__DOT__sreg = Vlfsr7__ConstPool__TABLE_h1a19c207_0
        [__Vtableidx1];
    vlSelf->data_out = vlSelf->lfsr7__DOT__sreg;
}

void Vlfsr7___024root___eval(Vlfsr7___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlfsr7__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr7___024root___eval\n"); );
    // Body
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->rst) & (~ (IData)(vlSelf->__Vclklast__TOP__rst))))) {
        Vlfsr7___024root___sequent__TOP__0(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
}

#ifdef VL_DEBUG
void Vlfsr7___024root___eval_debug_assertions(Vlfsr7___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlfsr7__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr7___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
}
#endif  // VL_DEBUG
