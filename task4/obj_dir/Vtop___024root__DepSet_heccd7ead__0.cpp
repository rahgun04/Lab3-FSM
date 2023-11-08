// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__0\n"); );
    // Body
    vlSelf->__Vdly__top__DOT__lfsr__DOT__sreg = vlSelf->top__DOT__lfsr__DOT__sreg;
    vlSelf->__Vdly__top__DOT__lights__DOT__sreg = vlSelf->top__DOT__lights__DOT__sreg;
    vlSelf->__Vdly__top__DOT__lfsr__DOT__sreg = ((IData)(vlSelf->rst)
                                                  ? 1U
                                                  : 
                                                 ((IData)(vlSelf->en)
                                                   ? 
                                                  ((0x7eU 
                                                    & ((IData)(vlSelf->top__DOT__lfsr__DOT__sreg) 
                                                       << 1U)) 
                                                   | (1U 
                                                      & VL_REDXOR_8(
                                                                    (0x44U 
                                                                     & (IData)(vlSelf->top__DOT__lfsr__DOT__sreg)))))
                                                   : (IData)(vlSelf->top__DOT__lfsr__DOT__sreg)));
}

VL_INLINE_OPT void Vtop___024root___sequent__TOP__2(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__2\n"); );
    // Init
    SData/*15:0*/ __Vdly__top__DOT__oneSec__DOT__count;
    // Body
    __Vdly__top__DOT__oneSec__DOT__count = vlSelf->top__DOT__oneSec__DOT__count;
    if (vlSelf->rst) {
        vlSelf->top__DOT__del__DOT__current_state = 0U;
        vlSelf->top__DOT__tick = 0U;
        __Vdly__top__DOT__oneSec__DOT__count = vlSelf->N;
    } else {
        vlSelf->top__DOT__del__DOT__current_state = vlSelf->top__DOT__del__DOT__next_state;
        if (vlSelf->top__DOT__cmd_seq) {
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
    vlSelf->top__DOT__del__DOT__count = (0x7fU & ((
                                                   ((IData)(vlSelf->rst) 
                                                    | (IData)(vlSelf->top__DOT__cmd_delay)) 
                                                   | (0U 
                                                      == (IData)(vlSelf->top__DOT__del__DOT__count)))
                                                   ? 
                                                  ((IData)(vlSelf->top__DOT__lfsr__DOT__sreg) 
                                                   - (IData)(1U))
                                                   : 
                                                  ((IData)(vlSelf->top__DOT__del__DOT__count) 
                                                   - (IData)(1U))));
    vlSelf->top__DOT__oneSec__DOT__count = __Vdly__top__DOT__oneSec__DOT__count;
}

VL_INLINE_OPT void Vtop___024root___sequent__TOP__4(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__4\n"); );
    // Body
    vlSelf->top__DOT__lfsr__DOT__sreg = vlSelf->__Vdly__top__DOT__lfsr__DOT__sreg;
    if (vlSelf->rst) {
        vlSelf->__Vdly__top__DOT__lights__DOT__sreg = 1U;
    } else if (vlSelf->top__DOT____Vcellinp__lights__en) {
        if ((0xffU == (IData)(vlSelf->top__DOT__lights__DOT__sreg))) {
            vlSelf->top__DOT__cmd_seq = 0U;
            vlSelf->top__DOT__cmd_delay = 0U;
            vlSelf->__Vdly__top__DOT__lights__DOT__sreg = 0U;
        } else if ((0x7fU == (IData)(vlSelf->top__DOT__lights__DOT__sreg))) {
            vlSelf->__Vdly__top__DOT__lights__DOT__sreg 
                = (0xffU & (1U | ((IData)(vlSelf->top__DOT__lights__DOT__sreg) 
                                  << 1U)));
            vlSelf->top__DOT__cmd_seq = 0U;
            vlSelf->top__DOT__cmd_delay = 1U;
        } else {
            vlSelf->__Vdly__top__DOT__lights__DOT__sreg 
                = (0xffU & (1U | ((IData)(vlSelf->top__DOT__lights__DOT__sreg) 
                                  << 1U)));
        }
    }
    vlSelf->top__DOT__lights__DOT__sreg = vlSelf->__Vdly__top__DOT__lights__DOT__sreg;
    vlSelf->data_out = vlSelf->top__DOT__lights__DOT__sreg;
}

VL_INLINE_OPT void Vtop___024root___sequent__TOP__5(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__5\n"); );
    // Body
    vlSelf->top__DOT__cmd_delay = 0U;
    vlSelf->top__DOT__cmd_seq = 1U;
}

VL_INLINE_OPT void Vtop___024root___sequent__TOP__6(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__6\n"); );
    // Body
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
    vlSelf->top__DOT____Vcellinp__lights__en = ((IData)(vlSelf->top__DOT__cmd_seq)
                                                 ? (IData)(vlSelf->top__DOT__tick)
                                                 : 
                                                ((0U 
                                                  != vlSelf->top__DOT__del__DOT__current_state) 
                                                 & ((1U 
                                                     != vlSelf->top__DOT__del__DOT__current_state) 
                                                    & (2U 
                                                       == vlSelf->top__DOT__del__DOT__current_state))));
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Body
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->rst) & (~ (IData)(vlSelf->__Vclklast__TOP__rst))))) {
        Vtop___024root___sequent__TOP__0(vlSelf);
    }
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vtop___024root___sequent__TOP__2(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->rst) & (~ (IData)(vlSelf->__Vclklast__TOP__rst))))) {
        Vtop___024root___sequent__TOP__4(vlSelf);
    }
    if (((IData)(vlSelf->trigger) & (~ (IData)(vlSelf->__Vclklast__TOP__trigger)))) {
        Vtop___024root___sequent__TOP__5(vlSelf);
    }
    if (((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
          | ((IData)(vlSelf->rst) & (~ (IData)(vlSelf->__Vclklast__TOP__rst)))) 
         | ((IData)(vlSelf->trigger) & (~ (IData)(vlSelf->__Vclklast__TOP__trigger))))) {
        Vtop___024root___sequent__TOP__6(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
    vlSelf->__Vclklast__TOP__trigger = vlSelf->trigger;
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
    if (VL_UNLIKELY((vlSelf->trigger & 0xfeU))) {
        Verilated::overWidthError("trigger");}
}
#endif  // VL_DEBUG
