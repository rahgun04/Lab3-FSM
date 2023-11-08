module f1_fsm (
    input logic clk, // clock
    input logic rst, // reset
    input logic en, //enable
    input logic trigger,
    output logic [7:0] data_out, // pseudo—random output
    output logic cmd_seq,
    output logic cmd_delay
);

logic [7:0] sreg;

always_ff @ (posedge trigger) begin
    cmd_seq <= 1;
    cmd_delay <= 0;
end

always_ff @ (posedge clk, posedge rst)
    if (rst)
        sreg <= 8'b1;
    else begin
        if(en)begin
            case(sreg)
                8'b11111111:    begin
                    cmd_seq <= 0;
                    cmd_delay <= 0;
                    sreg <= 8'b00000000;
                end
                8'b01111111: begin
                    cmd_seq <= 0;
                    cmd_delay <= 1;
                    sreg <= ((sreg << 1) | 8'b00000001);
                end
                default:        sreg <= ((sreg << 1) | 8'b00000001);
            endcase
        end
    end
        

assign data_out = sreg;

endmodule
