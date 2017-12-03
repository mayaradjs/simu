all: relatorio.o agencia.o
	gcc -g relatorio.o agencia.o -o relatorio -Wall -lm

relatorio.o:
	gcc -g -c relatorio.c

agencia.o:
	gcc -g agencia.c

clean:
	rm *.o relatorio
