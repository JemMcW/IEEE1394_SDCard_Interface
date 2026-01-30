`timescale 1ns/1ps

module tb ();

    reg clk;
    reg cs;
    reg phy_clk_t;
    reg [1:0] ctl_t;
    reg [1:0] phy_data_t;
    reg empty_t;
    reg hf_t;
    reg [5:0] phy_data_pad_t;

    reg first_read_t;

    integer i;

    // qspi read out when fifo half full
    initial begin

        clk = 1'b0;
        cs = 1'b1;
        first_read_t = 1'b1;

        forever begin

            if (hf_t == 1'b1) begin

                #10 cs = 1'b0;

                if (first_read_t) begin
                    first_read_t = 1'b0;
                    #10 clk = ~clk;
                    #10 clk = ~clk;
                end

                for(i = 0; i < 1024; i = i + 1) begin
                    #10 clk = ~clk;
                end

                #100 cs = 1'b0;

            end else begin
                #20;
            end
        end
    end


    // phy clock 50 Mhz
    initial begin

        phy_clk_t = 1'b0;

        forever begin
            #10 phy_clk_t = ~phy_clk_t;
        end
    end


    initial begin

        ctl_t = 2'b00;

        #10; // align changes to phy_clk rising edge

        forever begin

            // non iso packet

            #20 ctl_t = 2'b01; phy_data_t = 2'b11;
            #80 phy_data_t = 2'b00; // Speed code

            // 0xffff for 'length'
            #20 phy_data_t = 2'b11;
            #20 phy_data_t = 2'b11;
            #20 phy_data_t = 2'b11;
            #20 phy_data_t = 2'b11;
            #20 phy_data_t = 2'b11;
            #20 phy_data_t = 2'b11;
            #20 phy_data_t = 2'b11;
            #20 phy_data_t = 2'b11;

            // don't care data for rest of header
            #480

            // 4 bytes of data
            #320 phy_data_t = 2'b10;

            // don't care for data CRC
            #320 ctl_t = 2'b00;

                        // iso packet

            #200 ctl_t = 2'b01; phy_data_t = 2'b11;

            #80 phy_data_t = 2'b00; // Speed code

            // length = 12
            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b00;

            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b11;
            #20 phy_data_t = 2'b00;

            // don't care data for rest of header
            #480

            // data = 1,2,3,4 ...
            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b10;

            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b01;

            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b11;

            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b10;
            #20 phy_data_t = 2'b00;

            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b10;
            #20 phy_data_t = 2'b10;

            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b10;
            #20 phy_data_t = 2'b01;

            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b10;
            #20 phy_data_t = 2'b11;

            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b01;
            #20 phy_data_t = 2'b00;


            // 9 - 12
            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b01;
            #20 phy_data_t = 2'b10;

            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b01;
            #20 phy_data_t = 2'b01;

            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b01;
            #20 phy_data_t = 2'b11;

            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b11;
            #20 phy_data_t = 2'b00;

            // don't care for data CRC
            #320 ctl_t = 2'b00;



            // iso packet
            /*
            #200 ctl_t = 2'b01; phy_data_t = 2'b11;

            #80 phy_data_t = 2'b00; // Speed code

            // length = 512
            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b10;

            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b00;

            // don't care data for rest of header
            #480

            // data = 0,1,2,3
            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b10;

            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b01;

            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b11;

            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b00;
            #20 phy_data_t = 2'b10;
            #20 phy_data_t = 2'b00;

            // more data
            #20000;

            // don't care for data CRC
            #320 ctl_t = 2'b00;
            */

            #500;
        end
    end


    // verilator lint_off PINMISSING
    top uut (
        .quad_spi_clk(clk),
        .quad_spi_cs(cs),

        .phy_clk(phy_clk_t),
        .phy_ctl(ctl_t),
        .phy_data({phy_data_pad_t, phy_data_t}),

        .fifo_empty(empty_t),
        .fifo_half_full(hf_t),

        .error_status(1'b1)
    );
    // verilator lint_on PINMISSING

    initial begin
        $dumpfile("tb.vcd");
        $dumpvars();
        #100000 $finish;
    end




endmodule


