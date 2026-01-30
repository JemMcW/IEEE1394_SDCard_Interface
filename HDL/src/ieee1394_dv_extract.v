`timescale 1ns/1ps

module ieee1394_dv_extract (
    input  wire       rst_i,

    input  wire       phy_clk_i,

    input  wire       status_state_i,
    input  wire       receive_state_i,

    input  wire [3:0] data_i,
    output reg  [3:0] data_o,

    output wire       data_strobe_i,
    output reg        data_strobe_o

);


    /*
        one video frame is divided into 10 (12?) DIF sequences


        DIF sequency consists of

        Header section:         1 DIF block
        Subcode section:        2 DIF blocks
        VAUX section:           3 DIF blocks
        Audio section:          9 DIF blocks
        Video section:          135 DIF blocks

        DIF block consists of

        ID                      3 bytes
        data                    77 bytes
    */


    /*
        Firewire isochronous packet

        32bit header + 32bit header CRC

        first 16 bits is the data length in bytes

        data aligned to 32 bits

        32bit data CRC

    */

    reg [4:0]  headerNybbleCounter = 5'h10;             // counter for 8 bytes (16 nybbles) of header and CRC
    reg [4:0]  firstEightByteIgnoreCounter = 5'h10;     // counter to ignore the first 8 bytes of data which are not part of the dv data
    reg [16:0] dataNybbleCounter = 0;                   // counter for remaining nybbles. 2 * data length from the first 16bits of the packet header


    reg status_state_reg;
    reg ignore = 1'b0;

    always @(negedge phy_clk_i or posedge rst_i) begin

        if (rst_i) begin
            headerNybbleCounter <= 5'h10;
            firstEightByteIgnoreCounter <= 5'h10;
            dataNybbleCounter <= 0;

        end else begin

            if (receive_state_i == 1'b0) begin // TODO: check that dataNybbleCounter is 0 here
                headerNybbleCounter <= 5'h10;
                firstEightByteIgnoreCounter <= 5'h10;
                dataNybbleCounter <= 0;
                ignore <= 1'b0;

            end else if (data_strobe_i == 1'b1) begin

                // Get data length
                if (headerNybbleCounter >= 13) begin
                    dataNybbleCounter <= {dataNybbleCounter[12:1], data_i, 1'b0};
                    headerNybbleCounter <= headerNybbleCounter - 1;
                end

                // skip rest of header
                else if (headerNybbleCounter != 0) begin
                    headerNybbleCounter <= headerNybbleCounter - 1;
                    ignore <= (dataNybbleCounter == 17'h1fffe);                  // Ignore non isochronous packets. Better way ?
                end

                // ignore first 8 bytes
                else if (firstEightByteIgnoreCounter != 0) begin
                    firstEightByteIgnoreCounter <= firstEightByteIgnoreCounter - 1;
                    dataNybbleCounter <= dataNybbleCounter - 1;
                end

                // forward packet data
                else if (dataNybbleCounter != 0) begin
                    dataNybbleCounter <= dataNybbleCounter - 1;
                end
            end
        end
    end


    always @(negedge phy_clk_i) begin
        status_state_reg <= status_state_i; // delay

        if (!ignore && ((headerNybbleCounter == 0 && firstEightByteIgnoreCounter == 0 && dataNybbleCounter != 0))) begin //|| status_state_reg))  begin
            data_o <= data_i;
            data_strobe_o <= data_strobe_i;
        end else begin
            data_o <= 4'h0;
            data_strobe_o <= 1'b0;
        end
    end


endmodule
