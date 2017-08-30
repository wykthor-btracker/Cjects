#include <stdio.h>

int main(int argc, char **argv)
{
	int max = 25;
	int curr = 0;
	int total = 0;
	int extra = 42;
	int todos = 0;
	int formandos = 0;
	for(;;)
	{
		scanf("%d",&curr);
		if(curr<0) break;
		formandos++;
		if(curr>max) curr = max;
		todos+=curr;
		if(curr>15) curr-=15;
		else curr =0;
		total+=extra*curr;
	}
	todos+=formandos;
	printf("%d.00 %d\n",total,todos);
	return 0;
}

