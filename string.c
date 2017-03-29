#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Data{
	int dia;
	int mes;
	int ano;
};
typedef struct Data Data;

struct recebimento {
	unsigned int numeroDocumento;
	float valorRecebimento;
	Data dataEmissao;
	Data dataVencimento;	
	unsigned int codigoCliente;
	int flag;
};
typedef struct recebimento* Recebimento;
typedef struct recebimento receb;
int main(int argc, char **argv)
{
	FILE *fw,*fp;
	int i,size = 3;	
	Recebimento *recebimentos;
	recebimentos = malloc(sizeof(receb)*size);
	for(i=0;i<size;i++) recebimentos[i] = malloc(sizeof(receb));
	char line[100];
	fw = fopen("input.dat","r");
	fp = fopen("data.dat","w");
	i = 0;
	while(fscanf(fw,"%u %f %u %d",
		&recebimentos[i]->numeroDocumento,
		&recebimentos[i]->valorRecebimento,
		&recebimentos[i]->codigoCliente,
		&recebimentos[i]->flag)!=EOF)
	{
		if(recebimentos[i]->flag)
		{
			fprintf(stdout,"\n%u\n%.2f\n%u\n",
			recebimentos[i]->numeroDocumento,
			recebimentos[i]->valorRecebimento,
			recebimentos[i]->codigoCliente);
			fprintf(stdout,"\n");
		}
		i++;
	}
    fclose(fw);
	return 0;
}

