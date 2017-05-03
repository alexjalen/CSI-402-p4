//Alex Pospesel
//ID: 001146589
//NetID: ap212246
//Email: apospesel@albany.edu
//CSI 402
//Program 4
//Due 4/24/16

#include "headers.h"
#include "prototypes.h"

int main (int argc, char *argv[]){

	//variables
	FILE* inFile;
	char* root;
	
	//line struct
	line* progLineArray;
	
	//opcodeNode struct
	opcodeNode* opcodeNodeList;

	//check if number of cmd line arguements are correct
	if(argc != 2){
		die("Invalid number of arguments.");
	}

	//open input file
	inFile = checkOpen(argv[1], "r", "Input file failed to open.");

	//get root name
	root = removeAfter(argv[1], '.');
	
	//printf("The rootName is: %s\n", root);

	//read each line into the progLineArray and malloc each part of the list
	progLineArray = readFile(inFile);
	//increment to next address of linked list
	progLineArray = progLineArray->next;
	
	
	
	
	//pass 1 of assembler
	//progLineArray = passOne(progLineArray);
	
	/*
	//TESTING printing out the file from the struct
	printf("Print the file from the struct.\n");
	while(progLineArray != NULL){
		printf("%d\t%s", progLineArray->lineNum, progLineArray->line);
		progLineArray = progLineArray->next;
	}
	*/
	
	//create opcodeNode list
	opcodeNodeList = createOpcodeList();
	
	opcodeNodeList = opcodeNodeList->next;
	
	/*
	printf("Print the opcodeNodeList.\n");
	while(opcodeNodeList != NULL){
		printf("%s\t%d\t%c\n", opcodeNodeList->instruction, opcodeNodeList->opcode, opcodeNodeList->type);
		opcodeNodeList = opcodeNodeList->next;
	}
	*/
	
	
	//create symbol table variables and run passOne
	symbolNode* symbolList = passOne(progLineArray);
	
	//increment symbolNode to next node for bugs
	symbolList = symbolList->next;
	
	
	char *symbolFileName;
	
	symbolFileName = checkMalloc(sizeof(char) * (strlen(root) + 5));
	
	sprintf(symbolFileName, "%s.sym", root);
	
	FILE *symbolFile = checkOpen(symbolFileName, "w", "Symbol file failed to open.");
	
	while(symbolList != NULL){
		fprintf(symbolFile, "%s\t%d\n", symbolList->symbol, symbolList->LC);
		symbolList = symbolList->next;
	}
	
	char *objFileName;
	
	objFileName = checkMalloc(sizeof(char) * (strlen(root) + 5));
	
	sprintf(objFileName, "%s.obj", root);
	
	FILE *objFile = checkOpen(objFileName, "w", "Object file failed to open.");
	
	//close file
	fclose(inFile);
	fclose(symbolFile);
	fclose(objFile);
	
	//end program
	return 0;
	
}//end main