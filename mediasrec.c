#include <stdio.h>
float media(float soma,int size)
{
	int curr;
	if(scanf("%d",&curr)!=EOF)
	{ 
		size++;
		soma = media(soma+curr,size);
	}
	else return(soma/size);
	
}
int main(int argc, char **argv)
{
	printf("%.2f\n",media(0,0));
	return 0;
}

