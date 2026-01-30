
`timescale 1ns/1ps
module blinky (
    input wire clk,
    output led1,
    output led2,
    output led3
);

    localparam BITS = 3;
    localparam LOG2DELAY = 25;

    reg [BITS+LOG2DELAY-1:0] counter = 0;
    reg [BITS-1:0] outcnt;

    always @(posedge clk) begin
        counter <= counter + 1;
        outcnt <= counter >> LOG2DELAY;
    end

    assign {led1, led2, led3} = outcnt ^ (outcnt >> 1);
endmodule
