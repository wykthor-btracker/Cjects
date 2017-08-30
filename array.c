#include "stdio.h"
int main(void) {
  int i,const size = 6,index = 0,last;
  int array[size] = {1,2,3,4,5};
  for(i=0;i<size;i++)
  {
    last = index;
    index = (index+1)%size;
    array[last] = array[index];
  }
  for(i=0;i<size;i++)
  {
    printf("%d ",array[i]);
  }
  return 0;
}
