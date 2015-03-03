//main for homework part 2
#include "header.h"

void
main(int argc,char **argv)
{
  int i,j;
  char word[WORDSIZE], tag[WORDSIZE];
  FILE *f;
  wordTable ds;
  if (argc != 2) {
    fprintf(stderr,"Improper number of arguments\n");
    return;
  }
  else {
    f = fopen("trainingCorp.txt");
    ds = createStructure(MAXWORD);
    for (i=0;i<MAXWORD;i++) {
      for (j=0;j<WORDSIZE;j++) {
        word[j] = '\0';
        tag[j] = '\0';
      }
    }
  }
} 
