#ifndef CODE_H_
#define CODE_H_
#include<iostream>

struct nodo {
	char info;
	nodo *next;
	nodo(char c = '\0', nodo* n = NULL);
};

struct coda {
	nodo *inizio;
	nodo *fine;
	coda();
};

void push(nodo*, coda &);
nodo* pop(coda &);
bool e_vuota(coda );
void push_list(nodo*,coda&);
#endif
