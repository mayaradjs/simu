#include <stdlib.h>
#include <stdio.h>

#ifndef RELATORIO_H
#define RELATORIO_H

typedef struct atendimento {
    unsigned int cod, saldo;
    int qtdAtendimento;
    struct atendimento *prox;
    struct atendimento *ant;
}atendimento;



atendimento *contabilizaCliente(atendimento dadosAtendimento, int op);
void imprimeRelatorio();
void init();


#endif
