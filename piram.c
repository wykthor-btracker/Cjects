#include <stdio.h>
#include <stdlib.h>
int piram(int tamanho)
{
	if(tamanho == 1) return 1;
	else return tamanho+piram(tamanho-1);
}

int mult(int a, int b)
{
	if(b == 1) return a;
	else
	{ 
		if(0) printf("%d+mult(%d,%d-1)\n",a,a,b);
		return(a+mult(a,b-1));
	}
}

void reverse(char **arr, int len,int str,int end)
{
	if(str == end) return;
	else
	{
		char middle;
		middle = (*arr)[str];
		(*arr)[str] = (*arr)[end];
		(*arr)[end] = middle;
		reverse(arr,len,str+1,end-1);
	}
}
int main()
{
	printf("%d\n",mult(2,5));
	char *bola = malloc(sizeof(char)*5);
	scanf("%s",bola);
	reverse(&bola,5,0,4);
	printf("%s\n",bola);
	return 0;
}
