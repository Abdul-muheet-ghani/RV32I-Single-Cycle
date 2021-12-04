module arbiter (
    input         clk,
    input         signed i_ld,
    input         signed i_str,

    input      [31:0] i_ins_addr,
    input      [31:0] i_data_addr,
    output reg [12:0] o_addr,

    input      [31:0] i_data,
    output reg [31:0] o_ram_data,
    output reg [31:0] o_rom_data,

    input      [31:0] i_opb,
    output reg [31:0] o_opb,

    output  reg  write
    
);

wire we =  clk;
wire re = !clk;
wire i_ack ;

assign i_ack    =  (i_ld || i_str);

always @(*) begin
    if (re) begin
        if (i_ack) begin
                o_addr = {i_ack , i_data_addr[11:0]};
            if (i_str) begin
                o_opb = i_opb;
                write = 1'b1;
            end
            else begin
                o_ram_data = i_data;
            end
        end
    end
    if(we) begin
        o_addr     =  {1'b0 , i_ins_addr[11:0]};
        o_rom_data = i_data; 
        write = 1'b0;
    end
end
endmodule