#include <stdio.h>

int main(int argc, char **argv)
{
	int i,sum = 0,flag = 0,size,max,out,in;
	scanf("%d %d",&size,&max);
	for(i=0;i<size;i++)
	{
		scanf("%d %d",&out,&in);
		sum-=out;
		if(sum+in>max)
		{
			flag++;
			break;
		}
		else sum+=in;
	}
	if(flag) printf("S");
	else printf("N");
	printf("\n");
	return 0;
}

