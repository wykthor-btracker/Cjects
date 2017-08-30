#include <stdio.h>	
int main(int argc, char **argv)
{
	int x,y;
	scanf("%d %d",&x,&y);
	int i,j,k,array[x][y],s_array[x][y];
	int ships,c_x,c_y;
	scanf("%d",&ships);
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{ 
			array[i][j] = 0;
			s_array[i][j] = 0;
		}
	}
	for(i=0;i<ships;i++)
	{
		scanf("%d %d",&c_x,&c_y);
		for(j=0;j<x;j++)
		{
			for(k=0;k<y;k++)
			{
				if(array[c_x][c_y]!=1) array[c_x][c_y] = 1;
			}
		}
	}
	int l,count,bombs;
	scanf("%d %d",&count,&bombs);
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			 printf("%d",array[i][j]);
			 if(j!=y-1) printf(" ");
		 }
		printf("\n");
	}
	printf("\n");
	for(k=0;k<count;k++)
	{
		for(l=0;l<bombs;l++)
		{
			int b_x,b_y;
			//up-right
			scanf("%d %d",&b_x,&b_y);
			int in_x = b_x,in_y = b_y;
			int new_x = in_x-1;
			if(new_x<0) new_x = x+new_x;
			int new_y = (in_y+1)%y;
			if(array[new_x][new_y] == 1) array[new_x][new_y] = 0;			
			//down-right
			new_x = (in_x+1)%x;
			new_y = (in_y+1)%y;			
			if(array[new_x][new_y] == 1) array[new_x][new_y] = 0;
			//up-left
			new_x = in_x-1;
			if(new_x<0) new_x = x+new_x;
			new_y = in_y-1;
			if(new_y<0) new_y = x+new_y;
			if(array[new_x][new_y] == 1) array[new_x][new_y] = 0;			
			//down-left						
			new_y = in_y-1;
			if(new_y<0) new_y = x+new_y;
			new_x = (in_x+1)%x;			
			if(array[new_x][new_y] == 1) array[new_x][new_y] = 0;
		}
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			if(array[i][j]==1)
			{
				int in_x = i,in_y = j;
				int new_x = in_x-1;
				if(new_x<0) new_x = x+new_x;
				int new_y = (in_y+1)%y;
				//printf("swapping (%d,%d) with (%d,%d) \n",in_x,in_y,new_x,new_y);
				s_array[new_x][new_y] = array[i][j];
			}
		}
		//printf("\n");
	}
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++){ 
			printf("%d",s_array[i][j]);
			if(j!=y-1) printf(" ");
			array[i][j] = s_array[i][j];
			s_array[i][j] = 0;
		}
		printf("\n");
	}	
	printf("\n");
	}
	return 0;
}

