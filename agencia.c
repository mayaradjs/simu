#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "relatorio.h"

typedef struct dadosCliente{

	unsigned int cod, valor;
	int operacao;
	
} dadosCliente;



int final=-1, inicio=-1;
unsigned int tam;
atendimento* apontador;

//===============================
//     INSERE CLIENTE NA FILA
//===============================
/*int*/void insere (dadosCliente *F, dadosCliente cliente) {
 if ( (final+1)%tam != inicio ) {//se a fila nao estiver cheia, nao sei o que fazer se a fila estiver cheia
	final = (final+1)%tam;
     	F[final] = cliente;
	
	//se for vazia, inicio passa a ser 0
	if (inicio==-1)
		inicio=0;
     		
 }

}

//===============================
//   REMOVE CLIENTE DA FILA
//===============================
dadosCliente remover (dadosCliente *filaAtendimento) {

	dadosCliente cliente = filaAtendimento[inicio];
	inicio = (inicio+1)%tam;

	return cliente;
}

//================================================================
//          ENVIA OS DADOS DO ATENDIMENTO ADD NO RELATORIO
//================================================================
void addRelatorio(dadosCliente clienteAtendido){

	atendimento novoAtendimento;
	novoAtendimento.cod = clienteAtendido.cod;
	novoAtendimento.saldo = clienteAtendido.valor;		
	apontador = contabilizaCliente(novoAtendimento, clienteAtendido.operacao);

}


 
//===============================
//          PRINCIPAL
//===============================
int main(){

	init();

	unsigned int n, m;

	scanf ("%u %u", &m, &n);
	tam = (int)sqrt(n);


	dadosCliente filaAtendimento[tam], cliente, clienteAtendido;

	for (int i=0; i<n; i++){
		scanf("%u %d %u", &cliente.cod, &cliente.operacao, &cliente.valor);
		insere(filaAtendimento, cliente);
		clienteAtendido = remover(filaAtendimento);

		//aqui deve mandar clienteAtendido para o caixa

		addRelatorio(clienteAtendido);

	}

	imprimeRelatorio();

return 0;
}


