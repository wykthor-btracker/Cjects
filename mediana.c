#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int size = 1;	
	int *array = (int*)malloc(size*sizeof(int));
	int curr,i;
	float mediana;
	while(scanf("%d",&curr) != EOF)
	{		
		array = (int*)realloc(array,(2*size)*sizeof(int));
		array[size-1] = curr;
		size++;	
	}
	size--;
  int sorted=0,swap = 0;
  int middle;
  for(i = 0;i<size;i++)
  {
    scanf("%d",&array[i]);
  }
  while(sorted == 0)
  {
    swap = 0;
    for(i = 0;i<size-1;i++)
    {
      if(array[i] > array[i+1])
      {
        middle = array[i];
        array[i] = array[i+1];
        array[i+1] = middle;
        swap = 1;
	  }
	}
	int index = size-1;
    if(swap==0)
    {
	  if(size%2!=0)
	  {
		  mediana = array[(index+1)/2];
		  printf("%.0f",mediana);
	  }
	  else
	  { 
		  mediana = (float)(array[index/2] + array[(index/2)+1])/2;
		  printf("%.1f",mediana);
	  }
	  printf("\n");
      sorted = 1;
    }
  }
	return 0;
}

