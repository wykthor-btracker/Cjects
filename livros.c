#include <stdio.h>
#include <stdlib.h>
int main()
{
  int pags,curr = 0,first,last = 0,max = 0,today;
  scanf("%d",&pags);
  while(scanf("%d",&first) != EOF)
  {
    today = abs(last-first);
    curr+=today;
    if(today>max) max = today;
    last = first;
  }
  printf("%d\n%d\n",curr,max);
  return 0;
}
