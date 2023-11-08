module top #(parameter WIDTH = 16
)(
    output logic [7:0] data_out,
    input logic en,
    input logic rst,
    input logic clk,
    input logic [WIDTH-1:0] N
    
);

logic tick;

clktick oneSec(
    .clk (clk),
    .rst (rst),
    .en (en),
    .N (N),
    .tick (tick)
);

f1_fsm lights(
    .clk(clk),
    .en(tick),
    .rst(rst),
    .data_out(data_out)
);

endmodule
