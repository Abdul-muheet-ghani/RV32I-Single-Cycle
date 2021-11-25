// #include "verilated.h"
#include "Vwrapper.h"
#include "verilated_vcd_c.h" //VCD file

using namespace std;

vluint64_t main_time=0;

int main(int argc, char** argv, char** env){
    Verilated::commandArgs(argc, argv);
    Vwrapper* my_top = new Vwrapper;

    VerilatedVcdC* vcd_file=0;
  
     const char *vcd = Verilated::commandArgsPlusMatch("vcd="); //--vdc use then only it will activate
         if (vcd[0]) {
          Verilated::traceEverOn(true);
          vcd_file = new VerilatedVcdC;
          my_top->trace (vcd_file, 99);
          vcd_file->open ("trace.vcd");
        }

vluint64_t timeout = 0;
	const char *arg_timeout = Verilated::commandArgsPlusMatch("timeout=");
	if (arg_timeout[0]) {
	  timeout = atoi(arg_timeout+9);
  }

vluint64_t vcd_start = 0;
	const char *arg_vcd_start = Verilated::commandArgsPlusMatch("vcd_start=");
	if (arg_vcd_start[0]) {
	  vcd_start = atoi(arg_vcd_start+11);
  }

    bool dump = false;
    my_top->clk = 0;
    my_top->reset = 0; // Set some inputs
    while (!Verilated::gotFinish()) {

        if (vcd_file && !dump && (main_time > vcd_start)) {
            dump = true;
          }

        if (main_time > 150) {
            my_top->reset = 1;
        }
        
        my_top->eval();

        if (dump) {
            vcd_file->dump(main_time);
        }
        
        if (timeout && (main_time >= timeout)) {
	        printf("Timeout: Exiting at time %lu\n", main_time);
	    }
        my_top->clk = !my_top->clk;
        
        main_time += 2;
    }

    if (vcd_file)
	  vcd_file->close();
    exit(0);
}
