#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long int power(long int base, long int exponent)
{
	if(exponent == 1) return base;
	else return(base*power(base,exponent-1));
}
unsigned int modinv(unsigned int u, unsigned int v)
{
    unsigned int inv, u1, u3, v1, v3, t1, t3, q;
    int iter;
    /* Step X1. Initialise */
    u1 = 1;
    u3 = u;
    v1 = 0;
    v3 = v;
    /* Remember odd/even iterations */
    iter = 1;
    /* Step X2. Loop while v3 != 0 */
    while (v3 != 0)
    {
        /* Step X3. Divide and "Subtract" */
        q = u3 / v3;
        t3 = u3 % v3;
        t1 = u1 + q * v1;
        /* Swap */
        u1 = v1; v1 = t1; u3 = v3; v3 = t3;
        iter = -iter;
    }
    /* Make sure u3 = gcd(u,v) == 1 */
    if (u3 != 1)
        return 0;   /* Error: No inverse exists */
    /* Ensure a positive result */
    if (iter < 0)
        inv = v - u1;
    else
        inv = u1;
    return inv;
}
int enc(long int n, long int e, long int mes)
{
	return(power(mes,e)%n);
}
long int dec(long int n, long int d, long int cyp)
{
	return(power(cyp,d)%n);
}
int main(int argc, char **argv)
{
	int prime1,prime2;
	prime1 = 200;
	prime2 = 150;
	long int n = prime1*prime2;
	long int z = (prime1-1)*(prime2-1);
	long int e = 0;
	while(e%z!=1)e++;
	long int d = modinv(e,z);
	printf("%ld",dec(n,d,enc(n,e,15)));
	return 0;
}

