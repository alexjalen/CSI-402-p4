//Alex Pospesel
//ID: 001146589
//NetID: ap212246
//Email: apospesel@albany.edu
//CSI 402
//Program 4
//Due 4/24/16

#include "headers.h"
#include "prototypes.h"

symbolNode* passOne(line* line){
	
	//symbolNode variable
	symbolNode* symbolList = checkMalloc(sizeof(struct symbolNode));
	symbolList->next = NULL;
	
	//temp line variable
	char* pointerLine = checkMalloc(sizeof(char) * 80);
	
	int LC = 0;
	
	//TESTING
	int lineNumber = 1;
	//read each line looking for ':' to denote a label is present
	while(line != NULL){
		
		//copy line[] into a line pointerLine
		strcpy(pointerLine, line->line);
		
		//change all # to '\0'
		pointerLine = replace_str(pointerLine, "#", '\0');
		
		//copy back the changed line
		strcpy(line->line, pointerLine);
		
		//TESTING
		//printf("Sizeof line: %d\t", strlen(line->line));
		
		//line->line = replace_str(line->line, "#", "\n");
		//test for the ':'
		if((strchr(line->line, ':')) != NULL){
			//if ':' located, symbol must be present
			//read symbol and store it
			sscanf(line->line, "%[^:]", line->label);
			
			//printf("Label is: %s\n", line->label);
			
			//increment hasLabel to 1
			line->hasLabel = 1;
			
			//set LC counter
			line->LC = LC;
			
			//add to symbolList
			addSymbol(line->label, LC, symbolList);
			
			
			//increase LC counter
			LC++;
		}else{

			if(strlen(line->line) > 16){
				//line must have data on it
				//check line for .text and .data
				char dataOrText[30];

				sscanf(line->line, "%s", dataOrText);

				//TESTING
				//printf("dataOrText is: %s\n", dataOrText);

				if((strcmp(dataOrText, ".text") == 0) || (strcmp(dataOrText, ".data") == 0)){
					//must have .text or .data
					//do not increment LC

					//TESTING
					//printf("DATA OR TEXT\n");

				}else if(strcmp(dataOrText, "hlt") == 0){
					//set LC counter
					line->LC = LC;
				
					//increment the LC counter
					LC++;

				//}else if(strcmp()){

				}else{
					if(line->hasLabel == 1){
						//do not increment
					}else{
						//set LC counter
						line->LC = LC;
				
						//increment the LC counter
						LC++;
					}

					
				}

			}
			//doesnt have label make it 0
			line->hasLabel = 0;
			
		}

		//TESTING
		//printf("Label: %d\n", line->hasLabel);


		/*
		if(strlen(line->line) > 22){
				//if line is > 2, then increment the LC, more data must be here.
				//set LC counter
				line->LC = LC;
				
				//increment the LC counter
				LC++;
		}
		*/
		
		//TESTING
		//printf("line: %d LC is: %d\n", lineNumber++, LC);
		
		//increment to next link
		line = line->next;
	}
	
	return symbolList;
}

void addSymbol(char* symbol, int LC, symbolNode* symbolNodeHead){
	
		
		symbolNode *current = symbolNodeHead;
		symbolNode *newNode = checkMalloc(sizeof(struct symbolNode));

		
		//copy in data
		strcpy(newNode->symbol, symbol);
		newNode->LC = LC;
		
		//set next link to null because at end of list
		newNode->next = NULL;
		
		//go to end of LL
		while(current->next != NULL){
			current = current->next;
		}    
		
		//set current to newNode
		current->next = newNode;
		
}