`timescale 1ns/1ps

/*

    Detect start of packet (via speed code) and convert 2 bit wide data from phy into nybbles synced to data strobe for writing into fifo

*/

module ieee1394 (
    input  wire       rst_i,            // system reset

    input  wire       phy_clk_i,        // ieee1394 phy clock
    input  wire [1:0] phy_ctl_i,        // control signals from phy
    input  wire [1:0] phy_data_i,       // phy data

    output wire [3:0] data_o,           // output for writing to fifo
    output reg        data_strobe_o,    // strobe indicating when data_o is valid

    output wire       receive_state_o,
    output wire       status_state_o
);

    localparam CTL_IDLE = 2'b00;
    localparam CTL_STATUS = 2'b10;
    localparam CTL_RECEIVE = 2'b01;

    localparam SPEED_CODE_S100 = 2'b00;


    reg [3:0] data_shift;               // shift register for incoming data
    reg data_strobe_temp;               // temp signal to dellay strobe to align with data
    reg receiving_data = 1'b0;

    always @(negedge phy_clk_i or posedge rst_i) begin
        if (rst_i) begin
            data_shift  <= 4'h0;
            data_strobe_temp <= 1'b0;
            receiving_data <= 1'b0;

        end else begin
            if (phy_ctl_i == CTL_IDLE) begin
                data_shift  <= 4'h0;
                data_strobe_temp <= 1'b0;
                receiving_data <= 1'b0;

            end else if (/*(phy_ctl_i == CTL_STATUS) ||*/ (receiving_data))  begin
                data_shift <= {data_shift[1:0], phy_data_i[0], phy_data_i[1]};
                data_strobe_temp <= ~data_strobe_temp;
                receiving_data <= 1'b1;

            end else if ((phy_ctl_i == CTL_RECEIVE) && (phy_data_i == SPEED_CODE_S100)) begin
                receiving_data <= 1'b1;

            end else begin
                data_shift  <= 4'h0;
                data_strobe_temp <= 1'b0;
                receiving_data <= 1'b0;
            end

        end
    end

    always @(negedge phy_clk_i) begin
        data_strobe_o <= data_strobe_temp;
    end

    assign data_o = (data_strobe_o == 1'b1) ? data_shift : 4'h0;//4'bzzzz;
    assign receive_state_o = receiving_data;
    assign status_state_o = (phy_ctl_i == CTL_STATUS);

endmodule
