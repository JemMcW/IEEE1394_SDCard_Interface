// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb.h for the primary calling header

#ifndef VERILATED_VTB___024ROOT_H_
#define VERILATED_VTB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb___024root final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb__DOT__clk;
    CData/*0:0*/ tb__DOT__cs;
    CData/*0:0*/ tb__DOT__phy_clk_t;
    CData/*1:0*/ tb__DOT__ctl_t;
    CData/*1:0*/ tb__DOT__phy_data_t;
    CData/*0:0*/ tb__DOT__empty_t;
    CData/*0:0*/ tb__DOT__hf_t;
    CData/*5:0*/ tb__DOT__phy_data_pad_t;
    CData/*0:0*/ tb__DOT__first_read_t;
    CData/*3:0*/ tb__DOT__uut__DOT__qspi_tx_data;
    CData/*0:0*/ tb__DOT__uut__DOT____Vcellout__b__led3;
    CData/*0:0*/ tb__DOT__uut__DOT____Vcellout__b__led2;
    CData/*0:0*/ tb__DOT__uut__DOT____Vcellout__b__led1;
    CData/*0:0*/ tb__DOT__uut__DOT__phy_data_available;
    CData/*0:0*/ tb__DOT__uut__DOT__dv_data_available;
    CData/*3:0*/ tb__DOT__uut__DOT__phy_rx_data;
    CData/*3:0*/ tb__DOT__uut__DOT__dv_rx_data;
    CData/*2:0*/ tb__DOT__uut__DOT__b__DOT__outcnt;
    CData/*1:0*/ tb__DOT__uut__DOT__quad_spi__DOT__qspi_state;
    CData/*3:0*/ tb__DOT__uut__DOT__firewire__DOT__data_shift;
    CData/*0:0*/ tb__DOT__uut__DOT__firewire__DOT__data_strobe_temp;
    CData/*0:0*/ tb__DOT__uut__DOT__firewire__DOT__receiving_data;
    CData/*4:0*/ tb__DOT__uut__DOT__dv__DOT__headerNybbleCounter;
    CData/*4:0*/ tb__DOT__uut__DOT__dv__DOT__firstEightByteIgnoreCounter;
    CData/*0:0*/ tb__DOT__uut__DOT__dv__DOT__status_state_reg;
    CData/*0:0*/ tb__DOT__uut__DOT__dv__DOT__ignore;
    CData/*0:0*/ tb__DOT__uut__DOT__fifo__DOT__write_addr_2nd_msb;
    CData/*3:0*/ tb__DOT__uut__DOT__fifo__DOT__pulseCounter;
    CData/*1:0*/ __Vdly__tb__DOT__uut__DOT__quad_spi__DOT__qspi_state;
    CData/*0:0*/ __Vdly__tb__DOT__uut__DOT__firewire__DOT__data_strobe_temp;
    CData/*0:0*/ __Vdly__tb__DOT__uut__DOT__firewire__DOT__receiving_data;
    CData/*4:0*/ __Vdly__tb__DOT__uut__DOT__dv__DOT__headerNybbleCounter;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VstlPhaseResult;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb__DOT__phy_clk_t__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb__DOT__cs__0;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VinactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    SData/*11:0*/ tb__DOT__uut__DOT__fifo__DOT__write_addr;
    SData/*11:0*/ tb__DOT__uut__DOT__fifo__DOT__read_addr;
    IData/*31:0*/ tb__DOT__i;
    IData/*27:0*/ tb__DOT__uut__DOT__b__DOT__counter;
    IData/*16:0*/ tb__DOT__uut__DOT__dv__DOT__dataNybbleCounter;
    IData/*31:0*/ tb__DOT__uut__DOT__fifo__DOT__i;
    IData/*16:0*/ __Vdly__tb__DOT__uut__DOT__dv__DOT__dataNybbleCounter;
    IData/*31:0*/ __VactIterCount;
    IData/*31:0*/ __VinactIterCount;
    IData/*31:0*/ __Vi;
    VlUnpacked<CData/*3:0*/, 2048> tb__DOT__uut__DOT__fifo__DOT__memory;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggeredAcc;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;

    // INTERNAL VARIABLES
    Vtb__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtb___024root(Vtb__Syms* symsp, const char* namep);
    ~Vtb___024root();
    VL_UNCOPYABLE(Vtb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
