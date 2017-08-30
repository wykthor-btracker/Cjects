#include <stdio.h>

int main(int argc, char **argv)
{
	int flag,ponto[2],curr[2],size,i;
	for(;;)
	{
		scanf("%d",&size);
		if(size==0) return 0;
		flag = 1;
		for(i=0;i<=size;i++)
		{
			if(flag)
			{ 
				scanf("%d %d",&ponto[0],&ponto[1]);
				flag--;
			}
			else 
			{
				scanf("%d %d",&curr[0],&curr[1]);
				if(curr[0]==ponto[0]||curr[1]==ponto[1])
				{
					printf("divisa\n");
				}
				else
				{
					if(curr[0]>ponto[0])
					{
						if(curr[1]>ponto[1]) printf("NE\n");
						else printf("SE\n");
					}
					else if(curr[0]<ponto[0])
					{
						if(curr[1]>ponto[1])printf("NO\n");
						else printf("SO\n");
					}
				}
			}
		}
	}
	return 0;
}

