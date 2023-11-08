module lfsr7 (
    input logic clk, // clock
    input logic rst, // reset
    input logic en, //enable
    output logic [7:0] data_out // pseudo—random output
);

logic [7:0] sreg;

always_ff @ (posedge clk, posedge rst)
    if (rst)
        sreg <= 8'b1;
    else begin
        if(en)begin
            case(sreg)
                8'b11111111:    sreg <= 8'b00000000;
                default:        sreg <= ((sreg << 1) | 8'b00000001);
            endcase
        end
    end
        

assign data_out = sreg;

endmodule