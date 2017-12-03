#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct dadosCliente{

	unsigned int cod, operacao, valor;
	
} dadosCliente;



int final=-1, inicio=-1;
unsigned int tam;


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


 
//===============================
//          PRINCIPAL
//===============================
int main(){

	unsigned int n, m;

	scanf ("%u %u", &m, &n);
	tam = (int)sqrt(n);	

	dadosCliente filaAtendimento[tam], cliente, clienteAtendido;

	for (int i=0; i<n; i++){
		scanf("%u %u %u", &cliente.cod, &cliente.operacao, &cliente.valor);
		insere(filaAtendimento, cliente);
		clienteAtendido = remover(filaAtendimento);
		//deve mandar clienteAtendido para o caixa
		contabilizaCliente(clienteAtendido.cod, clienteAtendido.operacao, clienteAtendido.valor);
	}

return 0;
}


//====================================================
//   INSERE CLIENTE NA LISTA DE CLIENTES ATENDIDOS
//====================================================
void contabilizaCliente(){



}


