#ifndef RELATORIO_H
#define RELATORIO_H

typedef struct atendimento{
    long long int cod, saldo;
    long long int qtdAtendimento;
    struct atendimento *prox;
    struct atendimento *ant;
} atendimento;


atendimento *contabilizaCliente(atendimento dadosAtendimento, int op);

void imprimeRelatorio();
void init();


#endif
