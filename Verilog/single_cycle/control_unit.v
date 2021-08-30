module unit (
   input [8:0]dec,input [2:0]fun_3,input fun_7,output reg[14:0]un
 );

 reg [3:0]a,c;
 reg [2:0]b,d;

 always @* begin
   a = dec[3:0];
   b = dec[4:2];
   c = dec[8:5];
   d[0] = dec[5];
   d[1] = dec[0] | dec[1];
   d[2] = dec[2] | dec[6] | dec[7];
 end
   
 always @* begin
   un[14] = dec[0] | dec[1] | dec[2] | dec[3] | dec[6] | dec[7] | dec[8];
   un[13] = dec[6];  //lw
   un[12] = dec[5];  //sw
   un[11] = dec[4];  //branch
   case (a)
      0001 : un[10:9] = 2'b01;
      0010 : un[10:9] = 2'b11;
      0100 : un[10:9] = 2'b10;
      1000 : un[10:9] = 2'b10;
      default: un[10:9] = 0;
   endcase
   un[8] = dec[0] | dec[1] | dec[4] | dec[5] | dec[7]  ;
   case (b)
      3'b001 : un[7:6] = 2'b11;
      3'b010 : un[7:6] = 2'b01;
      3'b100 : un[7:6] = 2'b10; 
      default: un[7:6] = 0; 
   endcase
   if (dec == 9'b100000000) begin
      if (fun_7==1) begin
         case (fun_3)
            3'b000: un[5:2] = 4'b0001;
            3'b001: un[5:2] = 4'b0101;
            3'b010: un[5:2] = 4'b0111;
            3'b011: un[5:2] = 4'b0011;
            3'b100: un[5:2] = 4'b1101;
            3'b101: un[5:2] = 4'b1001; 
            3'b110: un[5:2] = 4'b1001;
            3'b111: un[5:2] = 4'b0011;
            default:un[5:2] = 0; 
         endcase

      end else begin                                //fun-7 = 0 
         case (fun_3)                          
            3'b000: un[5:2] = 4'b0000;
            3'b001: un[5:2] = 4'b0100;
            3'b010: un[5:2] = 4'b0111;
            3'b011: un[5:2] = 4'b0011;
            3'b100: un[5:2] = 4'b0101;
            3'b101: un[5:2] = 4'b0110; 
            3'b110: un[5:2] = 4'b1000;
            3'b111: un[5:2] = 4'b0010;
            default : un[5:2] = 0;
         endcase
      end
      
   end
   if (dec == 9'b010000000) begin
      if (fun_7==1) begin
         case (fun_3)
            3'b000: un[5:2] = 4'b0000;
            3'b001: un[5:2] = 4'b0100;
            3'b010: un[5:2] = 4'b0111;
            3'b011: un[5:2] = 4'b0011;
            3'b100: un[5:2] = 4'b1101;
            3'b101: un[5:2] = 4'b1001; 
            3'b110: un[5:2] = 4'b1000;
            3'b111: un[5:2] = 4'b0010;
            default:un[5:2] = 0; 
         endcase

      end else begin                                //fun-7 = 0 
         case (fun_3)                          
            3'b000: un[5:2] = 4'b0000;
            3'b001: un[5:2] = 4'b0100;
            3'b010: un[5:2] = 4'b0111;
            3'b011: un[5:2] = 4'b0011;
            3'b100: un[5:2] = 4'b0101;
            3'b101: un[5:2] = 4'b0110; 
            3'b110: un[5:2] = 4'b1000;
            3'b111: un[5:2] = 4'b0010;
            default:un[5:2] = 0;
         endcase
      end
   end
   if (dec == 9'b001000000 ) begin
      if (fun_3 == 3'b010) begin
         un[5:2] = 4'b0000;
      end
   end
   if (dec == 9'b000100000 & fun_3 == 3'b010) begin
      un[5:2] = 4'b0000;
   end
   if (dec == 9'b000001000 ) begin
      un[5:2] = 4'b1111;
   end
   if (dec == 9'b000000100 & fun_3 == 3'b000) begin
      un[5:2] = 4'b1111;
   end
   if (dec == 9'b000000010 ) begin
      un[5:2] = 4'b0000;
   end
   if (dec == 9'b000000001) begin
      un[5:2] = 4'b0000;
   end
   case (d)
      3'b001 : un[1:0] = 2'b11;
      3'b010 : un[1:0] = 2'b01;
      3'b100 : un[1:0] = 2'b10; 
      default: un[1:0] = 0;
   endcase


 end

endmodule
