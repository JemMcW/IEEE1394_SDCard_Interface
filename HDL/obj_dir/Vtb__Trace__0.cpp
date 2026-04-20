// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtb__Syms.h"


void Vtb___024root__trace_chg_0_sub_0(Vtb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_chg_0\n"); );
    // Body
    Vtb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb___024root*>(voidSelf);
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtb___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb___024root__trace_chg_0_sub_0(Vtb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_chg_0_sub_0\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgCData(oldp+0,((((IData)(vlSelfRef.tb__DOT__uut__DOT____Vcellout__b__led3) 
                                 << 2U) | (((IData)(vlSelfRef.tb__DOT__uut__DOT____Vcellout__b__led2) 
                                            << 1U) 
                                           | (IData)(vlSelfRef.tb__DOT__uut__DOT____Vcellout__b__led1)))),3);
        bufp->chgBit(oldp+1,(vlSelfRef.tb__DOT__uut__DOT____Vcellout__b__led1));
        bufp->chgBit(oldp+2,(vlSelfRef.tb__DOT__uut__DOT____Vcellout__b__led2));
        bufp->chgBit(oldp+3,(vlSelfRef.tb__DOT__uut__DOT____Vcellout__b__led3));
        bufp->chgIData(oldp+4,(vlSelfRef.tb__DOT__uut__DOT__b__DOT__counter),28);
        bufp->chgCData(oldp+5,(vlSelfRef.tb__DOT__uut__DOT__b__DOT__outcnt),3);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+6,(vlSelfRef.tb__DOT__hf_t));
        bufp->chgBit(oldp+7,(vlSelfRef.tb__DOT__uut__DOT__dv_data_available));
        bufp->chgCData(oldp+8,(vlSelfRef.tb__DOT__uut__DOT__dv_rx_data),4);
        bufp->chgBit(oldp+9,(vlSelfRef.tb__DOT__uut__DOT__dv__DOT__status_state_reg));
        bufp->chgSData(oldp+10,(vlSelfRef.tb__DOT__uut__DOT__fifo__DOT__write_addr),12);
        bufp->chgBit(oldp+11,(vlSelfRef.tb__DOT__uut__DOT__fifo__DOT__write_addr_2nd_msb));
        bufp->chgBit(oldp+12,(((1U & ((IData)(vlSelfRef.tb__DOT__uut__DOT__fifo__DOT__write_addr) 
                                      >> 0x0000000aU)) 
                               != (IData)(vlSelfRef.tb__DOT__uut__DOT__fifo__DOT__write_addr_2nd_msb))));
        bufp->chgCData(oldp+13,(vlSelfRef.tb__DOT__uut__DOT__fifo__DOT__pulseCounter),4);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[3U]))) {
        bufp->chgBit(oldp+14,(vlSelfRef.tb__DOT__uut__DOT__firewire__DOT__receiving_data));
        bufp->chgCData(oldp+15,(vlSelfRef.tb__DOT__uut__DOT__dv__DOT__headerNybbleCounter),5);
        bufp->chgCData(oldp+16,(vlSelfRef.tb__DOT__uut__DOT__dv__DOT__firstEightByteIgnoreCounter),5);
        bufp->chgIData(oldp+17,(vlSelfRef.tb__DOT__uut__DOT__dv__DOT__dataNybbleCounter),17);
        bufp->chgBit(oldp+18,(vlSelfRef.tb__DOT__uut__DOT__dv__DOT__ignore));
    }
    bufp->chgBit(oldp+19,(vlSelfRef.tb__DOT__clk));
    bufp->chgBit(oldp+20,(vlSelfRef.tb__DOT__cs));
    bufp->chgBit(oldp+21,(vlSelfRef.tb__DOT__phy_clk_t));
    bufp->chgCData(oldp+22,(vlSelfRef.tb__DOT__ctl_t),2);
    bufp->chgCData(oldp+23,(vlSelfRef.tb__DOT__phy_data_t),2);
    bufp->chgBit(oldp+24,(vlSelfRef.tb__DOT__first_read_t));
    bufp->chgCData(oldp+25,(((((1U == (IData)(vlSelfRef.tb__DOT__uut__DOT__quad_spi__DOT__qspi_state))
                                ? 0x0fU : 0U) & (((1U 
                                                   == (IData)(vlSelfRef.tb__DOT__uut__DOT__quad_spi__DOT__qspi_state))
                                                   ? (IData)(vlSelfRef.tb__DOT__uut__DOT__qspi_tx_data)
                                                   : 0U) 
                                                 & ((1U 
                                                     == (IData)(vlSelfRef.tb__DOT__uut__DOT__quad_spi__DOT__qspi_state))
                                                     ? 0x0fU
                                                     : 0U))) 
                             & ((1U == (IData)(vlSelfRef.tb__DOT__uut__DOT__quad_spi__DOT__qspi_state))
                                 ? 0x0fU : 0U))),4);
    bufp->chgCData(oldp+26,((((IData)(vlSelfRef.tb__DOT__phy_data_pad_t) 
                              << 2U) | (IData)(vlSelfRef.tb__DOT__phy_data_t))),8);
    bufp->chgBit(oldp+27,((0U != (IData)(vlSelfRef.tb__DOT__uut__DOT__quad_spi__DOT__qspi_state))));
    bufp->chgCData(oldp+28,(vlSelfRef.tb__DOT__uut__DOT__qspi_tx_data),4);
    bufp->chgBit(oldp+29,(vlSelfRef.tb__DOT__uut__DOT__phy_data_available));
    bufp->chgCData(oldp+30,(vlSelfRef.tb__DOT__uut__DOT__phy_rx_data),4);
    bufp->chgBit(oldp+31,((2U == (IData)(vlSelfRef.tb__DOT__ctl_t))));
    bufp->chgSData(oldp+32,(vlSelfRef.tb__DOT__uut__DOT__fifo__DOT__read_addr),12);
    bufp->chgIData(oldp+33,(vlSelfRef.tb__DOT__uut__DOT__fifo__DOT__i),32);
    bufp->chgCData(oldp+34,(vlSelfRef.tb__DOT__uut__DOT__firewire__DOT__data_shift),4);
    bufp->chgBit(oldp+35,(vlSelfRef.tb__DOT__uut__DOT__firewire__DOT__data_strobe_temp));
    bufp->chgCData(oldp+36,(vlSelfRef.tb__DOT__uut__DOT__quad_spi__DOT__qspi_state),2);
}

void Vtb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_cleanup\n"); );
    // Body
    Vtb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb___024root*>(voidSelf);
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
