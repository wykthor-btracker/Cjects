#include <stdio.h>
#include <stdlib.h>
int main()
{
  char matriz[100][100];
  int i,hei,len,attacks,hits = 0,pos_x,pos_y;
  scanf("%d %d",&hei,&len);
  for(i=0;i<hei;i++)
  {
    scanf("%s",matriz[i]);
  }
  scanf("%d",&attacks);
  for(i=0;i<attacks;i++)
  {
    scanf("%d %d",&pos_x,&pos_y);
    if(matriz[pos_x][pos_y] == '#')
    {
		matriz[pos_x][pos_y]
	}
  }
  printf("%d",hits);
  return 0;
}
