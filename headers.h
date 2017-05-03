//Alex Pospesel
//ID: 001146589
//NetID: ap212246
//Email: apospesel@albany.edu
//CSI 402
//Program 4
//Due 4/24/16

//include
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//definitions
#define MAX_SYMBOL_LEN 9
#define MAX_INST_LEN 6

//structs
typedef struct line{
	int hasLabel;
	int hasInstruct;
	int lineNum;
	int LC;
	char label[MAX_SYMBOL_LEN];
	char instruction[MAX_INST_LEN];
	char operands[3][9];
	char line[80];
	struct line* next;
}line;

//Symbol Table
typedef struct symbolNode{
	char symbol[MAX_SYMBOL_LEN];
	int LC;
	struct symbolNode* next;
}symbolNode;

//Machine Opcode table
typedef struct opcodeNode{
	char instruction[MAX_INST_LEN];
	int opcode;
	char type;
	struct opcodeNode* next;
}opcodeNode;

//Error type
typedef enum errorType{
	undefinedSymbol,
	multiplyDefinedSymbol,
	illegalOpcode
}errorType;

//Error list
typedef struct errorNode{
	errorType type;
	int line;
}errorNode;
