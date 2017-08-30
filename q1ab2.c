#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DEBUG if(0)
int pal(int start, int end, char *string, int *sum)
{
	if(((start==end-1 && start+end%2!=0) || start==end) && string[start] == string[end]) return 1;
	else
	{
		if(string[start] != string[end])
		{
			(*sum)++;
			DEBUG printf("%c != %c\n",string[start],string[end]);
			DEBUG printf("string[%d] != string[%d]\n",start,end);
			DEBUG printf("sum = %d\n",*sum);
		}
		if(*sum>1) return 0;
		pal(start+1,end-1,string,sum);
	}
}
int main(int argc, char **argv)
{
	char *text = malloc(sizeof(char)*16);
	int sum = 0,*psum = &sum;
	scanf("%s",text);
	if((pal(0,strlen(text)-1,text,psum) || strlen(text) == 2) && sum) printf("YES %d\n",sum);
	else printf("NO %d\n", sum);
	return 0;
}

