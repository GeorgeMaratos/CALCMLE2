#include "header.h"
int
isUsed(wordTable table, wrdPtr wP, tagPtr tP)
{
  int i;
  for (i=0;i<MAXWORD;i++) {
    if (table[i] != NULL) {
      if (strcmp(table[i]->word,wP->word) == 0 &&
  	  strcmp(table[i]->tag,tP->tag) == 0)
        return 1;
    }
  }
  return 0;
}

void
findMLE(wordTable ds, wrdTable wT, tagTable tT)
{
  wordTable array;
  int i,j,k,l = 0;
  float value;
  if (DEBUG) fprintf(stdout,"findMLE\n");
  array = malloc(sizeof(wordPtr) * MAXWORD);
  for (i=0;i<MAXWORD;i++) array[i] = NULL;
  for (i=0;i<MAXWORD;i++) {
    if (wT[i] != NULL) 
      for (j=0;j<MAXWORD;j++) {
        if (ds[j] != NULL)
          if (strcmp(ds[j]->word,wT[i]->word) == 0) {
	    for (k=0;k<MAXWORD;k++) {
	      if (tT[k] != NULL)
	        if (strcmp(ds[j]->tag,tT[k]->tag) == 0) {
	          value = calcMLE(wT[i],tT[k],ds);
	          if (isUsed(array,wT[i],tT[k]) == 0) {
		    fprintf(stdout,"Word: %s Tag: %s MLE: %f\n",wT[i]->word,tT[k]->tag,value);
		    array[l++] = makeWord(wT[i]->word,tT[k]->tag); 
		  }
		}	
	    }
          }
      }
    
  }
}

float calcMLE(wrdPtr wP, tagPtr tP,wordTable ds)
{
  if (DEBUG) fprintf(stdout, "calMLE\n");
  float value;
  int i, top = 0;
  for (i=0;i<MAXWORD;i++) {
    if (ds[i] != NULL) {
      if (strcmp(ds[i]->word,wP->word) == 0 && 
	strcmp(ds[i]->tag,tP->tag) == 0)
        top++;
    }
  }
  if (DEBUG) fprintf(stdout, "top: %d oc: %d\n",top, tP->occurences);
  value = (float)top / (float)tP->occurences;
  return value;
}
