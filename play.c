#include <stdio.h>

int main(int argc, char **argv)
{
	int min,segs,total = 0;
	int h,m,s;
	while(scanf("%d",&min)!=EOF)
	{
		scanf("%d",&segs);
		min*=60;
		printf("%d+=%d+%d\n",total,min,segs);
		total+=min+segs;
	}
	s = total%60;
	m = total/60;
	h = m/60;
	printf("%d\n%d\n%d\n",h,m,s);
	return 0;
}

