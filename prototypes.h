//Alex Pospesel
//ID: 001146589
//NetID: ap212246
//Email: apospesel@albany.edu
//CSI 402
//Program 4
//Due 4/24/16

//error.c file
void die(char * message);
void debug(char * message);
void checkPoint();
FILE * checkOpen(char * name, char * mode, char * failMessage);
void * checkMalloc(size_t s);

//rootName.c
char* removeAfter(char* fileName, char charRemoved);

//readFile.c
line* readFile(FILE* inFile);
void addNode(char* string, line * head, int lineNum);
opcodeNode* createOpcodeList();
void addOpcodeNode(char* instruction, int opcode, char type, opcodeNode* head);
char* replace_str(char *str, char *sub, char rep);

//passOne.c_str
symbolNode* passOne(line* line);
void addSymbol(char* symbol, int LC, symbolNode* symbolNodeHead);
