#include <stdio.h>

int main(){
	int n,i;
	char inst[1];
	char nome1='S';
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",inst);
		printf("%c\n",inst[0]);
	}
    return 0;
}
