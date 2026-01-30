`timescale 1ns/1ps

module qspi (
    // input  wire       rst,            // System reset
    input  wire       qspi_sclk_i,    // QSPI clock
    input  wire       qspi_cs_i,      // Chip select
    inout  wire [3:0] qspi_data_io,   // QSPI data bus (tri-state)
    output wire       data_fetch_o,   // High when ready for data
    input  wire [3:0] data_in_i       // Data to be transmitted
);

    // State definitions using localparam
    localparam IDLE          = 2'd0;
    localparam TRANSMIT_DATA = 2'd1;

    // Internal signals
    reg [1:0] qspi_state = IDLE;

    // Combinational Logic
    // data_fetch_o is '0' when IDLE, else '1'
    assign data_fetch_o = (qspi_state == IDLE) ? 1'b0 : 1'b1;

    // Tri-state logic for qspi_data_io
    // Driven by data_in_i during TRANSMIT_DATA state, otherwise High-Z
    assign qspi_data_io = (qspi_state == TRANSMIT_DATA) ? data_in_i : 4'bzzzz;

    // State Machine logic
    // Data is sampled on rising edge, propagated on falling edge.
    always @(negedge qspi_sclk_i or posedge qspi_cs_i) begin
        if (qspi_cs_i == 1'b1) begin
            qspi_state <= IDLE;
        end else begin
            case (qspi_state)
                IDLE: begin
                    if (qspi_cs_i == 1'b0) begin        // Chip select goes low to signal start
                        qspi_state <= TRANSMIT_DATA;
                    end else begin
                        qspi_state <= IDLE;
                    end
                end

                // TURNAROUND: begin
                //     // Move to transmit state after turnaround cycle
                //     qspi_state <= TRANSMIT_DATA;
                // end

                TRANSMIT_DATA: begin
                    if (qspi_cs_i == 1'b1) begin        // Keep transmitting as long as Chip select stays low
                        qspi_state <= IDLE;
                    end else begin
                        qspi_state <= TRANSMIT_DATA;
                    end
                end

                default: begin
                    qspi_state <= IDLE;
                end
            endcase
        end
    end

    // localparam DATA_WIDTH    = 4;
    // localparam ADDRESS_WIDTH = 5;
    //
    // reg [(DATA_WIDTH-1):0] data_in_i_tmp;
    // reg [(ADDRESS_WIDTH-1):0] counter = 5'h0;
    //
    // always @(negedge qspi_sclk_i) begin
    //     counter = counter + 1;
    //     data_in_i_tmp = memory[counter];
    // end
    //
    // reg [DATA_WIDTH-1:0] memory [0:(1 << ADDRESS_WIDTH) - 1];
    // initial begin
    //     memory[0] = 4'h4;
    //     memory[1] = 4'h8;
    //     memory[2] = 4'h6;
    //     memory[3] = 4'h5;
    //     memory[4] = 4'h6;
    //     memory[5] = 4'hC;
    //     memory[6] = 4'h6;
    //     memory[7] = 4'hC;
    //     memory[8] = 4'h6;
    //     memory[9] = 4'hF;
    //
    //     memory[10] = 4'h2;
    //     memory[11] = 4'h0;
    //
    //     memory[12] = 4'h5;
    //     memory[13] = 4'h7;
    //     memory[14] = 4'h6;
    //     memory[15] = 4'hF;
    //     memory[16] = 4'h7;
    //     memory[17] = 4'h2;
    //     memory[18] = 4'h6;
    //     memory[19] = 4'hC;
    //     memory[20] = 4'h6;
    //     memory[21] = 4'h4;
    //     memory[22] = 4'h2;
    //     memory[23] = 4'h1;
    //
    //     memory[24] = 4'h3;
    //     memory[25] = 4'h1;
    //     memory[26] = 4'h3;
    //     memory[27] = 4'h2;
    //     memory[28] = 4'h3;
    //     memory[29] = 4'h3;
    //     memory[30] = 4'h2;
    //     memory[31] = 4'h0;
    // end

endmodule
