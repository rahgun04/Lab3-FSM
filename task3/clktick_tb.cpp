#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vclktick.h"
#include <chrono>

#include "vbuddy.cpp"     // include vbuddy code
#define MAX_SIM_CYC 100000


using namespace std::chrono; 

int main(int argc, char **argv, char **env) {
  int simcyc;     // simulation clock count
  int tick;       // each clk cycle has two ticks for two edges
  int lights = 0; // state to toggle LED lights
  int current_N = 1;
  auto lastTime = high_resolution_clock::now();

  Verilated::commandArgs(argc, argv);
  // init top verilog instance
  Vclktick * top = new Vclktick;
  // init trace dump
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace (tfp, 99);
  tfp->open ("clktick.vcd");
 
  // init Vbuddy
  if (vbdOpen()!=1) return(-1);
  vbdHeader("L3T2:Clktick");
  vbdSetMode(1);        // Flag mode set to one-shot

  // initialize simulation inputs
  top->clk = 1;
  top->rst = 0;
  top->en = 0;
  top->N = vbdValue();
  
  // run simulation for MAX_SIM_CYC clock cycles
  for (simcyc=0; simcyc<MAX_SIM_CYC; simcyc++) {
    // dump variables into VCD file and toggle clock
    for (tick=0; tick<2; tick++) {
      tfp->dump (2*simcyc+tick);
      top->clk = !top->clk;
      top->eval ();
    }

    // Display toggle neopixel
    if (top->tick) {
      vbdBar(lights);
      lights = lights ^ 0xFF;
    }
    // set up input signals of testbench
    top->rst = (simcyc < 2);    // assert reset for 1st cycle
    top->en = (simcyc > 2);
    //top->N = vbdValue();
    auto now = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(now - lastTime);
    lastTime = now;
    top->N = 1000/duration.count();
    std::cout << duration.count() << " millis(ms)"<< std::endl;
    std::cout << top->N << " = N"<< std::endl;
    vbdCycle(simcyc);


    if (Verilated::gotFinish())  exit(0);
  }

  vbdClose();     // ++++
  tfp->close(); 
  exit(0);
}
