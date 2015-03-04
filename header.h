#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define DEBUG 1
#define MAXWORD 500
#define WORDSIZE 15
#define LINESIZE 100


struct word {
  char *word, *tag;
};

typedef struct word Word;
typedef Word *wordPtr;
typedef wordPtr *wordTable;

//populate.c
wordTable createStructure(int);
wordPtr makeWord(char*,char*);
void poulateStructure(wordTable,FILE*,char*,char*);
