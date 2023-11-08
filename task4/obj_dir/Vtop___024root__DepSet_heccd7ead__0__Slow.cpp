// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___initial__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___initial__TOP__0\n"); );
    // Body
    vlSelf->top__DOT__del__DOT__count = 0U;
}

VL_ATTR_COLD void Vtop___024root___settle__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___settle__TOP__0\n"); );
    // Body
    vlSelf->data_out = vlSelf->top__DOT__lights__DOT__sreg;
    vlSelf->top__DOT____Vcellinp__lights__en = ((IData)(vlSelf->top__DOT__cmd_seq)
                                                 ? (IData)(vlSelf->top__DOT__tick)
                                                 : 
                                                ((0U 
                                                  != vlSelf->top__DOT__del__DOT__current_state) 
                                                 & ((1U 
                                                     != vlSelf->top__DOT__del__DOT__current_state) 
                                                    & (2U 
                                                       == vlSelf->top__DOT__del__DOT__current_state))));
    vlSelf->top__DOT__del__DOT__next_state = ((0U == vlSelf->top__DOT__del__DOT__current_state)
                                               ? ((IData)(vlSelf->top__DOT__cmd_delay)
                                                   ? 1U
                                                   : vlSelf->top__DOT__del__DOT__current_state)
                                               : ((1U 
                                                   == vlSelf->top__DOT__del__DOT__current_state)
                                                   ? 
                                                  ((0U 
                                                    == (IData)(vlSelf->top__DOT__del__DOT__count))
                                                    ? 2U
                                                    : vlSelf->top__DOT__del__DOT__current_state)
                                                   : 
                                                  ((2U 
                                                    == vlSelf->top__DOT__del__DOT__current_state)
                                                    ? 
                                                   ((IData)(vlSelf->top__DOT__cmd_delay)
                                                     ? 3U
                                                     : 0U)
                                                    : 
                                                   ((3U 
                                                     == vlSelf->top__DOT__del__DOT__current_state)
                                                     ? 
                                                    ((IData)(vlSelf->top__DOT__cmd_delay)
                                                      ? vlSelf->top__DOT__del__DOT__current_state
                                                      : 0U)
                                                     : 0U))));
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
    vlSelf->__Vclklast__TOP__trigger = vlSelf->trigger;
    Vtop___024root___initial__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    // Body
    Vtop___024root___settle__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vtop___024root___final(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___final\n"); );
}

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->data_out = VL_RAND_RESET_I(8);
    vlSelf->en = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->N = VL_RAND_RESET_I(16);
    vlSelf->trigger = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__cmd_seq = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__cmd_delay = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__tick = VL_RAND_RESET_I(1);
    vlSelf->top__DOT____Vcellinp__lights__en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__oneSec__DOT__count = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__lfsr__DOT__sreg = VL_RAND_RESET_I(7);
    vlSelf->top__DOT__del__DOT__count = VL_RAND_RESET_I(7);
    vlSelf->top__DOT__del__DOT__current_state = 0;
    vlSelf->top__DOT__del__DOT__next_state = 0;
    vlSelf->top__DOT__lights__DOT__sreg = VL_RAND_RESET_I(8);
    vlSelf->__Vdly__top__DOT__lfsr__DOT__sreg = VL_RAND_RESET_I(7);
    vlSelf->__Vdly__top__DOT__lights__DOT__sreg = VL_RAND_RESET_I(8);
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
