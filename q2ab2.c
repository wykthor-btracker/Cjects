#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG if(0)
int viciado(int ind, char *str,int count,int size,int poss)
{
	if(ind == size) return count+poss;
	else
	{
		if(str[ind] == 'V' && str[ind+1] == 'K')
		{
			DEBUG printf("str[%d] = %c\nstr[%d] = %c\n poss = %d\n count = %d\n",ind,str[ind],ind+1,str[ind+1],poss,count+1);
			count++;
			if(ind+2>=size) return count+poss;
			else viciado(ind+2,str,count,size,poss);
		}
		else
		{
			DEBUG printf("%c %c diff = %d\n",str[ind],str[ind+1],str[ind]-str[ind+1]);
			if(str[ind]-str[ind+1] != -11)
			{
				poss = 1;
			}
			viciado(ind+1,str,count,size,poss);
		}
	}
}
int main(int argc, char **argv)
{
	char *str = malloc(sizeof(char)*100);
	scanf("%s",str);
	printf("%d\n",viciado(0,str,0,strlen(str)-1,0));
	return 0;
}

