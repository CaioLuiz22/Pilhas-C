typedef char Itemp;
typedef struct pilha {
	int max;
	int topo;
	Itemp *item;
} *Pilha;

Pilha crpilha(int m) {
	Pilha P = (Pilha) malloc(sizeof(struct pilha));
	P->max = m;
	P->topo = -1;
	P->item = (Itemp*) malloc(m*sizeof(Itemp));
	return P;
}

int vaziap(Pilha P) {
	return (P->topo == -1);
}

int cheiap(Pilha P) {
	return (P->topo == P->max - 1);
}

void empilha(Itemp x, Pilha P) {
	if (cheiap(P)) {
		puts("pilha cheia!");
		abort();
	}
	P->topo++;
	P->item[P->topo] = x;
} 

Itemp desempilha(Pilha P) {
	if (vaziap(P)) {
		puts("pilha vazia!");
		abort();
	}
	Itemp x = P->item[P->topo];
	P->topo--;
	return x;
}

void destroip(Pilha *P) {
	free((*P)->item);
	free(*P);
	*P = NULL;
}










