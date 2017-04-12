#include <stdio.h>
#include <stdlib.h>
struct cliente {
	char nome[101];
	char endereco[201];
	char telefone[12];
	unsigned int codigoCliente;
	int contador;
};
typedef struct cliente* Cliente;
typedef struct cliente tamanhoCliente;
int main(int argc, char **argv)
{
	FILE *writer;
	int i,size = 2;
	Cliente *clientes;
	clientes = malloc(sizeof(tamanhoCliente)*size);
	for(i=0;i<size;i++) clientes[i] = malloc(sizeof(tamanhoCliente));
	writer = fopen("cliente.dat","r+");
	i = 0;
	while((fscanf(writer,"%s %s %s %d %d",
		clientes[i]->nome,
		clientes[i]->endereco,
		clientes[i]->telefone,
		&clientes[i]->codigoCliente,
		&clientes[i]->contador))!=EOF)
		{
			printf("read num.%d\n",i);
			i++;
		}
	int end = i;
	for(i=0;i<end;i++)
	{
		fprintf(stdout,"%s %s %s %d %d\n",
				clientes[i]->nome,
				clientes[i]->endereco,
				clientes[i]->telefone,
				clientes[i]->codigoCliente,
				clientes[i]->contador);
	}
	return 0;
}
