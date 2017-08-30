#include <stdio.h>

int main(int argc, char **argv)
{
	int i, a;
	char inp[100];
	while(fgets(inp,100,stdin)!= NULL)
	{
		for(i=0;i<100;i++)
		{
			if(inp[i]=='\0') break;
			switch(inp[i])
			{
				case '0':
					inp[i] = 'o';
					break;
				case '1':
					inp[i] = 'i';
					break;
				case '2':
					inp[i] = 'u';
					break;
				case '5':
					inp[i] = 'e';
					break;
				case '4':
					inp[i] = 'a';
			}
			if(!a) inp[i]-=32;
			a++;
			printf("%c",inp[i]);
		}
		i = 0;
	}
	return 0;
}

