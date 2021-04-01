# RV32I Single Cycle
![single cycle](https://user-images.githubusercontent.com/81433387/112760956-4b2d4080-9012-11eb-8a8a-48a488396f03.PNG)

## Description
This repository contains RISC-V Single Cycle 32 Bit Processor simulation on Logic Simulator called [Logisim](http://www.cburch.com/logisim/download.html "website"). This circuit contains 32 bit ALU, 32 bit Data Bus, 16KB ROM/RAM, 12 Bit Address Bus for both RAM MAR(memory address register). Register File contains 32 Registers with data width of 32 bits. Troubleshooting codes used to verify all the circuit components.

## Component
- ALU
- Register File
- Memory Address Register
- Immediate Generation
- Control Unit
  - Type Decode
  - Control Decode
- RAM
- Branch Circuit
- Program Counter

## Refrence Material 
- Book [David_A._Patterson,_John_L._Hennessy](https://drive.google.com/file/d/1zJ5JT1A-pmruRShfD6ikY52tFlcvrdYB/view "book")
- Online RV32I Simulator [Venus](https://venus.cs61c.org/ "online simulator")

## Under the Guidance
- [Zeeshan Raffique](https://github.com/zeeshanrafique23 "sir zeeshan profile")
- [Sajjad Ahmed](https://github.com/sajjadahmed677 "sie ajjad profile")

## Pre-Req Tools
- Logisim Software [Logisim](http://www.cburch.com/logisim/download.html "website")
- Reference book for help [David_A._Patterson,_John_L._Hennessy](https://drive.google.com/file/d/1zJ5JT1A-pmruRShfD6ikY52tFlcvrdYB/view "book")
- Venus online simulator [Venus](https://venus.cs61c.org/ "online simulator")

## Designing procedure

At first learn the basic instructions of the RV32I Instruction Set Architecture and learn their functionality. To learn the backend working use Venus Online RV32I Simulator. This Simulator helps grasp the working behind the instruction much faster. On the Logic Simulator software first start with the program counter and memory address register. Then develop the circuit for the immediate generation which uses full instruction and PC to generate respective immediate. after that create register file with 32 registers each 32-bit data width. This register file takes 5-bit address to select one of the 32 registers and write data to it using register enable wire. two 5-bit address RS1 and RS2 are to read one of the 32 registers simultaneously. Now make 32 Bit ALU with 4-bit ALU operation Select which selects which operation to perform according to the instruction. After completing create type decoder which uses 7-bit opcode to decode the type of the instruction. Then in control Decoder depending upon the type of instruction, function3 and function7 different components are controlled. Integrate type decode and control decode, and this will become your control unit. Add RAM and configure its data bits to 32bit and address width to 12 bits. To handle branch instruction Branch circuit is now having to be created using the simple comparators and depending upon the RS1 and RS2 conditional jump is done if branch is true. In the end Add a 32-bit adder for jalr as this instruction requires two additions. One ALU cannot perform 2 operation on a single cycle. Connect the wiring using the splitters, multiplexers, constants, tunnels, and clocks. To troubleshoot the circuit, start with the simpler instructions e.g.; add, addi and watch the circuit behavior using temporary register outputs. To load the machine code on the Instruction Register, simulate the code on Venus then using dump feature copy the machine code and create xyzcode.mem extension file using All file saving option on notepad :

### Create a .txt file and place the hexadecimal code of your instructions simulated on Venus (RISC-V Simulator)
Each instruction's hexadecimal code must be on seperate line as following. This program consists of 27 instruction
## Dump code
```
00200113
00300193
00310233
40218233
00001697
00001737
003172B3
00117293
00316333
00116313
003143B3
00114393
00311433
00111413
003154B3
004000EF
00628A63
00115493
00312533
00112513
003135B3
00113593
40315633
40115613
06400167
00422023
00022203
```
#### The above instruction performs the following steps
## Assembly Code
```
addi x2,x0,2
addi x3,x0,3
add x4,x2,x3
sub x4,x3,x2
auipc x13,1
lui x14,1
and x5,x2,x3
andi x5,x2,1
or x6,x2,x3
ori x6,x2,1
xor x7,x2,x3
xori x7,x2,1
sll x8,x2,x3
slli x8,x2,1
srl x9,x2,x3
jal up
up:
  beq x5,x6,label
  srli x9,x2,1
  slt x10,x2,x3
  slti x10,x2,1
sltu x11,x2,x3
label:
sltiu x11,x2,1
sra x12,x2,x3
srai x12,x2,1
jalr x2,x0,0x64
sw x4,0x0(x4)
lw x4,0x0(x4)
```
#### Save the Dump code in `all files` formate and load image in Instruction Memory

---
>keep smiling and work harder
***
