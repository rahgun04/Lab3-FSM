module top #(parameter WIDTH = 16
)(
    output logic [7:0] data_out,
    input logic en,
    input logic rst,
    input logic clk,
    input logic [WIDTH-1:0] N,
    input logic trigger
    
);


logic cmd_seq;
logic cmd_delay;
logic [7:1] seed;
logic time_out;
logic tick;


clktick oneSec(
    .clk (clk),
    .rst (rst),
    .en (cmd_seq),
    .N (N),
    .tick (tick)
);

lfsr7 lfsr(
    .clk(clk),
    .rst(rst),
    .en(en),
    .data_out(seed)
);

delay del(
    .clk(clk),
    .rst(rst),
    .trigger(cmd_delay),
    .n(seed),
    .time_out(time_out)
);

f1_fsm lights(
    .clk(clk),
    .en(cmd_seq ? tick : time_out),
    .rst(rst),
    .data_out(data_out),
    .trigger(trigger),
    .cmd_seq(cmd_seq),
    .cmd_delay(cmd_delay)
);

endmodule
