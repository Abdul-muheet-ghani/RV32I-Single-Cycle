//////////////////////////////////////////////////////////////////////////////////
// Company: MERL-UITU
// Engineer: Abdul Muheet Ghani
// 
// Design Name: RV32IMACZicsr for Linux
// Module Name: type decoder
// Project Name: RV32IMACZicsr for linux
// Target Devices: 
// Description: 
// 
//////////////////////////////////////////////////////////////////////////////////

`include "RV32_pkg.vh"

module control (
   input      [31:0] opcode_in,

   output reg        illegal_ins_out,
   output reg        ecall_out,
   output reg        ebreak_out,
   output reg        mret_out,
   output reg [10:0] decoded_out
 );

   /////////////////////////////////////////////////////////
   //always block
   /////////////////////////////////////////////////////////

   always @* begin
      case (opcode_in[6:0])
         `OPCODE_RTYPE  : {decoded_out,illegal_ins_out} = {(11'b10000000000),1'b0};
         `OPCODE_ITYPE  : {decoded_out,illegal_ins_out} = {(11'b01000000000),1'b0};
         `OPCODE_LOAD   : {decoded_out,illegal_ins_out} = {(11'b00100000000),1'b0};
         `OPCODE_STORE  : {decoded_out,illegal_ins_out} = {(11'b00010000000),1'b0};
         `OPCODE_BRANCH : {decoded_out,illegal_ins_out} = {(11'b00001000000),1'b0};
         `OPCODE_JAL    : {decoded_out,illegal_ins_out} = {(11'b00000100000),1'b0};
         `OPCODE_JALR   : {decoded_out,illegal_ins_out} = {(11'b00000010000),1'b0};
         `OPCODE_LUI    : {decoded_out,illegal_ins_out} = {(11'b00000001000),1'b0};
         `OPCODE_AUIPC  : {decoded_out,illegal_ins_out} = {(11'b00000000100),1'b0};
         `OPCODE_SYSTEM : {decoded_out,illegal_ins_out} = {(11'b00000000010),1'b0};
         `OPCODE_SYSTEM : {decoded_out,illegal_ins_out} = {(11'b00000000001),1'b0};
         default: {decoded_out,illegal_ins_out} = {11'b0,1'b1};
      endcase
   end

   always @* begin
      ecall_out  = (opcode_in == `OPCODE_SYSTEM) && (opcode_in[14:12] == 0) && (opcode_in[21:20] == 2'b00);
      ebreak_out = (opcode_in == `OPCODE_SYSTEM) && (opcode_in[14:12] == 0) && (opcode_in[21:20] == 2'b01);
      mret_out   = (opcode_in == `OPCODE_SYSTEM) && (opcode_in[14:12] == 0) && (opcode_in[21:20] == 2'b10);
   end

endmodule
