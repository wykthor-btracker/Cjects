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
	FILE *fw;
	int i,size = 3;	
	Recebimento *recebimentos;
	recebimentos = malloc(sizeof(receb)*size);
	recebimentos = realloc(recebimentos,(sizeof(receb)*size)+1);
	for(i=0;i<size;i++) recebimentos[i] = malloc(sizeof(receb));
	fw = fopen("input.dat","r+");
	i = 0;
	while(fscanf(fw,"%u %f %d/%d/%d %d/%d/%d %u %d",
		&recebimentos[i]->numeroDocumento,
		&recebimentos[i]->valorRecebimento,
		&recebimentos[i]->dataEmissao.dia,
		&recebimentos[i]->dataEmissao.mes,
		&recebimentos[i]->dataEmissao.ano,
		&recebimentos[i]->dataVencimento.dia,
		&recebimentos[i]->dataVencimento.mes,
		&recebimentos[i]->dataVencimento.ano,
		&recebimentos[i]->codigoCliente,
		&recebimentos[i]->flag)!=EOF) i++;
	int end = i;
	rewind(fw);
	recebimentos[0]->numeroDocumento++;
	for(i=0;i<end;i++)
	{
		fprintf(fw,"\n%u\n%f\n%d/%d/%d\n%d/%d/%d\n%u\n%d\n",
			recebimentos[i]->numeroDocumento,
			recebimentos[i]->valorRecebimento,
			recebimentos[i]->dataEmissao.dia,
			recebimentos[i]->dataEmissao.mes,
			recebimentos[i]->dataEmissao.ano,
			recebimentos[i]->dataVencimento.dia,
			recebimentos[i]->dataVencimento.mes,
			recebimentos[i]->dataVencimento.ano,
			recebimentos[i]->codigoCliente,
			recebimentos[i]->flag);
	}		
    fclose(fw);
	return 0;
}

