`timescale 1ns/1ps

module fifo #(
    parameter ADDRESS_WIDTH = 10, // 1024 entries (1 ram blocks)
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

    reg write_addr_2nd_msb;
    wire fifo_half_full_edge;
    reg fifo_half_full_edge_latch;
    reg fifo_half_full_edge_delay;
    reg [3:0] pulseCounter;

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

    always @(negedge write_clk_i) begin
        if (fifo_half_full_edge) begin
            fifo_half_full_edge_latch <= 1;
        end else if (fifo_half_full_edge_delay) begin
            fifo_half_full_edge_latch <= 0;
        end
    end

    always @(negedge write_clk_i) begin
        if (fifo_half_full_edge_latch && (write_addr[4:0] == 5'h1f)) begin
            fifo_half_full_edge_delay <= 1;
        end else begin
            fifo_half_full_edge_delay <= 0;
        end
    end


    // Fifo half full pulse
    always @(negedge write_clk_i) begin
        if (pulseCounter != 0 || fifo_half_full_edge_delay) begin
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
        for (i = 0; i < 256; i++) begin
            memory[2 * i] = i/16;
            memory[2 * i + 1] = i;

            memory[512 + 2 * i] = i/16;
            memory[512 + 2 * i + 1] = i;

            memory[1024 + 2 * i] = (255 - i)/16;
            memory[1024 + 2 * i + 1] = (255 - i);

            memory[1536 + 2 * i] = (255 - i)/16;
            memory[1536 + 2 * i + 1] = (255 - i);
        end
    end

endmodule
