#include <stdio.h>
/*
 * 3
 * 1 targets at 11, interrupted at 10, add interruption to total: total+=10+((-1)->target-interruption));
 * 10 targets at 20, not interrupted, add full to total: total+=10;
 * 20 targets at 30, not interrupted, add full to total: total+=10;
 * total = 9+20;
 */
int main()
{
	int i,flag = 0,last,input,size,time = 0,target;
	scanf("%d",&size);
	for(i=0;i<size;i++)
	{
		if(!flag)
		{
			scanf("%d",&last);
		}
		target = last+10;
		flag = 1;
		scanf("%d",&input);
		if(target>input)
		{
			time+=10-(target-input);
		}
		else
		{
			time+=10;
		}
//		time= time + 10-((last+10)-input);
		last = input;
	}
	printf("%d\n",time+10);
	return 0;
}

