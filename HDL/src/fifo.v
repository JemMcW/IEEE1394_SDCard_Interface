`timescale 1ns/1ps

module fifo #(
    parameter ADDRESS_WIDTH = 10, // 1024 entries (1 ram block)
    parameter DATA_WIDTH = 4      // 4 bits wide
) (
    input  wire                   write_clk_i,
    input  wire                   write_en_i,
    input  wire [DATA_WIDTH-1:0]  data_in_i,

    input  wire                   read_clk_i,
    input  wire                   read_en_i,
    output reg  [DATA_WIDTH-1:0]  data_out_o,

    output wire                   fifo_full_o,
    output reg                    fifo_half_full_o,
    output wire                   fifo_empty_o
);

    // Memory array
    reg [DATA_WIDTH-1:0] memory [0:(1 << ADDRESS_WIDTH) - 1];

    // Address width + 1 sized pointers allow index 2^N addresses
    reg [ADDRESS_WIDTH:0] write_addr = 0;
    reg [ADDRESS_WIDTH:0] read_addr = 0;
    // wire [ADDRESS_WIDTH:0] read_addr_gc;

    reg write_addr_2nd_msb;
    wire fifo_half_full_edge;
    reg [3:0] pulseCounter;

    // grey code read pointer to cross clock domains
    // assign read_add_gc = read_addr ^ (read_addr >> 1)

    // Status flags
    assign fifo_empty_o = 1'b0;
    assign fifo_full_o  = 1'b0;

    // Fifo is half full when write address 2nd msb changes
    // 8 bit address           (7 bit wide memory)
    // address: 0x00 -> 0x3f   memory written to: 0x00->0x3f
    // address: 0x40 -> 0x7f   memory written to: 0x40->0x7f
    // address: 0x80 -> 0xBf   memory written to: 0x00->0x3f
    // address: 0xC0 -> 0xff   memory written to: 0x40->0x7f

    assign fifo_half_full_edge = (write_addr[ADDRESS_WIDTH - 1] != write_addr_2nd_msb);

    // Fifo half full pulse
    always @(negedge write_clk_i) begin
        if (pulseCounter != 0 || fifo_half_full_edge) begin
            pulseCounter <= pulseCounter + 1'b1;
            fifo_half_full_o <= 1'b1;
        end else begin
            pulseCounter <= 0;
            fifo_half_full_o <= 1'b0;
        end
    end

    // Write process: Triggered on falling edge of write_clk (phy clock)
    always @(negedge write_clk_i) begin
        if (write_en_i) begin
            memory[write_addr[ADDRESS_WIDTH-1:0]] <= data_in_i;
            write_addr <= write_addr + 1'b1;
            write_addr_2nd_msb <= write_addr[ADDRESS_WIDTH - 1];
        end else begin
            write_addr <= write_addr;
        end
    end

    // Read process: Triggered on falling edge of read_clk (qspi clock)
    always @(negedge read_clk_i) begin
        if (read_en_i) begin
            data_out_o <= memory[read_addr[ADDRESS_WIDTH-1:0]];
            read_addr <= read_addr + 1'b1;
        end else begin
            data_out_o <= 0;
            read_addr <= read_addr;
        end
    end


    // Memory initialization
    integer i;
    initial begin
        for (i = 0; i < 32; i++) begin
            memory[32*i + 0] = 4'h4;
            memory[32*i + 1] = 4'h8;
            memory[32*i + 2] = 4'h6;
            memory[32*i + 3] = 4'h5;
            memory[32*i + 4] = 4'h6;
            memory[32*i + 5] = 4'hC;
            memory[32*i + 6] = 4'h6;
            memory[32*i + 7] = 4'hC;
            memory[32*i + 8] = 4'h6;
            memory[32*i + 9] = 4'hF;

            memory[32*i + 10] = 4'h2;
            memory[32*i + 11] = 4'h0;

            memory[32*i + 12] = 4'h5;
            memory[32*i + 13] = 4'h7;
            memory[32*i + 14] = 4'h6;
            memory[32*i + 15] = 4'hF;
            memory[32*i + 16] = 4'h7;
            memory[32*i + 17] = 4'h2;
            memory[32*i + 18] = 4'h6;
            memory[32*i + 19] = 4'hC;
            memory[32*i + 20] = 4'h6;
            memory[32*i + 21] = 4'h4;
            memory[32*i + 22] = 4'h2;
            memory[32*i + 23] = 4'h1;

            memory[32*i + 24] = 4'h3;
            memory[32*i + 25] = 4'h1;
            memory[32*i + 26] = 4'h3;
            memory[32*i + 27] = 4'h2;
            memory[32*i + 28] = 4'h3;
            memory[32*i + 29] = 4'h3;
            memory[32*i + 30] = 4'h2;
            memory[32*i + 31] = 4'h0;
        end
    end

endmodule
