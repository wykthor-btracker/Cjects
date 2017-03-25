#include "stdio.h"
#include "math.h"
int main(void) {
  int primo = 0,achou = 0,u;
	scanf("%d",&primo);
	achou = 0;
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
		printf("SIM\n");
	}
	else
	{
		printf("NAO\n");
	}
  return 0;
}
