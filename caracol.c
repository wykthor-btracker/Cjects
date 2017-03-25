#include <stdio.h>

int main(int argc, char **argv)
{
	void d(int *pos){pos[1]++;}
	void r(int *pos){pos[0]++;}
	void u(int *pos){pos[1]--;}
	void l(int *pos){pos[0]--;}
	int size,pos[2] = {0};
	scanf("%d",&size);
	int i,j,array[size][size],read = size,dir = 0,write = 0,first = 0,s_first = 0,step = 0;
	while(write<size*size)
	{
		step = 0;
		if(!first)
		{ 
			step++;
			first++;
		}
		for(;step<2;step++)
		{
			for(i=0;i<read;i++)
			{
				printf(" %d %d ",pos[0],pos[1]);
				scanf("%d",&array[pos[0]][pos[1]]);
				{
					if(i == read-1) dir = (dir+1)%4;
					switch(dir)
					{
						case 0:
							d(pos);
							printf("d");
							break;
						case 1:
							r(pos);
							printf("r");
							break;
						case 2:
							u(pos);
							printf("u");
							break;
						case 3:
							l(pos);
							printf("l");
							break;
					}
				}
				//printf(" %d %d ",pos[0],pos[1]);
				write++;
				//printf("dir = %d,step = %d",dir,step);
				printf("\n");
			}
			printf("change\n");
		}
		read--;
	}
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			printf("%d ",array[j][i]);
		}
		printf("\n");
	}
	return 0;
}

