//Alex Pospesel
//ID: 001146589
//NetID: ap212246
//Email: apospesel@albany.edu
//CSI 402
//Program 4
//Due 4/24/16

#include "headers.h"
#include "prototypes.h"

char* removeAfter(char* fileName, char charRemoved){

	char* root;

	char dotRemoved = charRemoved;
	
	char* subString;

	//malloc root to return to main
	root = checkMalloc(sizeof(char) * (strlen(fileName) + 1));
	
	//malloc substring
	subString = checkMalloc(sizeof(char) * (strlen(fileName) + 1));
	
	//copy fileName into root
	strcpy(root, fileName);
	
	//check to see if a '.' is contained in root name
	if((subString = strrchr(root, dotRemoved)) != NULL){		
		//must be a '.' present
		//strip the last '.'
		root[strlen(root) - strlen(subString)] = '\0';
	}


	return root;
}