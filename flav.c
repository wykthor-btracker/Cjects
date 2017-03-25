#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k;
      scanf("%d", &k);
    int numeros[4][4];
    int linhas, colunas;
        for(colunas = 0 ; colunas < 4 ; colunas++){
          for(linhas = 0 ; linhas < 4 ; linhas++){
            scanf("%d", &numeros[linhas][colunas]);
              if(linhas == colunas){
                numeros[linhas][colunas] *= k;
              }
          }
        }
        scanf("%d", &k);
        for(linhas = 0 ; linhas < 4 ; linhas++){
          for(colunas = 0 ; colunas < 4 ; colunas++){
            printf("%d ", numeros[linhas][colunas]);
          }
            printf("\n");
        }
    return 0;
}
