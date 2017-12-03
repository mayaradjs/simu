#include "relatorio.h"

atendimento *cabeca;

unsigned int contCliente=0;

atendimento *contabilizaCliente(atendimento dadosAtendimento, int op){

	atendimento atend, a, *aux;
	atend.cod = dadosAtendimento.cod;
	atend.qtdAtendimento = 0;
	atend.prox = NULL;
	atend.ant = NULL;

	aux = (atendimento*)malloc(sizeof(atendimento));

	if (op == 0){
		atend.saldo = dadosAtendimento.saldo;
	}else{
		atend.saldo = 0 - dadosAtendimento.saldo;
	}
	contCliente++;

	if ((cabeca->prox) == NULL){
			atend.ant = cabeca;
			atend.prox = NULL;
			cabeca->prox = &atend;
	}else{
		a.prox = cabeca->prox;

		do{
			if ((a.prox)->cod == atend.cod){
				(a.prox)->saldo = (a.prox)->saldo + atend.saldo;
				(a.prox)->qtdAtendimento++;
				contCliente--;
			}else if (((a.prox)->cod) > (atend.cod)){
				aux = (a.prox)->ant;
				(a.prox)->ant = &atend;
				atend.ant = aux;
				atend.prox = a.prox;
				aux->prox = &atend;
			}else{
				a.prox = (a.prox)->prox;
				if (a.prox==NULL){
					a.prox = &atend;
					atend.ant = (a.prox)->ant;
					}
			}
		}while((a.prox!=NULL) && ((a.prox)->cod < atend.cod));
	}

	return (atend.prox)->ant;

}

void imprimeRelatorio(){
	atendimento a;
	a.prox = cabeca->prox;
	printf("%u\n", contCliente);
	while (a.prox != NULL){
		printf("%u %d %u\n", (a.prox)->cod, (a.prox)->qtdAtendimento, (a.prox)->saldo);
		a.prox = (a.prox)->prox;
	}

}

void init(){

	cabeca = (atendimento*)malloc(sizeof(atendimento));
	cabeca->ant = NULL;
	cabeca->prox=NULL;

}

