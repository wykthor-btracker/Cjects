#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
int digitos(int n)
{
  if(abs(n) < 10) return 1;
  else return 1+digitos(n/10);
}
int main()
{
  int n;
  setlocale(LC_ALL, "Portuguese");
  printf("Digite um número:\n");
  scanf("%d", &n);
  printf("O número %d tem %d\n", n, digitos(n)); 
  return 0;
}
