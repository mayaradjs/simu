#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct dadosCliente{

	unsigned int cod, operacao, valor;
	
} dadosCliente;



int final=-1, inicio=-1;
unsigned int tam;

/*int*/void insere (dadosCliente *F, dadosCliente cliente) {
 if ( (final+1)%tam != inicio ) {//se a fila nao estiver cheia, nao sei o que fazer se a fila estiver cheia
	final = (final+1)%tam;
     	F[final] = cliente;
	
	//se for vazia, inicio passa a ser 0
	if (inicio==-1)
		inicio=0;
     		
 }

}

dadosCliente remover (dadosCliente *filaAtendimento) {
	dadosCliente cliente;
	if (inicio != final) {
		cliente = filaAtendimento[inicio];
		inicio = (inicio+1)%tam;
	}

	return cliente;
}





int main(){

	unsigned int n, m;

	scanf ("%u %u", &m, &n);
	tam = (int)sqrt(n);	

	dadosCliente filaAtendimento[tam], cliente;

	for (int i=0; i<n; i++){
		scanf("%u %u %u", &cliente.cod, &cliente.operacao, &cliente.valor);
		insere(filaAtendimento, cliente);
	}

	for (int i=0; i<tam; i++){
		printf("\n%u %u %u\n", filaAtendimento[i].cod, filaAtendimento[i].operacao, filaAtendimento[i].valor);}

return 0;
}
