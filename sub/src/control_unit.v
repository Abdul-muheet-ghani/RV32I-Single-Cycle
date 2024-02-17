//////////////////////////////////////////////////////////////////////////////////
// Company: MERL-UITU
// Engineer: Abdul Muheet Ghani
// 
// Design Name: RV32IMACZicsr for Linux
// Module Name: Control Unit
// Project Name: RV32IMACZicsr for linux
// Target Devices: 
// Description: 
// 
//////////////////////////////////////////////////////////////////////////////////

`include "RV32_pkg.vh"

module unit (
   input     [8:0]  type_decode_in,
   input     [2:0]  function_3_in,
   input            function_7_in,
   output reg[14:0] control_unit_out
 );

 reg [2:0]sel;

 always @* begin
   sel[0] = type_decode_in[5];
   sel[1] = type_decode_in[0] | type_decode_in[1];
   sel[2] = type_decode_in[2] | type_decode_in[6] | type_decode_in[7];
 end
   
 always @* begin
   control_unit_out[14] = type_decode_in[0] | type_decode_in[1] | type_decode_in[2] | type_decode_in[3] | type_decode_in[6] | type_decode_in[7] | type_decode_in[8];
   control_unit_out[13] = type_decode_in[6];  //lw
   control_unit_out[12] = type_decode_in[5];  //sw
   control_unit_out[11] = type_decode_in[4];  //branch
   /* verilator lint_off WIDTH */ case (type_decode_in[3:0])
      0001 : control_unit_out[10:9] = 2'b01;
      0010 : control_unit_out[10:9] = 2'b11;
      0100 : control_unit_out[10:9] = 2'b10;
      1000 : control_unit_out[10:9] = 2'b10;
      default: control_unit_out[10:9] = 0;
   endcase
   control_unit_out[8] = type_decode_in[0] | type_decode_in[1] | type_decode_in[5] | type_decode_in[7] | type_decode_in[6] | type_decode_in[2];
   case (type_decode_in[4:2])
      3'b001 : control_unit_out[7:6] = 2'b11;
      3'b010 : control_unit_out[7:6] = 2'b01;
      3'b100 : control_unit_out[7:6] = 2'b10; 
      default: control_unit_out[7:6] = 0; 
   endcase
   if (type_decode_in == 9'b100000000) begin
      if (function_7_in==1) begin
         case (function_3_in)
            `FUNCT3_ADD  : control_unit_out[5:2] = 4'b0001;
            `FUNCT3_XOR  : control_unit_out[5:2] = 4'b0101;
            `FUNCT3_SLT  : control_unit_out[5:2] = 4'b0111;
            `FUNCT3_OR   : control_unit_out[5:2] = 4'b0011;
            `FUNCT3_SLL  : control_unit_out[5:2] = 4'b1101;
            `FUNCT3_SRA  : control_unit_out[5:2] = 4'b1001; 
            `FUNCT3_SLTU : control_unit_out[5:2] = 4'b1001;
            `FUNCT3_AND  : control_unit_out[5:2] = 4'b0011;
            default:control_unit_out[5:2] = 0; 
         endcase

      end else begin                                //fun-7 = 0 
         case (function_3_in)                          
            `FUNCT3_ADD  : control_unit_out[5:2] = 4'b0000;
            `FUNCT3_XOR  : control_unit_out[5:2] = 4'b0100;
            `FUNCT3_SLT  : control_unit_out[5:2] = 4'b0111;
            `FUNCT3_OR   : control_unit_out[5:2] = 4'b0011;
            `FUNCT3_SLL  : control_unit_out[5:2] = 4'b0101;
            `FUNCT3_SRA  : control_unit_out[5:2] = 4'b0110; 
            `FUNCT3_SLTU : control_unit_out[5:2] = 4'b1000;
            `FUNCT3_AND  : control_unit_out[5:2] = 4'b0010;
            default : control_unit_out[5:2] = 0;
         endcase
      end
      
   end
   if (type_decode_in == 9'b010000000) begin
      if (function_7_in==1) begin
         case (function_3_in)
            `FUNCT3_ADD  : control_unit_out[5:2] = 4'b0000;
            `FUNCT3_XOR  : control_unit_out[5:2] = 4'b0100;
            `FUNCT3_SLT  : control_unit_out[5:2] = 4'b0111;
            `FUNCT3_OR   : control_unit_out[5:2] = 4'b0011;
            `FUNCT3_SLL  : control_unit_out[5:2] = 4'b1101;
            `FUNCT3_SRA  : control_unit_out[5:2] = 4'b1001; 
            `FUNCT3_SLTU : control_unit_out[5:2] = 4'b1000;
            `FUNCT3_AND  : control_unit_out[5:2] = 4'b0010;
            default:control_unit_out[5:2] = 0; 
         endcase

      end else begin                                //fun-7 = 0 
         case (function_3_in)                          
            `FUNCT3_ADD  : control_unit_out[5:2] = 4'b0000;
            `FUNCT3_XOR  : control_unit_out[5:2] = 4'b0100;
            `FUNCT3_SLT  : control_unit_out[5:2] = 4'b0111;
            `FUNCT3_OR   : control_unit_out[5:2] = 4'b0011;
            `FUNCT3_SLL  : control_unit_out[5:2] = 4'b0101;
            `FUNCT3_SRA  : control_unit_out[5:2] = 4'b0110; 
            `FUNCT3_SLTU : control_unit_out[5:2] = 4'b1000;
            `FUNCT3_AND  : control_unit_out[5:2] = 4'b0010;
            default:control_unit_out[5:2] = 0;
         endcase
      end
   end
   if (type_decode_in == 9'b001000000 ) begin
      if (function_3_in == `FUNCT3_SLT) begin
         control_unit_out[5:2] = 4'b0000;
      end
   end
   if (type_decode_in == 9'b000100000 & function_3_in == `FUNCT3_SLT) begin
      control_unit_out[5:2] = 4'b0000;
   end
   if (type_decode_in == 9'b000001000 ) begin
      control_unit_out[5:2] = 4'b1111;
   end
   if (type_decode_in == 9'b000000100 & function_3_in == `FUNCT3_ADD) begin
      control_unit_out[5:2] = 4'b1111;
   end
   if (type_decode_in == 9'b000000010 ) begin
      control_unit_out[5:2] = 4'b0000;
   end
   if (type_decode_in == 9'b000000001) begin
      control_unit_out[5:2] = 4'b0000;
   end
   case (sel)
      3'b001 : control_unit_out[1:0] = 2'b11;
      3'b010 : control_unit_out[1:0] = 2'b01;
      3'b100 : control_unit_out[1:0] = 2'b10; 
      default: control_unit_out[1:0] = 0;
   endcase
 end
endmodule
