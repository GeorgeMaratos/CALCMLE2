#include "header.h"

void
findMLE(wordTable ds, wrdTable wT, tagTable tT)
{
  int i,j,k;
  float value;
  if (DEBUG) fprintf(stdout,"findMLE\n");
  for (i=0;i<MAXWORD;i++) {
    if (wT[i] != NULL) 
      for (j=0;j<MAXWORD;j++) {
        if (ds[j] != NULL)
          if (strcmp(ds[j]->word,wT[i]->word) == 0) {
	    for (k=0;k<MAXWORD;k++) {
	      if (tT[k] != NULL)
	        if (strcmp(ds[j]->tag,tT[k]->tag) == 0) {
	          value = calcMLE(wT[i],tT[k],ds);
	          fprintf(stdout,"Word: %s Tag: %s MLE: %f\n",wT[i]->word,tT[k]->tag,value);
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
  fprintf(stdout, "top: %d oc: %d\n",top, tP->occurences);
  value = (float)top / (float)tP->occurences;
  return value;
}
