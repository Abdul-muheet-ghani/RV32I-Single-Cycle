//////////////////////////////////////////////////////////////////////////////////
// Company: MERL-UITU
// Engineer: Abdul Muheet Ghani
// 
// Design Name: RV32IMACZicsr for Linux
// Module Name: Immediate
// Project Name: RV32IMACZicsr for linux
// Target Devices: 
// Description: 
// 
//////////////////////////////////////////////////////////////////////////////////

module immediate (
   input      signed [31:0] instruction_in,
   input      signed [31:0] pc_in,
   output reg signed [31:0] I_type_imm_out,
   output reg signed [31:0] S_type_imm_out,
   output reg signed [31:0] SB_type_imm_out,
   output reg signed [31:0] UJ_type_imm_out,
   output reg signed [31:0] U_type_imm_out
 );

 reg [11:0]S_type ,SB_type, I_type;
 reg [20:0]UJ_type;

   always @(*) begin 
      SB_type[0]    = 1'b0;
      SB_type[4:1]  = instruction_in[11:8];
      SB_type[10:5] = instruction_in[30:25];
      SB_type[11]   = instruction_in[7];
      SB_type[12]   = instruction_in[31];

      UJ_type[0]     = 1'b0;
      UJ_type[10:1]  = instruction_in[30:21];
      UJ_type[11]    = instruction_in[20];
      UJ_type[19:12] = instruction_in[19:12];
      UJ_type[20]    = instruction_in[31];

      S_type[4:0]     = instruction_in[11:7] ;
      S_type[11:5]    = instruction_in[31:25];

      I_type   = instruction_in[31:20];

      I_type_imm_out  = {{20{I_type[11]}},I_type};
      S_type_imm_out  = {{20{S_type[11]}},S_type};
      SB_type_imm_out = pc_in + {{0{SB_type[12]}},SB_type};
      UJ_type_imm_out = {{0{UJ_type[21]}},UJ_type} + pc_in;
      U_type_imm_out  = {12'b0,instruction_in[31:12]} << 12;
   end
endmodule
