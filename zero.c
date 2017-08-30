#include "stdio.h"
#include "math.h"
long int fat(long int quod)
{
  long int i,sum=1;
  for(i=quod;i>1;i--)
  {
    sum*=i;
  }
  return(sum);
}
int main(void) {
  /*long int val;
  int exponent = 0;
  scanf("%ld",&val);
  val = fat(val); 
  int curr = pow(10,exponent);
  */
  long int i;
  int mult = 5,ind = 0;
  scanf("%ld",&i);
  for(;;)
  {
	  if(i<mult)
	  { 
		  printf("%d",ind);
		  return 0;
	  }
	  else if(i==mult)
	  { 
		  printf("%d",ind+1);
		  return 0;
	  }
	  else
	  {
		  ind++;
		  mult+=5;
	  }
  }
  return 0;
}
