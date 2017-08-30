#include <stdio.h>
int main() {
   
    int i, controle = 0;
    int n;
    do {       
        scanf("%d", &n);       
        for (i = 1; i <= n; i++)
        {
            if (n % i == 0)
                controle++;    
        }       
        if (controle == 2)
           printf("\n1");
        else
            printf("\n0");       
        //printf("Informe um numero: ");
        scanf("%d", &n);      
        n = 0;
        i = 0;
        controle = 0;           
        for (i = 1; i <= n; i++)
        {
            if (n % i == 0)
                controle++;    
        }       
        if (controle == 2)
           printf("\n1");
        else
            printf("\n0");           
        //printf("Informe um numero: ");
        scanf("%d", &n);       
        controle = 0;       
        for (i = 1; i <= n; i++)
        {
            if (n % i == 0)
                controle++;    
        }       
        if (controle == 2)
           printf("\n1");
        else
            printf("\n0");           
        n = 0;
        i = 0;
        controle = 0;                       
    } while (n != -1);
   return 0;
}
