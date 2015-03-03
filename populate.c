#include "header.h"

wordTable
createStructure(int size)
{
  if (DEBUG) fprintf(stdout,"createStructure\n");
  int i;
  wordTable ret;
  ret = malloc(sizeof(wordPtr) * size);
  for (i=0;i<size;i++) ret[i] = NULL;
  return ret;
}

wordPtr
makeWord(char *word,char *tag)
{
  if (DEBUG) fprintf(stdout,"populateStructure\n");
  char *wrdPtr, *tagPtr;
  int wordSize = strlen(word), tagSize = strlen(tag);
  wordPtr ret;
  ret = malloc(sizeof(Word));
  wrdPtr = malloc(sizeof(wordSize) + 1);
  tagPtr = malloc(sizeof(tagSize) + 1);
  strcpy(wrdPtr,word);
  strcpy(tagPtr,tag);
  ret->word = wrdPtr;
  ret->tag = tagPtr;
  return ret;
}
