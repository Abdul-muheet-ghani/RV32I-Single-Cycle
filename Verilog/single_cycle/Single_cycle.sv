/*
Abdul Muheet Ghani
*/

`timescale 1ns/1ns
module ram (
    clk,addre,din,dout,we
 );
    input clk,we;
    input [31:0]din;
    input [31:0]addre;
    output reg [31:0]dout ;
    reg [11:0]add1 ;

    always @(*) begin
       #10;
       add1 = addre[13:2];
    end

    reg [31:0] mem[1024-1:0] ;

    initial begin
        $readmemh("coef.txt",mem);
    end
    
    always @(posedge clk) begin
            if (we==1) begin
               mem[add1] <= din;
            end else begin
               dout <= mem[add1];
            end
    end
endmodule
//----------------------------------------------------
module adder (clk,a);


 reg [31:0]c=0;
 output reg [31:0]a;
 input clk;

    always @(posedge clk ) begin
       a <= c;
    end

    always @* begin
       c <= a+4;
    end
endmodule
//-----------------------------------------------------
module control (
   input [31:0]opcode,output reg [8:0]dec
 );
 reg [6:0]c ;
 reg [31:7]b;

 always @* begin
    c = opcode[6:0];
 end


 always @* begin
   case (c)
      7'b0110011 : dec = 9'b100000000;
      7'b0010011 : dec = 9'b010000000;
      7'b0000011 : dec = 9'b001000000;
      7'b0100011 : dec = 9'b000100000;
      7'b1100011 : dec = 9'b000010000;
      7'b1101111 : dec = 9'b000001000;
      7'b1100111 : dec = 9'b000000100;
      7'b0110111 : dec = 9'b000000010;
      7'b0010111 : dec = 9'b000000001; 
      default: dec = 0;
   endcase
end
endmodule
//----------------------------------------------------
module unit (
   input [8:0]dec,input [31:0]in,output reg[14:0]un
 );

 reg [2:0]fun_3 ;
 reg fun_7;

 always @* begin
    fun_3 = in[14:12];
    fun_7 = in[30];
 end

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
   un[8] = dec[0] | dec[1] | dec[4] | dec[5] | dec[7] | dec[6] ;
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
            3'b100: un[5:2] = 4'b0101;
            3'b010: un[5:2] = 4'b0111;
            3'b110: un[5:2] = 4'b0011;
            3'b001: un[5:2] = 4'b1101;
            3'b101: un[5:2] = 4'b1001; 
            3'b011: un[5:2] = 4'b1001;
            3'b111: un[5:2] = 4'b0011;
            default:un[5:2] = 0; 
         endcase

      end else begin                                //fun-7 = 0 
         case (fun_3)                          
            3'b000: un[5:2] = 4'b0000;
            3'b100: un[5:2] = 4'b0100;
            3'b010: un[5:2] = 4'b0111;
            3'b110: un[5:2] = 4'b0011;
            3'b001: un[5:2] = 4'b0101;
            3'b101: un[5:2] = 4'b0110; 
            3'b011: un[5:2] = 4'b1000;
            3'b111: un[5:2] = 4'b0010;
            default : un[5:2] = 0;
         endcase
      end
      
   end
   if (dec == 9'b010000000) begin
      if (fun_7==1) begin
         case (fun_3)
            3'b000: un[5:2] = 4'b0000;
            3'b100: un[5:2] = 4'b0100;
            3'b010: un[5:2] = 4'b0111;
            3'b110: un[5:2] = 4'b0011;
            3'b001: un[5:2] = 4'b1101;
            3'b101: un[5:2] = 4'b1001; 
            3'b011: un[5:2] = 4'b1000;
            3'b111: un[5:2] = 4'b0010;
            default:un[5:2] = 0; 
         endcase

      end else begin                                //fun-7 = 0 
         case (fun_3)                          
            3'b000: un[5:2] = 4'b0000;
            3'b100: un[5:2] = 4'b0100;
            3'b010: un[5:2] = 4'b0111;
            3'b110: un[5:2] = 4'b0011;
            3'b001: un[5:2] = 4'b0101;
            3'b101: un[5:2] = 4'b0110; 
            3'b011: un[5:2] = 4'b1000;
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
//----------------------------------------------------
module reg_adr (
   bit,rs1,rs2,rd,clk
 );

    input [31:0]bit;
    output reg [4:0]rs1,rs2,rd ;
    input clk;

    always @(*) begin
        rs2 <= bit[24:20];
        rs1 <= bit[19:15];
        rd  <= bit[11:7];
    end
   
endmodule
//----------------------------------------------------
module reg_file (
   rs1,rs2,rd,inp,ou1,ou2,clk
 );

 input clk;
 input [4:0]rs1,rs2,rd;
 input [31:0]inp;
 output reg[31:0]ou1,ou2;
 reg [31:0]x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19,x20,x21,x22,x23,x24,x25,x26,x27,x28,x29,x30,x31 ;

 always @(posedge clk) begin
   case (rd)
      0 : x0 = 0;
      1 : x1 = inp;
      2 : x2 = inp;
      3 : x3 = inp;
      4 : x4 = inp;
      5 : x5 = inp;
      6 : x6 = inp;
      7 : x7 = inp;
      8 : x8 = inp;
      9 : x9 = inp;
      10 : x10 = inp;
      11 : x11 = inp;
      12 : x12 = inp;
      13 : x13 = inp;
      14 : x14 = inp;
      15 : x15 = inp;
      16 : x16 = inp;
      17 : x17 = inp;
      18 : x18 = inp;
      19 : x19 = inp;
      20 : x20 = inp;
      21 : x21 = inp;
      22 : x22 = inp;
      23 : x23 = inp;
      24 : x24 = inp;
      25 : x25 = inp;
      26 : x26 = inp;
      27 : x27 = inp;
      28 : x28 = inp;
      29 : x29 = inp;
      30 : x30 = inp;
      31 : x31 = inp;  
      default : x0 = 0; 
   endcase
  end
  always @* begin
   case (rs1)
      0 : ou1 = 0;
      1 : ou1 = x1;
      2 : ou1 = x2;
      3 : ou1 = x3;
      4 : ou1 = x4;
      5 : ou1 = x5;
      6 : ou1 = x6;
      7 : ou1 = x7;
      8 : ou1 = x8;
      9 : ou1 = x9;
      10 : ou1 = x10;
      11 : ou1 = x11;
      12 : ou1 = x12;
      13 : ou1 = x13;
      14 : ou1 = x14;
      15 : ou1 = x15;
      16 : ou1 = x16;
      17 : ou1 = x17;
      18 : ou1 = x18;
      19 : ou1 = x19;
      20 : ou1 = x20;
      21 : ou1 = x21;
      22 : ou1 = x22;
      23 : ou1 = x23;
      24 : ou1 = x24;
      25 : ou1 = x25;
      26 : ou1 = x25;
      27 : ou1 = x27;
      28 : ou1 = x28;
      29 : ou1 = x29;
      30 : ou1 = x30;
      31 : ou1 = x31;

      default : ou1 = 0; 
   endcase
 //end
 //always @* begin
    
   case (rs2)
      0 : ou2 = 0;
      1 : ou2 = x1;
      2 : ou2 = x2;
      3 : ou2 = x3;
      4 : ou2 = x4;
      5 : ou2 = x5;
      6 : ou2 = x6;
      7 : ou2= x7;
      8 : ou2= x8;
      9 : ou2= x9;
      10 : ou2 = x10;
      11 : ou2 = x11;
      12 : ou2 = x12;
      13 : ou2 = x13;
      14 : ou2 = x14;
      15 : ou2 = x15;
      16 : ou2 = x16;
      17 : ou2 = x17;
      18 : ou2 = x18;
      19 : ou2 = x19;
      20 : ou2 = x20;
      21 : ou2 = x21;
      22 : ou2 = x22;
      23 : ou2 = x23;
      24 : ou2 = x24;
      25 : ou2 = x25;
      26 : ou2 = x25;
      27 : ou2 = x27;
      28 : ou2 = x28;
      29 : ou2 = x29;
      30 : ou2 = x30;
      31 : ou2 = x31;

      default : ou2 = 0; 
   endcase
 end
endmodule
//----------------------------------------------------
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

   assign ay[31:21] = 12'b000000000000;

   assign ax[19:0] = instruction[31:12];
   assign ax[31:20] = 0;

 always @(*)  begin
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
//----------------------------------------------------
module ALU (
   op,op1,op2,res
 );
   input [3:0]op;
   input [31:0]op1,op2;
   output reg [31:0]res ;


 always @* begin
      case (op)
         4'b0000 : res = op1 + op2; 
         4'b0001 : res = op1 - op2;
         4'b0010 : res = op1 & op2;
         4'b0011 : res = op1 | op2;
         4'b0100 : res = op1 ^ op2;
         4'b0101 : res = op1 << op2;
         4'b0101 : res = op1 >> op2;
         4'b0110 : res = op1 > op2;
         4'b0111 : res = op1 > op2;
         4'b1000 : res = op1 >> op2;
         4'b1111 : res = op1 + op2;
         default: res = 0;
      endcase
 end

endmodule
//----------------------------------------------------
module branch (
   op1,op2,fu_3,en,re
 );

 input [31:0]op1,op2;
 input [2:0]fu_3;
 input en;
 output reg re;
 wire fu_3;

 always @* begin
   if (fu_3 == 3'b000) begin
   if (op1 == op2) begin
      re = 1;
   end else begin
      re = 0;
   end
 end
   if (fu_3 == 3'b001) begin
   if (op1 != op2) begin
      re = 1;
   end else begin
      re = 0;
   end
 end
   if (fu_3 == 3'b100) begin
   if (op1 < op2) begin
      re = 1;
   end else begin
      re = 0;
   end
 end
   if (fu_3 == 3'b101) begin
   if (op1 >= op2) begin
      re = 1;
   end else begin
      re = 0;
   end
 end 
   if (fu_3 == 3'b110) begin
   if (op1 < op2) begin
      re = 1;
   end else begin
      re = 0;
   end
 end
   if (fu_3 == 3'b111) begin
   if (op1 >= op2) begin
      re = 1;
   end else begin
      re = 0;
   end
 end


 end
   
endmodule
//----------------------------------------------------
module data_mem (
    clk,addr,d,str,ld,resu
 );

 input clk,str,ld;
 input [31:0]addr,d;
 output reg[31:0] resu;
 reg [11:0]ad1 ;
 reg [31:0] data_rom[1024-1:0];

 always @(*) begin
    ad1 = addr[13:2];
 end

 always @(*) begin
    if (str == 1) begin
       data_rom[addr] <= d;
    end
    if (ld == 1) begin
      resu = data_rom[addr];
   end
 end
 

    
endmodule
//----------------------------------------------------
module mux1_2 (
   sel,a,b,c
 );
   input sel;
   input [31:0]a,b;
   output reg [31:0]c ;

 always @* begin
   case (sel)
      1'b0 : c = a;
      1'b1 : c = b; 
      
   endcase
 end


endmodule
//------------------------------------------------
module mux2_4 (
   sel,a,b,c,d,o
 );

 input [1:0]sel;
 input [31:0]a,b,c,d;
 output reg [31:0]o ;

 always @* begin
   case (sel)
      2'b00 : o = a;
      2'b01 : o = b;
      2'b10 : o = c;
      2'b11 : o = d; 
   endcase
 end
   
endmodule
//---------------------------------------------------
module as (
    clk,data_in,data_out,we
 );

 input clk,we;
 input [31:0]data_in ;
 output [14:0]data_out ;
 wire [31:0]OUT_T,addr,a,b,I,S,SB,UJ,U,op1,op2,faltu,reg_1,reg_2,im,ALU_OUTPUT,write_adder,write_ba,rite_ba ;
 wire [8:0]c ;
 wire [4:0]r1,r2,rf ;
 reg [31:0]ac,addr1=0 ;
 reg [1:0]opa,next_pc=0,imm_sel ;

 //output [31:0]op1,op2;

 adder m0(clk,a);
 mux2_4 m12(next_pc,a,UJ,OUT_T,I + reg_1,addr);
 ram m1(clk,addr,data_in,b,we);
 control m2(b,c);
 unit m3(c,b,data_out);
 reg reg_write,mem_to_reg,mem_write,branch,opb;
 reg [3:0]alu_op;
 wire [31:0]zero = 0 ;

 always @* begin
    imm_sel = data_out[1:0];
    alu_op = data_out[5:2];
    next_pc = data_out[7:6];
    opb = data_out[8];
    opa = data_out[10:9];
    branch = data_out[11];
    mem_write = data_out[12];
    mem_to_reg = data_out[13];
    reg_write = data_out[14];
 end

 reg_adr ms(b,r1,r2,rf,clk);
 reg_file m4(r1,r2,rf,rite_ba,op1,op2,clk);
 immediate m5(b,a,I,S,SB,UJ,U);
 mux2_4 m6(opa,op1,a,OUT_T,zero,reg_1);
 mux2_4 m7(imm_sel,zero,U,I,S,im);
 mux1_2 m8(opb,op2,im,reg_2);
 ALU m9(alu_op,reg_1,reg_2,ALU_OUTPUT);
 data_mem m10(clk,ALU_OUTPUT,op2,mem_write,mem_to_reg,write_adder);
 mux1_2 m11(mem_to_reg,ALU_OUTPUT,write_adder,write_ba);
 mux1_2 m14(mem_write,write_ba,zero,rite_ba);
 mux1_2 m13(branch,a,SB,OUT_T);
endmodule
//--------------------------------------------------
module asd (
   clk,data_in,data_out,we
);
   input clk,we;
   input [31:0]data_in;
   output [31:0]data_out;
   wire [31:0]a ;

   adder m89(clk,a);
   ram m78(clk,a,data_in,data_out,we);

endmodule
