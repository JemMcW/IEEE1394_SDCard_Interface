// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"

VL_ATTR_COLD void Vtb___024root___eval_initial__TOP(Vtb___024root* vlSelf);
VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__0(Vtb___024root* vlSelf);
VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__1(Vtb___024root* vlSelf);
VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__2(Vtb___024root* vlSelf);
VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__3(Vtb___024root* vlSelf);

void Vtb___024root___eval_initial(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb___024root___eval_initial__TOP(vlSelf);
    Vtb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vtb___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    Vtb___024root___eval_initial__TOP__Vtiming__3(vlSelf);
}

VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__0(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__clk = 0U;
    vlSelfRef.tb__DOT__cs = 0U;
    vlSelfRef.tb__DOT__first_read_t = 1U;
    while (true) {
        co_await vlSelfRef.__VdlySched.delay(0x0000000000002710ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             49);
        vlSelfRef.tb__DOT__clk = (1U & (~ (IData)(vlSelfRef.tb__DOT__clk)));
    }
    co_return;
}

VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__1(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__phy_clk_t = 0U;
    while (true) {
        co_await vlSelfRef.__VdlySched.delay(0x0000000000002710ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             62);
        vlSelfRef.tb__DOT__phy_clk_t = (1U & (~ (IData)(vlSelfRef.tb__DOT__phy_clk_t)));
    }
    co_return;
}

VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__2(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP__Vtiming__2\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__ctl_t = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000002710ULL, 
                                         nullptr, "testbench/tb.v", 
                                         71);
    while (true) {
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             77);
        vlSelfRef.tb__DOT__ctl_t = 1U;
        vlSelfRef.tb__DOT__phy_data_t = 3U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000013880ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             78);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             81);
        vlSelfRef.tb__DOT__phy_data_t = 3U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             82);
        vlSelfRef.tb__DOT__phy_data_t = 3U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             83);
        vlSelfRef.tb__DOT__phy_data_t = 3U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             84);
        vlSelfRef.tb__DOT__phy_data_t = 3U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             85);
        vlSelfRef.tb__DOT__phy_data_t = 3U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             86);
        vlSelfRef.tb__DOT__phy_data_t = 3U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             87);
        vlSelfRef.tb__DOT__phy_data_t = 3U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             88);
        vlSelfRef.tb__DOT__phy_data_t = 3U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000075300ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             91);
        co_await vlSelfRef.__VdlySched.delay(0x000000000004e200ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             94);
        vlSelfRef.tb__DOT__phy_data_t = 2U;
        co_await vlSelfRef.__VdlySched.delay(0x000000000004e200ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             97);
        vlSelfRef.tb__DOT__ctl_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000030d40ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             101);
        vlSelfRef.tb__DOT__ctl_t = 1U;
        vlSelfRef.tb__DOT__phy_data_t = 3U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000013880ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             103);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             106);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             107);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             108);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             109);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             111);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             112);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             113);
        vlSelfRef.tb__DOT__phy_data_t = 3U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             114);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000075300ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             117);
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             120);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             121);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             122);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             123);
        vlSelfRef.tb__DOT__phy_data_t = 2U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             125);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             126);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             127);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             128);
        vlSelfRef.tb__DOT__phy_data_t = 1U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             130);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             131);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             132);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             133);
        vlSelfRef.tb__DOT__phy_data_t = 3U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             135);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             136);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             137);
        vlSelfRef.tb__DOT__phy_data_t = 2U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             138);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             140);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             141);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             142);
        vlSelfRef.tb__DOT__phy_data_t = 2U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             143);
        vlSelfRef.tb__DOT__phy_data_t = 2U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             145);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             146);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             147);
        vlSelfRef.tb__DOT__phy_data_t = 2U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             148);
        vlSelfRef.tb__DOT__phy_data_t = 1U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             150);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             151);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             152);
        vlSelfRef.tb__DOT__phy_data_t = 2U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             153);
        vlSelfRef.tb__DOT__phy_data_t = 3U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             155);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             156);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             157);
        vlSelfRef.tb__DOT__phy_data_t = 1U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             158);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             162);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             163);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             164);
        vlSelfRef.tb__DOT__phy_data_t = 1U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             165);
        vlSelfRef.tb__DOT__phy_data_t = 2U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             167);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             168);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             169);
        vlSelfRef.tb__DOT__phy_data_t = 1U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             170);
        vlSelfRef.tb__DOT__phy_data_t = 1U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             172);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             173);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             174);
        vlSelfRef.tb__DOT__phy_data_t = 1U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             175);
        vlSelfRef.tb__DOT__phy_data_t = 3U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             177);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             178);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             179);
        vlSelfRef.tb__DOT__phy_data_t = 3U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             180);
        vlSelfRef.tb__DOT__phy_data_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x000000000004e200ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             183);
        vlSelfRef.tb__DOT__ctl_t = 0U;
        co_await vlSelfRef.__VdlySched.delay(0x000000000007a120ULL, 
                                             nullptr, 
                                             "testbench/tb.v", 
                                             235);
    }
    co_return;
}

VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__3(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP__Vtiming__3\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->_vm_contextp__->dumpfile("tb.vcd"s);
    vlSymsp->_traceDumpOpen();
    co_await vlSelfRef.__VdlySched.delay(0x0000000005f5e100ULL, 
                                         nullptr, "testbench/tb.v", 
                                         259);
    VL_FINISH_MT("testbench/tb.v", 259, "");
    co_return;
}

void Vtb___024root___eval_triggers_vec__act(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_triggers_vec__act\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                      << 5U) 
                                                     | (((((~ (IData)(vlSelfRef.tb__DOT__phy_clk_t)) 
                                                           & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__phy_clk_t__0)) 
                                                          << 3U) 
                                                         | (((IData)(vlSelfRef.tb__DOT__cs) 
                                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__cs__0))) 
                                                            << 2U)) 
                                                        | ((((~ (IData)(vlSelfRef.tb__DOT__clk)) 
                                                             & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__clk__0)) 
                                                            << 1U) 
                                                           | ((IData)(vlSelfRef.tb__DOT__phy_clk_t) 
                                                              & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__phy_clk_t__0))))))));
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__phy_clk_t__0 
        = vlSelfRef.tb__DOT__phy_clk_t;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__clk__0 
        = vlSelfRef.tb__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__cs__0 
        = vlSelfRef.tb__DOT__cs;
}

bool Vtb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

extern const VlUnpacked<CData/*1:0*/, 8> Vtb__ConstPool__TABLE_he534ed75_0;

void Vtb___024root___nba_sequent__TOP__0(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__0\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*2:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    // Body
    vlSelfRef.__Vdly__tb__DOT__uut__DOT__quad_spi__DOT__qspi_state 
        = vlSelfRef.tb__DOT__uut__DOT__quad_spi__DOT__qspi_state;
    __Vtableidx2 = (((IData)(vlSelfRef.tb__DOT__uut__DOT__quad_spi__DOT__qspi_state) 
                     << 1U) | (IData)(vlSelfRef.tb__DOT__cs));
    vlSelfRef.__Vdly__tb__DOT__uut__DOT__quad_spi__DOT__qspi_state 
        = Vtb__ConstPool__TABLE_he534ed75_0[__Vtableidx2];
}

extern const VlUnpacked<CData/*0:0*/, 8> Vtb__ConstPool__TABLE_h27a7c87c_0;
extern const VlUnpacked<CData/*0:0*/, 8> Vtb__ConstPool__TABLE_hd59b4f4e_0;
extern const VlUnpacked<CData/*0:0*/, 8> Vtb__ConstPool__TABLE_hc0328dcb_0;

void Vtb___024root___nba_sequent__TOP__1(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__1\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*2:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    IData/*27:0*/ __Vdly__tb__DOT__uut__DOT__b__DOT__counter;
    __Vdly__tb__DOT__uut__DOT__b__DOT__counter = 0;
    // Body
    __Vdly__tb__DOT__uut__DOT__b__DOT__counter = vlSelfRef.tb__DOT__uut__DOT__b__DOT__counter;
    __Vdly__tb__DOT__uut__DOT__b__DOT__counter = (0x0fffffffU 
                                                  & ((IData)(1U) 
                                                     + vlSelfRef.tb__DOT__uut__DOT__b__DOT__counter));
    vlSelfRef.tb__DOT__uut__DOT__b__DOT__outcnt = (7U 
                                                   & (vlSelfRef.tb__DOT__uut__DOT__b__DOT__counter 
                                                      >> 0x00000019U));
    vlSelfRef.tb__DOT__uut__DOT__b__DOT__counter = __Vdly__tb__DOT__uut__DOT__b__DOT__counter;
    __Vtableidx1 = vlSelfRef.tb__DOT__uut__DOT__b__DOT__outcnt;
    vlSelfRef.tb__DOT__uut__DOT____Vcellout__b__led1 
        = Vtb__ConstPool__TABLE_h27a7c87c_0[__Vtableidx1];
    vlSelfRef.tb__DOT__uut__DOT____Vcellout__b__led2 
        = Vtb__ConstPool__TABLE_hd59b4f4e_0[__Vtableidx1];
    vlSelfRef.tb__DOT__uut__DOT____Vcellout__b__led3 
        = Vtb__ConstPool__TABLE_hc0328dcb_0[__Vtableidx1];
}

void Vtb___024root___nba_sequent__TOP__2(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__2\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*11:0*/ __Vdly__tb__DOT__uut__DOT__fifo__DOT__read_addr;
    __Vdly__tb__DOT__uut__DOT__fifo__DOT__read_addr = 0;
    // Body
    __Vdly__tb__DOT__uut__DOT__fifo__DOT__read_addr 
        = vlSelfRef.tb__DOT__uut__DOT__fifo__DOT__read_addr;
    if ((0U != (IData)(vlSelfRef.tb__DOT__uut__DOT__quad_spi__DOT__qspi_state))) {
        vlSelfRef.tb__DOT__uut__DOT__qspi_tx_data = vlSelfRef.tb__DOT__uut__DOT__fifo__DOT__memory
            [(0x000007ffU & (IData)(vlSelfRef.tb__DOT__uut__DOT__fifo__DOT__read_addr))];
        __Vdly__tb__DOT__uut__DOT__fifo__DOT__read_addr 
            = (0x00000fffU & ((IData)(1U) + (IData)(vlSelfRef.tb__DOT__uut__DOT__fifo__DOT__read_addr)));
    } else {
        __Vdly__tb__DOT__uut__DOT__fifo__DOT__read_addr 
            = vlSelfRef.tb__DOT__uut__DOT__fifo__DOT__read_addr;
        vlSelfRef.tb__DOT__uut__DOT__qspi_tx_data = 0U;
    }
    vlSelfRef.tb__DOT__uut__DOT__fifo__DOT__read_addr 
        = __Vdly__tb__DOT__uut__DOT__fifo__DOT__read_addr;
}

void Vtb___024root___nba_sequent__TOP__3(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__3\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*3:0*/ __Vdly__tb__DOT__uut__DOT__firewire__DOT__data_shift;
    __Vdly__tb__DOT__uut__DOT__firewire__DOT__data_shift = 0;
    // Body
    vlSelfRef.__Vdly__tb__DOT__uut__DOT__firewire__DOT__data_strobe_temp 
        = vlSelfRef.tb__DOT__uut__DOT__firewire__DOT__data_strobe_temp;
    vlSelfRef.__Vdly__tb__DOT__uut__DOT__firewire__DOT__receiving_data 
        = vlSelfRef.tb__DOT__uut__DOT__firewire__DOT__receiving_data;
    __Vdly__tb__DOT__uut__DOT__firewire__DOT__data_shift 
        = vlSelfRef.tb__DOT__uut__DOT__firewire__DOT__data_shift;
    vlSelfRef.__Vdly__tb__DOT__uut__DOT__dv__DOT__dataNybbleCounter 
        = vlSelfRef.tb__DOT__uut__DOT__dv__DOT__dataNybbleCounter;
    vlSelfRef.__Vdly__tb__DOT__uut__DOT__dv__DOT__headerNybbleCounter 
        = vlSelfRef.tb__DOT__uut__DOT__dv__DOT__headerNybbleCounter;
    if ((0U == (IData)(vlSelfRef.tb__DOT__ctl_t))) {
        __Vdly__tb__DOT__uut__DOT__firewire__DOT__data_shift = 0U;
        vlSelfRef.__Vdly__tb__DOT__uut__DOT__firewire__DOT__data_strobe_temp = 0U;
        vlSelfRef.__Vdly__tb__DOT__uut__DOT__firewire__DOT__receiving_data = 0U;
    } else if (vlSelfRef.tb__DOT__uut__DOT__firewire__DOT__receiving_data) {
        __Vdly__tb__DOT__uut__DOT__firewire__DOT__data_shift 
            = ((0x0000000cU & ((IData)(vlSelfRef.tb__DOT__uut__DOT__firewire__DOT__data_shift) 
                               << 2U)) | ((2U & ((IData)(vlSelfRef.tb__DOT__phy_data_t) 
                                                 << 1U)) 
                                          | (1U & ((IData)(vlSelfRef.tb__DOT__phy_data_t) 
                                                   >> 1U))));
        vlSelfRef.__Vdly__tb__DOT__uut__DOT__firewire__DOT__data_strobe_temp 
            = (1U & (~ (IData)(vlSelfRef.tb__DOT__uut__DOT__firewire__DOT__data_strobe_temp)));
        vlSelfRef.__Vdly__tb__DOT__uut__DOT__firewire__DOT__receiving_data = 1U;
    } else if (((1U == (IData)(vlSelfRef.tb__DOT__ctl_t)) 
                & (0U == (IData)(vlSelfRef.tb__DOT__phy_data_t)))) {
        vlSelfRef.__Vdly__tb__DOT__uut__DOT__firewire__DOT__receiving_data = 1U;
    } else {
        __Vdly__tb__DOT__uut__DOT__firewire__DOT__data_shift = 0U;
        vlSelfRef.__Vdly__tb__DOT__uut__DOT__firewire__DOT__data_strobe_temp = 0U;
        vlSelfRef.__Vdly__tb__DOT__uut__DOT__firewire__DOT__receiving_data = 0U;
    }
    vlSelfRef.tb__DOT__uut__DOT__firewire__DOT__data_shift 
        = __Vdly__tb__DOT__uut__DOT__firewire__DOT__data_shift;
}

void Vtb___024root___nba_sequent__TOP__4(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__4\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*11:0*/ __Vdly__tb__DOT__uut__DOT__fifo__DOT__write_addr;
    __Vdly__tb__DOT__uut__DOT__fifo__DOT__write_addr = 0;
    CData/*3:0*/ __VdlyVal__tb__DOT__uut__DOT__fifo__DOT__memory__v0;
    __VdlyVal__tb__DOT__uut__DOT__fifo__DOT__memory__v0 = 0;
    SData/*10:0*/ __VdlyDim0__tb__DOT__uut__DOT__fifo__DOT__memory__v0;
    __VdlyDim0__tb__DOT__uut__DOT__fifo__DOT__memory__v0 = 0;
    CData/*0:0*/ __VdlySet__tb__DOT__uut__DOT__fifo__DOT__memory__v0;
    __VdlySet__tb__DOT__uut__DOT__fifo__DOT__memory__v0 = 0;
    // Body
    __Vdly__tb__DOT__uut__DOT__fifo__DOT__write_addr 
        = vlSelfRef.tb__DOT__uut__DOT__fifo__DOT__write_addr;
    __VdlySet__tb__DOT__uut__DOT__fifo__DOT__memory__v0 = 0U;
    vlSelfRef.tb__DOT__uut__DOT__dv__DOT__status_state_reg 
        = (2U == (IData)(vlSelfRef.tb__DOT__ctl_t));
    if (((0U != (IData)(vlSelfRef.tb__DOT__uut__DOT__fifo__DOT__pulseCounter)) 
         | ((1U & ((IData)(vlSelfRef.tb__DOT__uut__DOT__fifo__DOT__write_addr) 
                   >> 0x0000000aU)) != (IData)(vlSelfRef.tb__DOT__uut__DOT__fifo__DOT__write_addr_2nd_msb)))) {
        vlSelfRef.tb__DOT__uut__DOT__fifo__DOT__pulseCounter 
            = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.tb__DOT__uut__DOT__fifo__DOT__pulseCounter)));
        vlSelfRef.tb__DOT__hf_t = 1U;
    } else {
        vlSelfRef.tb__DOT__uut__DOT__fifo__DOT__pulseCounter = 0U;
        vlSelfRef.tb__DOT__hf_t = 0U;
    }
    if (vlSelfRef.tb__DOT__uut__DOT__dv_data_available) {
        __VdlyVal__tb__DOT__uut__DOT__fifo__DOT__memory__v0 
            = vlSelfRef.tb__DOT__uut__DOT__dv_rx_data;
        __VdlyDim0__tb__DOT__uut__DOT__fifo__DOT__memory__v0 
            = (0x000007ffU & (IData)(vlSelfRef.tb__DOT__uut__DOT__fifo__DOT__write_addr));
        __VdlySet__tb__DOT__uut__DOT__fifo__DOT__memory__v0 = 1U;
        __Vdly__tb__DOT__uut__DOT__fifo__DOT__write_addr 
            = (0x00000fffU & ((IData)(1U) + (IData)(vlSelfRef.tb__DOT__uut__DOT__fifo__DOT__write_addr)));
        vlSelfRef.tb__DOT__uut__DOT__fifo__DOT__write_addr_2nd_msb 
            = (1U & ((IData)(vlSelfRef.tb__DOT__uut__DOT__fifo__DOT__write_addr) 
                     >> 0x0aU));
    } else {
        __Vdly__tb__DOT__uut__DOT__fifo__DOT__write_addr 
            = vlSelfRef.tb__DOT__uut__DOT__fifo__DOT__write_addr;
    }
    vlSelfRef.tb__DOT__uut__DOT__fifo__DOT__write_addr 
        = __Vdly__tb__DOT__uut__DOT__fifo__DOT__write_addr;
    if (__VdlySet__tb__DOT__uut__DOT__fifo__DOT__memory__v0) {
        vlSelfRef.tb__DOT__uut__DOT__fifo__DOT__memory[__VdlyDim0__tb__DOT__uut__DOT__fifo__DOT__memory__v0] 
            = __VdlyVal__tb__DOT__uut__DOT__fifo__DOT__memory__v0;
    }
    vlSelfRef.tb__DOT__uut__DOT__dv_rx_data = (((~ (IData)(vlSelfRef.tb__DOT__uut__DOT__dv__DOT__ignore)) 
                                                & (((0U 
                                                     == (IData)(vlSelfRef.tb__DOT__uut__DOT__dv__DOT__headerNybbleCounter)) 
                                                    & (0U 
                                                       == (IData)(vlSelfRef.tb__DOT__uut__DOT__dv__DOT__firstEightByteIgnoreCounter))) 
                                                   & (0U 
                                                      != vlSelfRef.tb__DOT__uut__DOT__dv__DOT__dataNybbleCounter)))
                                                ? (IData)(vlSelfRef.tb__DOT__uut__DOT__phy_rx_data)
                                                : 0U);
    vlSelfRef.tb__DOT__uut__DOT__dv_data_available 
        = (((~ (IData)(vlSelfRef.tb__DOT__uut__DOT__dv__DOT__ignore)) 
            & (((0U == (IData)(vlSelfRef.tb__DOT__uut__DOT__dv__DOT__headerNybbleCounter)) 
                & (0U == (IData)(vlSelfRef.tb__DOT__uut__DOT__dv__DOT__firstEightByteIgnoreCounter))) 
               & (0U != vlSelfRef.tb__DOT__uut__DOT__dv__DOT__dataNybbleCounter))) 
           && (IData)(vlSelfRef.tb__DOT__uut__DOT__phy_data_available));
}

void Vtb___024root___nba_sequent__TOP__5(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__5\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__uut__DOT__quad_spi__DOT__qspi_state 
        = vlSelfRef.__Vdly__tb__DOT__uut__DOT__quad_spi__DOT__qspi_state;
}

void Vtb___024root___nba_sequent__TOP__6(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__6\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tb__DOT__uut__DOT__firewire__DOT__receiving_data) {
        if (vlSelfRef.tb__DOT__uut__DOT__phy_data_available) {
            if ((0x0dU <= (IData)(vlSelfRef.tb__DOT__uut__DOT__dv__DOT__headerNybbleCounter))) {
                vlSelfRef.__Vdly__tb__DOT__uut__DOT__dv__DOT__dataNybbleCounter 
                    = ((0x0001ffe0U & (vlSelfRef.tb__DOT__uut__DOT__dv__DOT__dataNybbleCounter 
                                       << 4U)) | ((IData)(vlSelfRef.tb__DOT__uut__DOT__phy_rx_data) 
                                                  << 1U));
                vlSelfRef.__Vdly__tb__DOT__uut__DOT__dv__DOT__headerNybbleCounter 
                    = (0x0000001fU & ((IData)(vlSelfRef.tb__DOT__uut__DOT__dv__DOT__headerNybbleCounter) 
                                      - (IData)(1U)));
            } else if ((0U != (IData)(vlSelfRef.tb__DOT__uut__DOT__dv__DOT__headerNybbleCounter))) {
                vlSelfRef.__Vdly__tb__DOT__uut__DOT__dv__DOT__headerNybbleCounter 
                    = (0x0000001fU & ((IData)(vlSelfRef.tb__DOT__uut__DOT__dv__DOT__headerNybbleCounter) 
                                      - (IData)(1U)));
                vlSelfRef.tb__DOT__uut__DOT__dv__DOT__ignore 
                    = (0x0001fffeU == vlSelfRef.tb__DOT__uut__DOT__dv__DOT__dataNybbleCounter);
            } else if ((0U != (IData)(vlSelfRef.tb__DOT__uut__DOT__dv__DOT__firstEightByteIgnoreCounter))) {
                vlSelfRef.tb__DOT__uut__DOT__dv__DOT__firstEightByteIgnoreCounter 
                    = (0x0000001fU & ((IData)(vlSelfRef.tb__DOT__uut__DOT__dv__DOT__firstEightByteIgnoreCounter) 
                                      - (IData)(1U)));
                vlSelfRef.__Vdly__tb__DOT__uut__DOT__dv__DOT__dataNybbleCounter 
                    = (0x0001ffffU & (vlSelfRef.tb__DOT__uut__DOT__dv__DOT__dataNybbleCounter 
                                      - (IData)(1U)));
            } else if ((0U != vlSelfRef.tb__DOT__uut__DOT__dv__DOT__dataNybbleCounter)) {
                vlSelfRef.__Vdly__tb__DOT__uut__DOT__dv__DOT__dataNybbleCounter 
                    = (0x0001ffffU & (vlSelfRef.tb__DOT__uut__DOT__dv__DOT__dataNybbleCounter 
                                      - (IData)(1U)));
            }
        }
    } else {
        vlSelfRef.__Vdly__tb__DOT__uut__DOT__dv__DOT__headerNybbleCounter = 0x10U;
        vlSelfRef.tb__DOT__uut__DOT__dv__DOT__firstEightByteIgnoreCounter = 0x10U;
        vlSelfRef.__Vdly__tb__DOT__uut__DOT__dv__DOT__dataNybbleCounter = 0U;
        vlSelfRef.tb__DOT__uut__DOT__dv__DOT__ignore = 0U;
    }
    vlSelfRef.tb__DOT__uut__DOT__firewire__DOT__receiving_data 
        = vlSelfRef.__Vdly__tb__DOT__uut__DOT__firewire__DOT__receiving_data;
    vlSelfRef.tb__DOT__uut__DOT__dv__DOT__headerNybbleCounter 
        = vlSelfRef.__Vdly__tb__DOT__uut__DOT__dv__DOT__headerNybbleCounter;
    vlSelfRef.tb__DOT__uut__DOT__dv__DOT__dataNybbleCounter 
        = vlSelfRef.__Vdly__tb__DOT__uut__DOT__dv__DOT__dataNybbleCounter;
}

void Vtb___024root___nba_sequent__TOP__7(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__7\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__uut__DOT__phy_data_available 
        = vlSelfRef.tb__DOT__uut__DOT__firewire__DOT__data_strobe_temp;
}

void Vtb___024root___nba_sequent__TOP__8(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__8\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__uut__DOT__firewire__DOT__data_strobe_temp 
        = vlSelfRef.__Vdly__tb__DOT__uut__DOT__firewire__DOT__data_strobe_temp;
}

void Vtb___024root___nba_comb__TOP__0(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__0\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__uut__DOT__phy_rx_data = ((IData)(vlSelfRef.tb__DOT__uut__DOT__phy_data_available)
                                                 ? (IData)(vlSelfRef.tb__DOT__uut__DOT__firewire__DOT__data_shift)
                                                 : 0U);
}

void Vtb___024root___eval_nba(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_nba\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((6ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb___024root___nba_sequent__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((0x0000000000000018ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb___024root___nba_sequent__TOP__4(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
    if ((6ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb___024root___nba_sequent__TOP__5(vlSelf);
    }
    if ((0x0000000000000018ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb___024root___nba_sequent__TOP__6(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb___024root___nba_sequent__TOP__7(vlSelf);
    }
    if ((0x0000000000000018ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb___024root___nba_sequent__TOP__8(vlSelf);
    }
    if ((0x0000000000000018ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb___024root___nba_comb__TOP__0(vlSelf);
    }
}

void Vtb___024root___timing_resume(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___timing_resume\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x0000000000000020ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtb___024root___eval_phase__act(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_phase__act\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb___024root___eval_triggers_vec__act(vlSelf);
    Vtb___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtb___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtb___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vtb___024root___timing_resume(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb___024root___eval_phase__inact(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_phase__inact\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("testbench/tb.v", 3, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vtb___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtb___024root___eval_phase__nba(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_phase__nba\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtb___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtb___024root___eval_nba(vlSelf);
        Vtb___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtb___024root___eval(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtb___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("testbench/tb.v", 3, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VinactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VinactIterCount)))) {
                VL_FATAL_MT("testbench/tb.v", 3, "", "DIDNOTCONVERGE: Inactive region did not converge after '--converge-limit' of 100 tries");
            }
            vlSelfRef.__VinactIterCount = ((IData)(1U) 
                                           + vlSelfRef.__VinactIterCount);
            vlSelfRef.__VactIterCount = 0U;
            do {
                if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                    Vtb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                    VL_FATAL_MT("testbench/tb.v", 3, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 100 tries");
                }
                vlSelfRef.__VactIterCount = ((IData)(1U) 
                                             + vlSelfRef.__VactIterCount);
                vlSelfRef.__VactPhaseResult = Vtb___024root___eval_phase__act(vlSelf);
            } while (vlSelfRef.__VactPhaseResult);
            vlSelfRef.__VinactPhaseResult = Vtb___024root___eval_phase__inact(vlSelf);
        } while (vlSelfRef.__VinactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtb___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vtb___024root___eval_debug_assertions(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_debug_assertions\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
