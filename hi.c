/*
Caleb Luh
4/18/2024
CDA 3103 Final Project
Dr. Mesut Ozdag
*/

#include "spimcore.h"

void ALU(unsigned A, unsigned B, char ALUControl, unsigned *ALUresult, char *Zero) {
	// Switch to control which ALU control gets executed
	switch ((int) ALUControl)
	{
		// 000: Z = A + B
	case 000:
		*ALUresult = A + B;
		break;

		// 001: Z = A - B
	case 001:
		*ALUresult = A - B;
		break;

		// 010: if A < B, Z = 1; otherwise, Z = 0 (A and B are signed integers)
	case 010:
		if ((signed)A < (signed)B) {
			*ALUresult = 1;
		} else {
			*ALUresult = 0;
		}
		break;

		// 011: if A < B, Z = 1; otherwise, Z = 0 (A and B are unsigned integers)
	case 011:
		if (A < B) {
			*ALUresult = 1;
		} else {
			*ALUresult = 0;
		}
		break;

    // 100: Z = A AND B (bitwise)
	case 100:
		*ALUresult = A & B;
		break;

    // 101: Z = A OR B (bitwise)
	case 101:
		*ALUresult = A | B;
		break;

    // 110: Z = Shift left B by 16 bits
	case 110:
		B << 16;
		break;

    // 111: Z = NOT A (bitwise)
	case 111:
		*ALUresult = ~A;
		break;

	}
	// Check for zeroes
	// If zero = 1, the value is zero.
	if(*ALUresult == 0) {
		*Zero = 1;
	}
	// When Zero = 0, the value is not zero.
	else {
		*Zero = 0;
	}
}

int instruction_fetch(unsigned PC, unsigned *Mem, unsigned *instruction) {
	// Check the memory index
	unsigned MemoryIndex = PC >> 2;

	// Check if multiple of 4 word-aligned format
    if (PC % 4 == 0) {
           *instruction = Mem[MemoryIndex];
           return 0;
    }
	// Exit if not
    else {
		return 1;
	}
}

void instruction_partition(unsigned instruction, unsigned *op, unsigned *r1,unsigned *r2, unsigned *r3, unsigned *funct, unsigned *offset, unsigned *jsec) {
	unsigned rPartition		= 0x1f;
	unsigned functopPartition	= 0x0000003f;
	unsigned offsetPartition	= 0x0000ffff;
	unsigned jsecPartition	= 0x03ffffff;

	// Apply partitions and shifts
	*op		= (instruction >> 26) & functopPartition;	// instruction [31-26]
	*r1		= (instruction >> 21) & rPartition; // instruction [25-21]
	*r2		= (instruction >> 16) & rPartition; // instruction [20-16]
	*r3		= (instruction >> 11) & rPartition; // instruction [15-11]
	*funct	= instruction & functopPartition; // instruction [5-0]
	*offset	= instruction & offsetPartition; // instruction [15-0]
	*jsec	= instruction & jsecPartition; // instruction [25-0]
}

int instruction_decode(unsigned op, struct_controls *controls)
{
	// Switch for different op codes to decode
	 switch(op) {
		case 0:   // Case for R Type
   			       controls->RegDst = 1;
                   controls->Jump = 0;
			       controls->Branch = 0;
			       controls->MemRead = 0;
			       controls->MemtoReg = 0;
			       controls->ALUOp = 7;
			       controls->MemWrite = 0;
			       controls->ALUSrc = 0;
			       controls->RegWrite = 1;
                   break;

         case 8:   // Case for add
   			       controls->RegDst = 0;
                   controls->Jump = 0;
			       controls->Branch = 0;
			       controls->MemRead = 0;
			       controls->MemtoReg = 0;
			       controls->ALUOp = 0;
			       controls->MemWrite = 0;
			       controls->ALUSrc = 1;
			       controls->RegWrite = 1;
                   break;

         case 10:  // Case for set less than
   			       controls->RegDst = 0;
                   controls->Jump = 0;
			       controls->Branch = 0;
			       controls->MemRead = 0;
			       controls->MemtoReg = 0;
			       controls->ALUOp = 2;
			       controls->MemWrite = 0;
			       controls->ALUSrc = 1;
			       controls->RegWrite = 1;
                   break;

          case 11:  // Case for set less than unsigned
   			       controls->RegDst = 0;
                   controls->Jump = 0;
			       controls->Branch = 0;
			       controls->MemRead = 0;
			       controls->MemtoReg = 0;
			       controls->ALUOp = 3;
			       controls->MemWrite = 0;
			       controls->ALUSrc = 1;
			       controls->RegWrite = 1;
                   break;

          case 4:  // Case for Branch
   			       controls->RegDst = 2;
                   controls->Jump = 0;
			       controls->Branch = 1;
			       controls->MemRead = 0;
			       controls->MemtoReg = 2;
			       controls->ALUOp = 1;
			       controls->MemWrite = 0;
			       controls->ALUSrc = 0;
			       controls->RegWrite = 0;
                   break;

          case 2:  //Case for Jump
   			       controls->RegDst = 0;
                   controls->Jump = 1;
			       controls->Branch = 0;
			       controls->MemRead = 0;
			       controls->MemtoReg = 0;
			       controls->ALUOp = 0;
			       controls->MemWrite = 0;
			       controls->ALUSrc = 0;
			       controls->RegWrite = 0;
                   break;

          case 35:  //Case for Load
   			       controls->RegDst = 0;
                   controls->Jump = 0;
			       controls->Branch = 0;
			       controls->MemRead = 1;
			       controls->MemtoReg = 1;
			       controls->ALUOp = 0;
			       controls->MemWrite = 0;
			       controls->ALUSrc = 1;
			       controls->RegWrite = 1;
                   break;

          case 15:  // Case for load unsigned
   			       controls->RegDst = 0;
                   controls->Jump = 0;
			       controls->Branch = 0;
			       controls->MemRead = 0;
			       controls->MemtoReg = 0;
			       controls->ALUOp = 6;
			       controls->MemWrite = 0;
			       controls->ALUSrc = 1;
			       controls->RegWrite = 1;
                   break;

          case 43:  // Case for Store word
   			       controls->RegDst = 2;
                   controls->Jump = 0;
			       controls->Branch = 0;
			       controls->MemRead = 0;
			       controls->MemtoReg = 2;
			       controls->ALUOp = 0;
			       controls->MemWrite = 1;
			       controls->ALUSrc = 1;
			       controls->RegWrite = 0;
                   break;

				   // Return 1 if exit
          default:
				   return 1;

     }
       return 0;
}

void read_register(unsigned r1, unsigned r2, unsigned *Reg, unsigned *data1, unsigned *data2) {
	// Read the registers addressed by r1 and r2 from Reg, and write the read values to data1 and data2 respectively
	*data1 = Reg[r1];
	*data2 = Reg[r2];
}

void sign_extend(unsigned offset, unsigned *extended_value) {
	// If negative sign extend for negative
	unsigned extend1s = 0xFFFF0000;
	unsigned Negative = offset >> 15;

    if (Negative == 1)
         *extended_value = offset | extend1s;

    // Otherwise sign extend normally
    else
         *extended_value = offset & 0x0000ffff;

}

int ALU_operations(unsigned data1, unsigned data2, unsigned extended_value, unsigned funct, char ALUOp, char ALUSrc, unsigned *ALUresult, char *Zero) {
	// Check which data we are opperating on by ALU src
	if(ALUSrc == 1){
		data2 = extended_value;
	}

	// All ALUOps just send instructions to ALU which updates ALU result
	// ALUOP 7 is R type insturction which requires use of funct
	if(ALUOp == 7){
		// Find the proper ALUOp for each R type instruction
		switch(funct) {

			// Add
			case 32:
					ALUOp = 0;
					break;
			// Sub
			case 34:
					ALUOp = 1;
					break;
			// Set Less Signed
			case 42:
					ALUOp = 2;
					break;
			// Set Less Unsigned
			case 43:
					ALUOp = 3;
					break;
			//And
			case 36:
					ALUOp = 4;
					break;
			// Or
			case 37:
					ALUOp = 5;
					break;
			// Shift Left extended value 16
			case 6:
					ALUOp = 6;
					break;
			// Nor
			case 39:
					ALUOp = 7;
					break;
			// Base case to return
			default:
					return 1;

		}
		//Send to ALU for funct
		ALU(data1,data2,ALUOp,ALUresult,Zero);

	} else {
	// Send to ALU for non funct
	ALU(data1, data2, ALUOp, ALUresult, Zero);
	}

	//Return
	return 0;


}

int rw_memory(unsigned ALUresult, unsigned data2, char MemWrite, char MemRead, unsigned *memdata, unsigned *Mem) {

	//if reading from memory
	if (MemRead == 1) {
		if((ALUresult % 4) == 0) {
			*memdata = Mem[ALUresult >> 2];
		}
		// Improper address return
		else {
			return 1;
		}

	}

	// If writting to memory
	if (MemWrite == 1) {
		if((ALUresult % 4) == 0){
			Mem[ALUresult >> 2] = data2;
		}
		// Improper address return
		else{
			return 1;
		}
	}

             return 0;
}

void write_register(unsigned r2, unsigned r3, unsigned memdata, unsigned ALUresult, char RegWrite, char RegDst, char MemtoReg, unsigned *Reg) {
	// Check if writing
	if(RegWrite == 1){
		 // If mem to register
		 if (MemtoReg == 1 && RegDst == 0) {
			Reg[r2] = memdata;
		 }
		 // If Mem to register r3
		 else if(MemtoReg == 1 && RegDst == 1){
			 Reg[r3] = memdata;
		 }
		 // If result to register
		 else if (MemtoReg == 0 && RegDst == 0) {
			Reg[r2] = ALUresult;
		 }
		 // If result to register result
		 else if (MemtoReg == 0 && RegDst == 1){
			Reg[r3] = ALUresult;
		 }
	}
}

void PC_update(unsigned jsec, unsigned extended_value, char Branch, char Jump, char Zero, unsigned *PC) {
	// Always increment the PC by 4
	*PC += 4;

	// If branching and zero, add extended value
	if(Zero == 1 && Branch == 1){
		*PC += extended_value << 2;
	}

	// If jumping, shift instruction and combine with PC
	if(Jump == 1){
		*PC = (jsec << 2) | (*PC & 0xf0000000);
	}
}
