SOURCE_DIR = ./src/
BUILD_DIR = ./build/

TB = ./testbench/tb
TOP = top

MODULES = $(shell find $(SOURCE_DIR) -name '*.v')
CONSTRAINTS = $(shell find $(SOURCE_DIR) -name '*.pcf')

# $< - first prerequisit
# $@ - first target
# $* - stem of target

.PHONY: all clean lint sim

all: $(BUILD_DIR)$(TOP).o

%.json:
	yosys -q -p 'synth_ice40 -top $(TOP) -json $@' $(MODULES)

%.asc: %.json
	nextpnr-ice40 --u1k --package sg48 --freq 96 --randomize-seed --json $(BUILD_DIR)$(TOP).json --pcf $(CONSTRAINTS) --asc $@

%.bin: %.asc
	icepack $< $@

%.o: %.bin
	arm-none-eabi-objcopy -I binary -O elf32-littlearm --rename-section .data=.fpgabitstream $< $@

sim:
	verilator --binary --trace-vcd -Wno-WIDTHTRUNC -Wno-PINMISSING -Isrc -j 0 $(TB).v
	./obj_dir/Vtb +trace

lint:
	verilator --lint-only -Wall -Wno-WIDTHTRUNC -Wno-PROCASSINIT -Wpedantic -Isrc ./src/$(TOP).v

clean:
	rm $(BUILD_DIR)*.bin

