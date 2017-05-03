//Alex Pospesel
//ID: 001146589
//NetID: ap212246
//Email: apospesel@albany.edu
//CSI 402
//Program 4
//Due 4/24/16

#include "headers.h"
#include "prototypes.h"

line* readFile(FILE* inFile){
	//read each line of the file
	//malloc and store line number and line in each linked list struct
	line *head;
	
	int lineNum = 1;
	char line[80];
	
	//line = checkMalloc(sizeof(char) * 80);
	
	while(fgets(line, 80, inFile) != NULL){
		
		//inset line at end of linked list
		addNode(line, head, lineNum);
		
		//increment lineNumber
		lineNum++;
		
	}
	
	//return the progLineArray
	return head;
}

void addNode(char* string, line* head, int lineNum){
	
	line *current = head;
    line *newNode = checkMalloc(sizeof(struct line));

	
    //copy in data
	strcpy(newNode->line, string);
	newNode->lineNum = lineNum;
	
	//set next link to null because at end of list
	newNode->next = NULL;
	
	//go to end of LL
    while(current->next != NULL){
        current = current->next;
    }    
	
	//set current to newNode
    current->next = newNode;
	
}

opcodeNode* createOpcodeList(){
	
	opcodeNode *head = checkMalloc(sizeof(struct opcodeNode));
	head->next = NULL;
	
	//R-format
	addOpcodeNode("hlt", 0, 'R', head);
	addOpcodeNode("add", 1, 'R', head);
	addOpcodeNode("sub", 2, 'R', head);
	addOpcodeNode("mul", 3, 'R', head);
	addOpcodeNode("div", 4, 'R', head);
	addOpcodeNode("mod", 5, 'R', head);
	addOpcodeNode("move", 6, 'R', head);
	addOpcodeNode("and", 7, 'R', head);
	addOpcodeNode("or", 8, 'R', head);
	addOpcodeNode("xor", 9, 'R', head);
	addOpcodeNode("com", 10, 'R', head);
	addOpcodeNode("sll", 11, 'R', head);
	addOpcodeNode("srl", 12, 'R', head);
	addOpcodeNode("sra", 13, 'R', head);
	addOpcodeNode("jr", 14, 'R', head);
	addOpcodeNode("rdr", 15, 'R', head);
	addOpcodeNode("prr", 16, 'R', head);
	addOpcodeNode("prh", 17, 'R', head);
	
	//I-format
	addOpcodeNode("li", 18, 'I', head);
	addOpcodeNode("addi", 19, 'I', head);
	addOpcodeNode("subi", 20, 'I', head);
	addOpcodeNode("muli", 21, 'I', head);
	addOpcodeNode("divi", 22, 'I', head);
	addOpcodeNode("modi", 23, 'I', head);
	addOpcodeNode("lwb", 24, 'I', head);
	addOpcodeNode("swb", 25, 'I', head);
	
	//J-format
	addOpcodeNode("lwa", 26, 'J', head);
	addOpcodeNode("swa", 27, 'J', head);
	addOpcodeNode("j", 28, 'J', head);
	addOpcodeNode("jal", 29, 'J', head);
	addOpcodeNode("jeq", 30, 'J', head);
	addOpcodeNode("jne", 31, 'J', head);
	addOpcodeNode("jlt", 32, 'J', head);
	addOpcodeNode("jle", 33, 'J', head);
	addOpcodeNode("jgt", 34, 'J', head);
	addOpcodeNode("jge", 35, 'J', head);
	
	return head;
}

void addOpcodeNode(char* instruction, int opcode, char type, opcodeNode* head){
	
	opcodeNode *current = head;
    opcodeNode *newNode = checkMalloc(sizeof(struct opcodeNode));
	
	//copy in data
	strcpy(newNode->instruction, instruction);
	newNode->opcode = opcode;
	newNode->type = type;
	
	//set next link to null because at end of list
	newNode->next = NULL;
	
	//go to end of LL
	while(current->next != NULL){
		current = current->next;
	} 
	
	//set current to newNode
	current->next = newNode;
}


char* replace_str(char *str, char *sub, char rep){
  
  char* buffer = checkMalloc(sizeof(char) * 80);
  char* p;
 
  if(! (p = strstr(str, sub)))  // Is 'orig' even in 'str'?
    return str;
 
  strncpy(buffer, str, p - str); // Copy characters from 'str' start to 'orig' st$
  buffer[p - str] = '\0';
 
  sprintf(buffer + (p - str), "%c%s", rep, p + strlen(sub));
 
  return buffer;
}


