//main for homework part 2
#include "header.h"

void
main(int argc,char **argv)
{
  int i,j;
  char word[WORDSIZE] = {0}, tag[WORDSIZE] = {0};
  char *buffer;
  FILE *f;
  wordTable ds;
  if (argc != 2) {
    fprintf(stderr,"Improper number of arguments\n");
    return;
  }
  else {
    f = fopen("trainingCorp.txt","r");
    ds = createStructure(MAXWORD);
    populateStructure(ds,f,word,tag);
  }
} 
