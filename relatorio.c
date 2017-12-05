#include "relatorio.h"

atendimento *cabeca;

unsigned int contCliente=0;

atendimento *contabilizaCliente(atendimento dadosAtendimento, int op){

	atendimento *atend, a, *aux;
	atend = (atendimento*)malloc(sizeof(atendimento));

	atend->cod = dadosAtendimento.cod;
	atend->qtdAtendimento = 1;
	atend->prox = NULL;
	atend->ant = cabeca;

	aux = (atendimento*)malloc(sizeof(atendimento));


	if (op == 0){
		atend->saldo = dadosAtendimento.saldo;
	}else{
		atend->saldo = 0 - dadosAtendimento.saldo;
	}
	contCliente++;


	if ((cabeca->prox) == NULL){
			cabeca->prox = atend;
	}else{
		a.prox = cabeca->prox;


		do{

			if (((a.prox)->cod) == (atend->cod)){
				(a.prox)->saldo = (a.prox)->saldo + atend->saldo;
				(a.prox)->qtdAtendimento = ((a.prox)->qtdAtendimento) +1;
				contCliente--;
				break;
				
			}else if (((a.prox)->cod) > (atend->cod)){

				aux->prox = (a.prox)->ant;
				(a.prox)->ant = atend;
				atend->ant = aux->prox;
				atend->prox = a.prox;
				(aux->prox)->prox = atend;


			}else{
				if (((a.prox)->prox) == NULL){
					(a.prox)->prox = atend;
					atend->ant = a.prox;
					break;
				}else
					a.prox = (a.prox)->prox;

			}



		}while((a.prox!=NULL) && ((a.prox)->cod <= atend->cod));

	}


	return atend;

}


void imprimeRelatorio(){
	atendimento a;
	a.prox = cabeca->prox;
	printf("%u\n", contCliente);
	while (a.prox != NULL){
		printf("%lld %lld %lld\n", (a.prox)->cod, (a.prox)->qtdAtendimento, (a.prox)->saldo);
		a.prox = (a.prox)->prox;
	}

}

void init(){

	cabeca = (atendimento*)malloc(sizeof(atendimento));
	cabeca->ant = NULL;
	cabeca->prox=NULL;

}

