#include "header.h"

wrdPtr
getWord(wordTable ds,char *word)
{
  if (DEBUG) fprintf(stdout,"getWord\n");
  int i,wordCount = 0;
  wrdPtr ret;
  for (i=0;i<MAXWORD;i++) {
    if (ds[i] != NULL) {
      if (strcmp(ds[i]->word,word) == 0)
              wordCount++;
    }
  }
  ret = malloc(sizeof(WD));
  ret->word = word;
  ret->occurences = wordCount;
  return ret;
}

tagPtr
getTag(wordTable ds,char *tag)
{
  if (DEBUG) fprintf(stdout,"getTag\n");
  int i,tagCount = 0;
  tagPtr ret;
  for (i=0;i<MAXWORD;i++) {
    if (ds[i] != NULL) {
      if (strcmp(ds[i]->tag,tag) == 0)
              tagCount++;
    }
  }
  ret = malloc(sizeof(TD));
  ret->tag = tag;
  ret->occurences = tagCount;
  return ret;
}

int
inWrdTable(wrdTable wT,char *word)
{
  if (DEBUG) fprintf(stdout,"inWrdTable\n");
  int i;
  for (i=0;i<MAXWORD;i++) {
    if (wT[i] != NULL)
      if (strcmp(wT[i]->word,word) == 0)
        return 1;
  }
  return 0;
}

int
inTagTable(tagTable wT,char *tag)
{
  if (DEBUG) fprintf(stdout,"inTagTable\n");
  int i;
  for (i=0;i<MAXWORD;i++) {
    if (wT[i] != NULL)
      if (strcmp(wT[i]->tag,tag) == 0)
        return 1;
  }
  return 0;
}

wrdTable
getWrdTable(wordTable ds)
{
  if (DEBUG) fprintf(stdout,"getWrdTable\n");
  int i,j = 0;
  wrdTable ret;
  ret = malloc(sizeof(wrdPtr) * MAXWORD);
  for (i=0;i<MAXWORD;i++) ret[i] = NULL;
  for (i=0;i<MAXWORD;i++) {
    if (ds[i] != NULL) {
      if (inWrdTable(ret,ds[i]->word) == 0)
	ret[j++] = getWord(ds,ds[i]->word);
    }
  }
  if (DEBUG) printWrdTable(ret);
  return ret;
}

tagTable
getTagTable(wordTable ds)
{
  if (DEBUG) fprintf(stdout,"getTagTable\n");
  int i,j = 0;
  tagTable ret;
  ret = malloc(sizeof(tagPtr) * MAXWORD);
  for (i=0;i<MAXWORD;i++) ret[i] = NULL;
  for (i=0;i<MAXWORD;i++) {
    if (ds[i] != NULL) {
      if (inTagTable(ret,ds[i]->tag) == 0)
        ret[j++] = getTag(ds,ds[i]->tag);
    }
  }
  if (DEBUG) printTagTable(ret);
  return ret;
}

void
printWrdTable(wrdTable wT)
{
  int i;
  for (i=0;i<MAXWORD;i++) {
    if (wT[i] != NULL)
      fprintf(stdout,"word: %s / %d\n",wT[i]->word, wT[i]->occurences);
  }
}

void
printTagTable(tagTable tT)
{
  int i;
  for (i=0;i<MAXWORD;i++) {
    if (tT[i] != NULL)
      fprintf(stdout,"tag: %s / %d\n",tT[i]->tag, tT[i]->occurences);
  }
}

