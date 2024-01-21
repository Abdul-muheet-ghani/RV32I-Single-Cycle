module immediate (
   instruction,pc,I,S,SB,UJ,U
 );
 input signed [31:0]instruction,pc;
 output reg signed [31:0]S,SB,UJ,U,I;
 reg [11:0]II ,SS ,az;
 reg [20:0]ay;
 reg signed [31:0]ax,sb1,k;

   always @(*) begin 
   az[0] = 1'b0;
   az[4:1] = instruction[11:8];
   az[10:5] = instruction[30:25];
   az[11] = instruction[7];
   az[12] = instruction[31];

   ay[0] = 1'b0;
   ay[10:1] = instruction[30:21];
   ay[11] = instruction[20];
   ay[19:12] = instruction[19:12];
   ay[20] = instruction[31];

   ax[19:0] = instruction[31:12];
   ax[31:20] = 0;

   II = instruction[31:20];
   I = {{20{II[11]}},II};
   SS[4:0] = instruction[11:7] ;
   SS[11:5] = instruction[31:25];
   S = {{20{SS[11]}},SS};
   sb1 = {{0{az[12]}},az};
   SB = pc + sb1;
   k = {{0{ay[21]}},ay};
   UJ = k + pc;
   U = ax << 12;
   end
endmodule
