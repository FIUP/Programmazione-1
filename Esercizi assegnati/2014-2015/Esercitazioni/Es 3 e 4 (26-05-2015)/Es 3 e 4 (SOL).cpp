/*
#####################################
### Esercizi in Aula - 26-05-2015 ###
#####################################
*/





/* Esercizio 3 */
/*
data una lista(L) ed un array P[0..dimP-1] cercare un match completo (e non necessariamente contiguo) di P su L.
in caso di "successo", i nodi di lista(L) che matchano con elementi di P vanno staccati da L e concatenati in una lista(L2) da restituire.
(possibile variante: non utilizzare il parametro "succ" (hint: fermarsi quando dimP==1)).
*/

struct nodo
{
	//membri - campi dati
	int info;
	nodo *next;

	//costruttore
	nodo(int a=0, nodo* b=0)
	{
		info=a;
		next=b;
	}
};


nodo *match_nc(nodo *&L, int *P, int dimP, bool &succ)
{	//PRE(lista(L) corretta, P ha dimP>=0 elementi, succ è definito 0/1 e lista(L)=lista(vL)).
	if(!dimP)	//alla chiamata precedente ho esaurito il pattern da matchare, quindi ritorno stato positivo
	{
		succ=true;
		return 0;
	}
	if(!L)	//sono uscito dalla lista, non ho più nodi (e dato che se ho trovato il match mi son fermato prima) qui non ho trovato il match
		return 0;
	if(L->info==*P)	//potenzialmente questo nodo fa parte del match, ma lo staccherò solo se c'è il match completo
	{
		nodo *x=match_nc(L->next, P+1, dimP-1, succ);	//mi occupo della parte restante della lista
		if(succ)	//se il match completo c'è: x contiene i nodi del match del resto di L a partire da qua, L->next (per side-effect) punta ai restanti nodi
		{
			nodo *y=L;	//chiamo il nodo attuale "y" (backup)
			L=L->next;	//stacco il nodo attuale (y) dalla lista (lo by-passo)
			y->next=x;	//attacco in cima ad x il nodo attuale (che fa parte del match)
			return y;	//restituisco la lista-pattern aggiornata
		}
		else	//se il match completo non c'è, ritorno la lista vuota
			return 0;
	}
	else	//il nodo corrente non matcha in P, quindi non farà parte del match, è giusto che lo "salti" e lo lasci dov'è nella lista(L)
		return match_nc(L->next, P, dimP, succ);
}	/* POST=(se esiste match completo (anche non contiguo) tra P[0..dimP-1] e lista(vL) allora:
				- con return viene restituita una lista(L2) corretta contenente i nodi di lista(vL) che metchano con elementi di P[0..dimP-1], 
				- lista(L) corretta, conterrà i rimanenti nodi;
			 altrimenti:
			 	- return restituisce 0,
			 	- lista(L)==lista(vL). */


/*
VARIANTE:
necessito di sapere se c'è il pattern completo oppure no.
non potendo usare il parametro "succ", potrei usare il puntatore alla lista-pattern ritornato come "test":
per poterlo fare, quando trovo il match completo mi devo fermare con dimP==1 e ritornare un puntatore ad un nodo (l'ultimo della lista pattern);
invece, quando NON trovo un pattern completo restituirò x=0;
in tal modo if(x) mi dirà se il pattern completo c'è o meno senza l'uso di "succ".
PS: bisogna prestare particolare attenzione a come cambia il caso base!
*/





/* Esercizio 4 */
/*
dato un albero(r) ed un array P[0..dimP-1] cercare un match (contiguo e completo) di P su albero(r).
in caso di "successo", va creata una lista(L) i cui nodi hanno come campo "info" un puntatore al nodo di albero(r) che matcha con l'elemento in P.
(per un esempio "visivo" vedi: Esercizio 1 del 25-05-2015 in cui si tratta una lista con suddette caratteristiche).
note: l'ordine di esplorazione di albero(r) è Depth-First Pre-Fissa; è sufficiente fermarsi al primo match incontrato (se c'è).
(possibile variante: cercare un match completo (e non necessariamente contiguo) di P su albero(r)).
*/

struct nodo_albero
{
	//membri - campi dati
	int info;
	nodo_albero *left, *right;

	//costruttore
	nodo_albero(int a=0, nodo_albero* b=0, nodo_albero*c=0)
	{
		info=a;
		left=b;
		right=c;
	}
};


struct nodo_lista
{
	//membri - campi dati
	nodo_albero *p;
	nodo_lista *next;

	//costruttore
	nodo_lista(nodo_albero *a=0, nodo_lista* b=0)
	{
		p=a;
		next=b;
	}
};


nodo_lista *match(nodo_albero *r, int *P, int dimP)
{	//PRE=().
	if(!r)	//caso base: albero vuoto
		return 0;
	else	//ho almeno un nodo
	{
		nodo_lista *x=check(r, P, dimP);	//cerchiamo il match a partire dal nodo attuale, cioè la lista non è vuota
		if(x)	//in caso affermativo
			return x;	//ritorniamo la lista
		
		x=match(r->left, P, dimP);	//se ci è andata male, proviamo nel sotto-albero sx
		if(x)	//se l'ho trovato a sx
			return x;	//ritorno la lista
		
		return match(r->right, P, dimP);	//altrimenti lo cerco nel sotto-albero dx, e restituirò quel che ottengo: se c'è la lista, altrimenti 0
	}
}	//POST=().


nodo_lista *check(nodo_albero *r, int *P, int dimP)
{	//PRE=(albero(r) corretto, P ha dimP>=0 elementi).
	if(!r)	//caso base: sono uscito dall'albero
		return 0;	//è andata male, ritorno la lista vuota
	if(r->info==*P)	//se il nodo corrente match
	{
		if(dimP==1)	//se il nodo corrente (che matcha) è l'ultimo da trovare
			return new nodo_lista(r,0);
		nodo_lista *x=check(r->left, P+1, dimP-1);	//altrimenti continuo la ricerca del resto del match a sx
		if(x)	//se a sinistra ho completato la parte di match che mancava
			return new nodo_lista(r,x);	//ci attacco in testa il nodo corrente e ritorno la nuova lista
		x=check(r->right, P+1, dimP-1);	//se non l'ho trovato a sx, cerco di completare il match a dx
		if(x)	//se a destra ho completato la parte di match che mancava
			return new nodo_lista(r,x);	//ci attacco in testa il nodo corrente e ritorno la nuova lista
		else	//se neanche a dx riesco a completare il match
			return 0;	//allora non c'è, ritorno la lista vuota
	}
	else	//il nodo attuale non matcha
		return 0;	//è andata male, ritorno la lista vuota
}	//POST=().


/*
VARIANTE:

*/
