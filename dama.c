#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	int curr[2],target[2],moves = 0;
	for(;;)
	{
		scanf("%d %d %d %d",&curr[0],&curr[1],&target[0],&target[1]);
		if(curr[0]+curr[1]+target[0]+target[1]==0) return 0;
		if(curr[0] == target[0] && curr[1] == target[1]) moves = 0;
		
		else if(curr[0]==target[0]||curr[1]==target[1]) moves = 1;
		
		else if(abs(curr[0]-target[0]) == abs(curr[1]-target[1])) moves = 1;
		
		else moves = 2;
		printf("%d\n",moves);
	}
	return 0;
}

