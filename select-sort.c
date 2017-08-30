#include "stdio.h"

int main(void) {
  int size = 3,array[size];
  int middle = 0,inc,inc_2,inc_3,current = 0,sign = 0;
  for(inc=0;inc<size;inc++)
  {
    scanf("%d",&array[inc]);
  }
  for(inc_2=0;inc_2<size;inc_2++)
  {
	printf("step %d at outer for\n",inc_2);
    for(inc_3=size-sign;inc_3<size;inc_3++)
    {
		printf("step %d at inner for\n",inc_3);
        if(array[inc_3]<array[current])
        {
		  printf("set %d as %d\n",current,inc_3);
          current = inc_3;
          printf("%d is the current element\n",current);
        }
    }
    printf("step %d at outer\n",inc_2);
    middle = array[sign];
    array[sign] = array[current];
    array[current] = middle;
    sign++;
  }
  for(inc=0;inc<size;inc++)
  {
	  printf("%d\n",array[inc]);
  }
  return 0;
}
