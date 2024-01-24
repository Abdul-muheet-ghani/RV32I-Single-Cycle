module immediate (
   instruction_in,
   pc_in,
   I_type_imm_out,
   S_type_imm_out,
   SB_type_imm_out,
   UJ_type_imm_out,
   U_type_imm_out
 );
 input signed [31:0]instruction_in,pc_in;
 output reg signed [31:0]S_type_imm_out,SB_type_imm_out,UJ_type_imm_out,U_type_imm_out,I_type_imm_out;
 reg [11:0]II ,SS ,az;
 reg [20:0]ay;
 reg signed [31:0]ax,sb1,k;

    always @(*) begin 
    az[0] = 1'b0;
   az[4:1] = instruction_in[11:8];
   az[10:5] = instruction_in[30:25];
   az[11] = instruction_in[7];
   az[12] = instruction_in[31];

   ay[0] = 1'b0;
   ay[10:1] = instruction_in[30:21];
   ay[11] = instruction_in[20];
   ay[19:12] = instruction_in[19:12];
   ay[20] = instruction_in[31];

   ax[19:0] = instruction_in[31:12];
   ax[31:20] = 0;

   II = instruction_in[31:20];
   I_type_imm_out = {{20{II[11]}},II};
   SS[4:0] = instruction_in[11:7] ;
   SS[11:5] = instruction_in[31:25];
   S_type_imm_out = {{20{SS[11]}},SS};
   sb1 = {{0{az[12]}},az};
   SB_type_imm_out = pc_in + sb1;
   k = {{0{ay[21]}},ay};
   UJ_type_imm_out = k + pc_in;
   U_type_imm_out = ax << 12;
   end
endmodule
