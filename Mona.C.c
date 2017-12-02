#include <stdio.h>
#include <stdlib.h>

int i=1, tam=5, ir=1, F[5];

int insere (int elem) {
  if ( (tam + ir - i)%tam != 1 ) {
     i = (i+1)%tam;
     F[i] = elem;
     return 0;
  }
   //printf ("Fila cheia!!! \n");
  return 1;
}

int remover (int*elem) {
  if (ir != i) {
     *elem = F[ir];
     ir = (ir+1) % tam;
     return 0;
  }
   //printf ("Fila vazia!! \n");
  return 1;
}

int main(int argc, char *argv[]) {

  int R;
  R = insere(5);if(R==0){printf ("Inserido na fila!!! \n");}
  R = insere(10);if(R==0){printf ("Inserido na fila!!! \n");}
  R = insere(7);if(R==0){printf ("Inserido na fila!!! \n");}
  R = insere(9);if(R==0){printf ("Inserido na fila!!! \n");}
  R = insere(2);if(R==0){printf ("Inserido na fila!!! \n");}

  if (R == 1) {
     printf("Fila cheia... \n");
  }

  int Retorno,con;
  for(con = 0; con < 5; con++)
  {
     if( remover(&Retorno) == 0)
     {
        printf ("Retorno: %d \n", Retorno );
     }
     else
     {
        printf ("fila Vazia!\n");
        break;
     }
  }

  if (R == 1) {
     printf("Fila vazia... \n");
  }

  system("PAUSE");
  return 0;
}
