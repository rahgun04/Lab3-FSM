module lfsr7 (
    input logic clk, // clock
    input logic rst, // reset
    input logic en, //enable
    output logic [7:1] data_out // pseudo—random output
);

logic [7:1] sreg;



always_ff @ (posedge clk, posedge rst)
    if (rst)
        sreg <= 7'b1;
    else
        sreg <= en ? {sreg[6:1], sreg[7] ^ sreg[3]} : sreg[7:1]; 

assign data_out = sreg;

endmodule
