#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define DEBUG 1
#define MAXWORD 500
#define WORDSIZE 20
#define LINESIZE 100


struct word {
  char *word, *tag;
};

typedef struct word Word;
typedef Word *wordPtr;
typedef wordPtr *wordTable;

struct tagData {
  char *tag;
  int occurences;
};

typedef struct tagData TD;
typedef TD *tagPtr;
typedef tagPtr *tagTable;

struct wrdData {
  char *word;
  int occurences;
};

typedef struct wrdData WD;
typedef WD *wrdPtr;
typedef wrdPtr *wrdTable;


//populate.c
wordTable createStructure(int);
wordPtr makeWord(char*,char*);
void populateStructure(wordTable,FILE*);

//calculate.c
wrdPtr getWord(wordTable,char*);
tagPtr getTag(wordTable,char*);
wrdTable getWrdTable(wordTable);
tagTable getTagTable(wordTable);
void printWrdTable(wrdTable);
void printTagTable(tagTable);
