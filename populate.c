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

void
populateStructure(wordTable ds, FILE *f)
{
  if (DEBUG) fprintf(stdout,"populateStructure\n");
  char *buffer, *word,*tag;
  int i = 0;
  wordPtr temp;
  buffer = malloc(LINESIZE);
  word = malloc(WORDSIZE);
  tag = malloc(WORDSIZE);
  fgets(buffer,LINESIZE,f);
  while(feof(f) == 0) {
    word = strtok(buffer,"/");
    tag = strtok(NULL,"/");
    temp = makeWord(word,tag);
    ds[i++] = temp;
    if (DEBUG) fprintf(stdout,"String: %s\n",buffer);
    fgets(buffer,LINESIZE,f);
  }
}
wordPtr
makeWord(char *word,char *tag)
{
  if (DEBUG) fprintf(stdout,"populateStructure word:%s tag:%s\n",word,tag);
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
