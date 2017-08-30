#include "stdio.h"
#include "math.h"
#include "stdlib.h"
int main(void) {
  int size = 1,middle,*array;
  array = (int*)malloc(sizeof(int)*(size+1));
  int primos = 0;
  int primo = 0,i = 0,achou = 0,u;
  while(primo!=404)
		{
			scanf("%d",&primo);
			if(primo==404)
			{
				break;
			}
            achou = 0;
            if(primo <= 1)
            {
				achou = 1;
			}
            for(u=2;u<=sqrt(primo);u++)
            { 
              if(primo%u==0)
              {
                achou = 1;
                break;
              }
            }
            if(!achou)
            {
              array[primos] = primo;
              array = (int*)realloc(array,sizeof(int)*(size+1));
              size++;
              primos++;
            }
		}
  int sorted=0,swap = 0;
  while(sorted == 0)
  {
    swap = 0;
    for(i = 0;i<size-1;i++)
    {
      if(array[i] < array[i+1]){
        middle = array[i];
        array[i] = array[i+1];
        array[i+1] = middle;
        swap = 1;
    }
  }
    if(swap==0 && primos >= 1)
    {
      printf("%d\n",array[0]);
      sorted = 1;
    }
    else if(swap==0)
    {
	  printf("SEM PRIMOS\n");
	  sorted = 1;
	}
  }
  return 0;
}
