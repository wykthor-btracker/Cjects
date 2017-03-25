#include <stdio.h>
int upper(char a)
{
	if(a>=97 && a<=122) return a-32;
	else return a;
}
int main(int argc, char **argv)
{
	printf("%c",upper('a'));
	return 0;
}

