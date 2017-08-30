#include <stdio.h>
#include <string.h>
void ConverteTemp(float v1, char esc1, float *v2, char esc2)
{
	if(esc2 == 'K')
	{
		if(esc1 == 'C') *v2 = v1+273;
		else if(esc1 == 'F') *v2 = ((v1-32)/1.8)+273; 
	}
	else if(esc2 == 'F')
	{
		if(esc1 == 'C') *v2 = v1*1.8+32;
		else if(esc1 == 'K') *v2 = ((v1-273)*1.8)+32; 
	}
	else if(esc2 == 'C')
	{
		if(esc1 == 'F') *v2 = (v1-32)/1.8;
		else if(esc1 == 'K') *v2 = v1-273;
	}
}
int main(int argc, char **argv)
{
	float nv = 0;
	float v1,*v2 = &nv;
	char esc1,esc2;	
	for(;;)
	{
		float nv = 0;
		float v1;
		char esc1,esc2;		 		
		scanf("%f %c %c",&v1,&esc1,&esc2);
		esc1 = toupper(esc1);
		esc2 = toupper(esc2);
		if(esc1 != 'C' && esc1 !='F' && esc1 != 'K' && esc2 != 'C' && esc2 !='F' && esc2 !='K')
		{
			if(esc1 == esc2 && esc1 == ':') return 0;
			printf("Valores invalidos, insira novamente.");
		}
		else
		{
			ConverteTemp(v1,esc1,v2,esc2);
			printf("%.1f%c",*v2,esc2);
			printf("\n");
		}
	}
	return 0;
}
