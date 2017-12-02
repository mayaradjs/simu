#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct dadosCliente{

	unsigned int cod, operacao, valor;
	
} dadosCliente;



int final=0, inicio=0;
unsigned int tam;

int insere (dadosCliente *F, dadosCliente cliente) {
//  if ( (tam + inicio - final)%tam != 1 ) {
     F[final] = cliente;
     final = (final%tam)+1;
     //return 0;
//  }
   //Fila cheia!!!);
 // return 1;
}


int main(){

	unsigned int n, m;

	scanf ("%u %u", &m, &n);
	tam = (int)pow(n, 0.5);	

	dadosCliente filaAtendimento[tam], cliente;

	for (int i=0; i<n; i++){
		scanf("%u %u %u", &cliente.cod, &cliente.operacao, &cliente.valor);
		insere(filaAtendimento, cliente);
	}



return 0;
}
