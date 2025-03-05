#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
	int n, i, num;
	printf("Quantos numeros na pilha? ");
	scanf("%d", &n);
	
	// Criação das pilhas
	Pilha A = crpilha(n);
	Pilha B = crpilha(n);
	
	// Loop de ordenação
	while (n > 0) {
		printf("Numero: ");
		scanf("%d", &num);
		while (!vaziap(A) && num >= A->item[A->topo]) {
			empilha(desempilha(A), B);
		}
		empilha(num, A);
		while (!vaziap(B)) {
			empilha(desempilha(B), A);
		}
		n--;
	}
	
	// Coloca os números em ordem crescente
	printf("Numeros em ordem crescente: ");
	while (!vaziap(A)) {
		num = desempilha(A);
		printf("%d ", num);
	}
	printf("\n");
	
	// Destroi as pilhas
	destroip(&A);
	destroip(&B);
	return 0;
}
