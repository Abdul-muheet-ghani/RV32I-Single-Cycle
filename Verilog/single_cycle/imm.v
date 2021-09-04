module immediate (
   instruction,pc,I,S,SB,UJ,U
 );
 input [31:0]instruction,pc;
 output reg[31:0]I,S,SB,UJ,U ;
 wire [31:0]az,ay,ax ;


   assign az[0] = 1'b0;
   assign az[4:1] = instruction[11:8];
   assign az[10:5] = instruction[30:25];
   assign az[11] = instruction[7];
   assign az[12] = instruction[31];
   assign az[31:13] = 20'b00000000000000000000;

   assign ay[0] = 1'b0;
   assign ay[10:1] = instruction[30:21];
   assign ay[11] = instruction[20];
   assign ay[19:12] = instruction[19:12];
   assign ay[20] = instruction[31];
   assign ay[31:21] = 10'b0000000000;

   assign ax[19:0] = instruction[31:12];
   assign ax[31:20] = 0;

 always @* begin
    I[11:0] = instruction[31:20] ;
    I[31:12] = 20'b00000000000000000000;
    S[4:0] = instruction[11:7] ;
    S[11:5] = instruction[31:25];
    S[31:12] = 20'b00000000000000000000;
    SB = pc + az;
    UJ = pc + ay;
    U = ax<<12;
 end
endmodule
