#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "relatorio.c"

typedef struct dadosCliente{

	long long int cod, valor;
	int operacao;
	
} dadosCliente;



unsigned int final=-1, inicio=-1;
unsigned int tam;
atendimento* apontador;

//===============================
//     INSERE CLIENTE NA FILA
//===============================
/*int*/void insere (dadosCliente *F, dadosCliente cliente) {
// if ( (final+1)%tam != inicio ) {//se a fila nao estiver cheia, nao sei o que fazer se a fila estiver cheia
	final = (final+1)%tam;
     	F[final] = cliente;
	
	//se for vazia, inicio passa a ser 0
	if (inicio==-1)
		inicio=0;
     		
 }


//===============================
//   REMOVE CLIENTE DA FILA
//===============================
dadosCliente remover (dadosCliente *filaAtendimento) {
	dadosCliente cliente;
	if (inicio >=0){
		cliente = filaAtendimento[inicio];
		inicio = (inicio+1)%tam;
	}//else printf("Lista vazia\n");

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
	//apontador = (atendimento*)malloc(sizeof(atendimento));
	long long int n, m;

	scanf ("%lld %lld", &m, &n);
	tam = (unsigned int)sqrt(n);


	dadosCliente filaAtendimento[tam], cliente, clienteAtendido;

	for (unsigned int i=0; i<n; i++){
		scanf("%lld %d %lld", &cliente.cod, &cliente.operacao, &cliente.valor);
		insere(filaAtendimento, cliente);

		clienteAtendido = remover(filaAtendimento);

		//aqui deve mandar clienteAtendido para o caixa

		addRelatorio(clienteAtendido);

	}

	imprimeRelatorio();

return 0;
}


