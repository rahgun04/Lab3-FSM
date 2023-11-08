// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__0\n"); );
    // Init
    SData/*15:0*/ __Vdly__top__DOT__oneSec__DOT__count;
    CData/*7:0*/ __Vdly__top__DOT__lights__DOT__sreg;
    // Body
    __Vdly__top__DOT__oneSec__DOT__count = vlSelf->top__DOT__oneSec__DOT__count;
    __Vdly__top__DOT__lights__DOT__sreg = vlSelf->top__DOT__lights__DOT__sreg;
    if (vlSelf->rst) {
        __Vdly__top__DOT__lights__DOT__sreg = 1U;
        vlSelf->top__DOT__tick = 0U;
        __Vdly__top__DOT__oneSec__DOT__count = vlSelf->N;
    } else {
        if (vlSelf->top__DOT__tick) {
            __Vdly__top__DOT__lights__DOT__sreg = (
                                                   (0xffU 
                                                    == (IData)(vlSelf->top__DOT__lights__DOT__sreg))
                                                    ? 0U
                                                    : 
                                                   (0xffU 
                                                    & (1U 
                                                       | ((IData)(vlSelf->top__DOT__lights__DOT__sreg) 
                                                          << 1U))));
        }
        if (vlSelf->en) {
            if ((0U == (IData)(vlSelf->top__DOT__oneSec__DOT__count))) {
                vlSelf->top__DOT__tick = 1U;
                __Vdly__top__DOT__oneSec__DOT__count 
                    = vlSelf->N;
            } else {
                __Vdly__top__DOT__oneSec__DOT__count 
                    = (0xffffU & ((IData)(vlSelf->top__DOT__oneSec__DOT__count) 
                                  - (IData)(1U)));
                vlSelf->top__DOT__tick = 0U;
            }
        }
    }
    vlSelf->top__DOT__lights__DOT__sreg = __Vdly__top__DOT__lights__DOT__sreg;
    vlSelf->data_out = vlSelf->top__DOT__lights__DOT__sreg;
    vlSelf->top__DOT__oneSec__DOT__count = __Vdly__top__DOT__oneSec__DOT__count;
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Body
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->rst) & (~ (IData)(vlSelf->__Vclklast__TOP__rst))))) {
        Vtop___024root___sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG
