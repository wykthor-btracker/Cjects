#include "stdio.h"
#include "math.h"
int main(void) 
{
  int primo = 0,achou = 0,u,i,size,primos;
	scanf("%d",&size);
	achou = 0;
	for(i=2;primos<size;i++)
	{
	primo = i;
	for(u=2;u<=sqrt(primo);u++)
		{
		  achou = 0;
		  if(primo%u==0)
		  {
			achou = 1;
			break;
		  }
		}
		if(!achou)
		{
			printf("%d\n",primo);
			primos++;
		}
	}
	  return 0;
}
