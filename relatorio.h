#include <stdlib.h>
#include <stdio.h>

#ifndef RELATORIO_H
#define RELATORIO_H

typedef struct atendimento {
    unsigned int cod, saldo;
    int qtdAtendimento=0;
    struct atendimento *prev;
    struct atendimento *next;
}atendimento;

atendimento *apontador;


void contabilizaCliente(unsigned int cod, int op, unsigned int valor);



#endif
