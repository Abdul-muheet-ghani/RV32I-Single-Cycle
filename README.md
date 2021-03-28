# RV32I Single Cycle
## Design By **_`Abdul Muheet Ghani`_**
![single cycle](https://user-images.githubusercontent.com/81433387/112760956-4b2d4080-9012-11eb-8a8a-48a488396f03.PNG)

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
