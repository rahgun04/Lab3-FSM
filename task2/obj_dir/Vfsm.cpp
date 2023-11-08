// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vfsm.h"
#include "Vfsm__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vfsm::Vfsm(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vfsm__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , en{vlSymsp->TOP.en}
    , data_out{vlSymsp->TOP.data_out}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vfsm::Vfsm(const char* _vcname__)
    : Vfsm(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vfsm::~Vfsm() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vfsm___024root___eval_initial(Vfsm___024root* vlSelf);
void Vfsm___024root___eval_settle(Vfsm___024root* vlSelf);
void Vfsm___024root___eval(Vfsm___024root* vlSelf);
#ifdef VL_DEBUG
void Vfsm___024root___eval_debug_assertions(Vfsm___024root* vlSelf);
#endif  // VL_DEBUG
void Vfsm___024root___final(Vfsm___024root* vlSelf);

static void _eval_initial_loop(Vfsm__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vfsm___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vfsm___024root___eval_settle(&(vlSymsp->TOP));
        Vfsm___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vfsm::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vfsm::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vfsm___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vfsm___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vfsm::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vfsm::final() {
    Vfsm___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vfsm::hierName() const { return vlSymsp->name(); }
const char* Vfsm::modelName() const { return "Vfsm"; }
unsigned Vfsm::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vfsm::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vfsm___024root__trace_init_top(Vfsm___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vfsm___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfsm___024root*>(voidSelf);
    Vfsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vfsm___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vfsm___024root__trace_register(Vfsm___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vfsm::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vfsm___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
