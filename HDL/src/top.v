`timescale 1ns/1ps

module top (
    input  wire       quad_spi_clk,         // QSPI clock
    input  wire       quad_spi_cs,          // QSPI chip select
    inout  wire [3:0] quad_spi_data,        // QSPI data bus (tri-state)

    input  wire       phy_clk,              // Clock from IEE1394 PHY
    output wire       phy_rst,              // Active low PHY reset signal
    output  wire      phy_lreq,             // PHY link request
    input  wire [1:0] phy_ctl,              //
    input  wire [7:0] phy_data,             // PHY data bus         -- Should be inout?

    output wire       fifo_full,
    output wire       fifo_half_full,
    output wire       fifo_empty,

    output wire [2:0] led,

    input wire        error_status
);

    //reg clk_48;

    assign phy_rst = 1'bz;

    // 48MHz internal oscilllator

    wire qspi_data_ready;
    wire [3:0] qspi_tx_data;


    assign phy_lreq = 1'b0;


    blinky b(
    .clk(phy_clk),
    .led1(led[0]),
    .led2(led[1]),
    .led3(led[2])
);

    qspi quad_spi (
        // .rst(1'b0),
        .qspi_sclk_i(quad_spi_clk),
        .qspi_cs_i(quad_spi_cs),
        .qspi_data_io(quad_spi_data),
        .data_fetch_o(qspi_data_ready),
        .data_in_i(qspi_tx_data)
    );

//     llcreq lreq (
//         .phy_clk_i(phy_clk),
//         .rst(error_status),
//         .lreq_o(phy_lreq)
// );

    wire phy_data_available;
    wire dv_data_available;
    wire [3:0] phy_rx_data;
    wire [3:0] dv_rx_data;
    wire phy_receiving;

    wire phy_status;


    ieee1394 firewire (
        // .clk_i(clk_48),
        .rst_i(1'b0),

        .phy_clk_i(phy_clk),
        .phy_ctl_i(phy_ctl),
        .phy_data_i(phy_data[1:0]),

        .data_o(phy_rx_data),
        .data_strobe_o(phy_data_available),

        .receive_state_o(phy_receiving),
        .status_state_o(phy_status)
    );


    ieee1394_dv_extract dv (
        .rst_i(1'b0),

        .phy_clk_i(phy_clk),

        .receive_state_i(phy_receiving),
        .status_state_i(phy_status),

        .data_i(phy_rx_data),
        .data_o(dv_rx_data),

        .data_strobe_i(phy_data_available),
        .data_strobe_o(dv_data_available)

    );

    // 32 Kbit fifo
    fifo  #(
        .ADDRESS_WIDTH(11)
    )
    fifo
    (
        .write_clk_i(phy_clk),
        .write_en_i(dv_data_available),
        // .write_en_i(phy_data_available),
        .data_in_i(dv_rx_data),
        // .data_in_i(phy_rx_data),

        .read_clk_i(quad_spi_clk),
        .read_en_i(qspi_data_ready),
        .data_out_o(qspi_tx_data),

        // .fifo_empty_o(fifo_empty),
        .fifo_half_full_o(fifo_half_full),
        .fifo_full_o(fifo_full)
    );


endmodule
