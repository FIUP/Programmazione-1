/*
#####################################
### Esercizi in Aula - 25-05-2015 ###
#####################################
*/





/* Esercizio 1 */
/*
dato un intero y e un albero(r) lo si deve percorrere (in ordine infisso) per trovarne tutti i nodi che abbiano campo info==y.
si vuole restituire una lista di nodi i cui campi info siano, nell'ordine, i puntatori ai nodi trovati.
(possibili varianti: percorrere l'albero in ordine infisso e/o postfisso).
*/

struct nodo_albero{
	//membri - campi dati
	int info;
	nodo_albero *left, *right;

	//costruttore
	nodo_albero(int a=0, nodo_albero* b=0, nodo_albero*c=0){
		info=a;
		left=b;
		right=c;
	}
};

struct nodo_lista{
	//membri - campi dati
	nodo_albero *p;
	nodo_lista *next;

	//costruttore
	nodo_lista(nodo_albero *a=0, nodo_lista* b=0){
		p=a;
		next=b;
	}
};

nodo_lista *conc(nodo_lista *L1, nodo_lista *L2){	//PRE=(lista(L1) e lista(L2) sono corrette).
	if(!L1)											//se L1 è vuota, ritorno semplicemente L2
		return L2;
	else{											//altrimenti scorro L1 fino in fondo, al ritorno riattacco tutto
		L1->next=conc(L1->next, L2);				//fa un sacco di "riagganci" inutili
		return L1;
	}
}//POST=(detto c il puntatore restituito, allora lista(c)=lista(a)@lista(b)).


void conc_rif(nodo_lista *&L1, nodo_lista *L2){		//PRE=(lista(L1) e lista(L2) sono corrette, lista(vL1)=lista(L1) e lista(vL2)=lista(L2)).
	if(!L1)
		L1=L2;										//se L1 è vuota "restituisco" L2 tramite side-effect su L1
	else
		conc_rif(L1->next, L2);
}//POST=(al ritorno di questa funzione sarà: lista(L1)==lista(vL1)@lista(L2) e lista(L2==lista(vL2)).


nodo_lista *f(nodo_albero *r, int y){				//PRE=(albero(r) corretto, albero(vr)=albero(r), y definito).
	if(!r)											//caso base: albero vuoto
		return 0;									//ritorno una lista vuota
	else{
		nodo_lista *L1=f(r->left, y);				//ottengo il risultato del sottoalbero sx
		nodo_lista *L2=f(r->right, y);				//ottengo il risultato del sottoalbero dx
		
		if(r->info==y)								//valutazione nodo corrente
			L2=new nodo_lista(r, L2);				//attacco in testa ad L2 il nodo corrente
		
		return conc(L1, L2);						//se volessi usare conc_rif dovrei sostituire questa riga con: conc_rif(L1, L2); return L1;
	}
}//POST=(ritorna una lista (corretta) di puntatori ai nodi di albero(r) che hanno campo info==y in ordine infisso, albero(r)==albero(vr) cioè non è stato modificato).


/*
VARIANTI:

- variante 0 - ordine INFISSO
quella soprastante, r (nodo attuale) se r->info==y devo generare L1@r::L2

- variante 1 - ordine PREFISSO
r (nodo attuale) se r->info==y andrebbe prima di tutto, cioè in testa ad L1, dovrei generare: r::L1@L2
quindi dopo le invocazioni ricorsive su sotto-albero sx e dx avrei:
	if(r->info==y)	//valutazione nodo corrente
		L1=new nodo_lista(r, L1);	//attacco in testa ad L1 il nodo corrente
	return conc(L1, L2);	//se volessi usare conc_rif dovrei sostituire questa riga con: conc_rif(L1, L2); return L1;
oppure, sempre dopo le invocazioni ricorsive:
	if(r->info==y)
		return new nodo_lista(r, conc(L1, L2));	//se volessi usare conc_rif dovrei sostituire questa riga con: conc_rif(L1, L2); return new nodo_lista(r, L1);
	else
		return conc(L1, L2);	//se volessi usare conc_rif dovrei sostituire questa riga con: conc_rif(L1, L2); return L1;
		
- variante 2 - ordine POSTFISSO
r (nodo attuale) se r->info==y andrebbe in fondo, cioè in coda ad L2, dovrei generare: L1@L2@r
quindi dopo le invocazioni ricorsive su sotto-albero sx e dx avrei:
	if(r->info==y)	//valutazione nodo corrente
	{
		nodo_lista L3=new nodo_lista(r, 0);
		L2=conc(L2, L3);	//se volessi usare conc_rif dovrei sostituire questa riga con: conc_rif(L2, L3);
	}	//o semplicemente: L2=conc(L2, new nodo_lista(r, 0));	//se volessi usare conc_rif dovrei sostituire questa riga con: conc_rif(L2, new nodo_lista(r, 0));
	return conc(L1, L2);	//se volessi usare conc_rif dovrei sostituire questa riga con: conc_rif(L1, L2); return L1;
*/

