#include <stdio.h>
#define size 103
int main(int argc, char **argv)
{
	char array[size];
	int j,i,c,count = 0,str = 0;
	scanf("%d",&c);
	for(i=0;i<c;i++)
	{
		fgets(array,size,stdin);
		for(j=0;j<size;j++)
		{
			count++;
			if(array[j]=='\0') break;
		}	
	}
	return 0;
}

