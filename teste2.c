#include "stdio.h"

int main(void) {
  int soma=0,size,i,current;
  scanf("%d",&size);
  for(i=0;i<size;i++)
  {
    scanf("%d",&current);
    soma+=current;
  }
  printf("%d",soma);
}
