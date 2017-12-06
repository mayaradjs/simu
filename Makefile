all: relatorio.o agencia.o
	gcc -g relatorio.o agencia.o -o agenciabancaria -Wall -lm

relatorio.o:
	gcc -g -c relatorio.c

agencia.o:
	gcc -g -c agencia.c

clean:
	rm -rf *.o agenciabancaria
