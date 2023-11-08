#!/bin/sh

# cleanup

rm -rf obj_dir

rm -f lfsr4.vcd

# run Verilator to translate Verilog into C++, including C++ testbench
verilator -Wall -cc -trace lfsr4.sv -exe prbs_tb.cpp

# build C++ project via make automatically generated by Verilator
make -j -C obj_dir/ -f Vlfsr4.mk Vlfsr4

# run executable simulation file

obj_dir/Vlfsr4