
//Tre Versioni della Variante proposta dell'Esercizio 3 svolto in aula il 26.06.2015
//by: Leo M.

//V1 - terribile: controlli doppi e istruzioni ripetute
nodo *match_nc2(nodo *&L, int *P, int dimP)
{	//PRE=(lista(L) corretta, P ha dimP>0 elementi, lista(vL)=lista(L)).
	if(!L)	//caso base: sono uscito dalla lista, niente da fare
		return 0;
	if(dimP==1)	//sono in cerca di un match per l'ultimo elemento di P
	{
		if(L->info==*P)	//se il nodo attuale mathca allora ho concluso positivamente la ricerca del match
		{
			nodo *y=L;
			L=L->next;
			y->next=0;
			return y;
		}
		else	//il nodo attuale non matcha, devo procedere in cerca dell'ultimo match
			return match_nc2(L->next, P, dimP);
	}
	else	//sono su un nodo valido e dimP>1
	{
		if(L->info==*P)
		{
			nodo *x=match_nc2(L->next, P+1, dimP-1);
			if(x)	//se x!=0 allora c'è match e mi serve il nodo attuale
			{
				nodo *y=L;	//chiamo y il nodo attuale (backup)
				L=L->next;	//oppure: "L=y->next;" attacco (per side-effect) il nodo precedente con il successivo rispetto a me
				y->next=x;	//attacco il nodo attuale in cima alla lista-pattern da restituire
				return y;	//restituisco la lista pattern aggiornata
			}
			else	//x==0, quindi il match non c'è, più avanti non si completerà mai
				return 0;
		}
		else	//il nodo attuale non matcha, quindi non mi interessa, lo lascio là dov'è
			return match_nc2(L->next, P, dimP);
	}
}	//POST=().





//V2 - più ragionevole e comprensibile: un blocco di 4 istruzioni ripetuto
nodo *match_nc2(nodo *&L, int *P, int dimP)
{	//PRE=(lista(L) corretta, P ha dimP>0 elementi, lista(vL)=lista(L)).

	if(!L)	//caso base: sono uscito dalla lista, niente da fare
		return 0;
		
	if(L->info==*P)	//il nodo attuale mathca, in caso di match completo mi serve
	{
		if(dimP==1)	//questo match è per l'ultimo elemento di P, lo stacco e sistemo le cose
		{
			nodo *y=L;
			L=L->next;
			y->next=0;
			return y;
		}
		else	//sono su un nodo valido e dimP>1
		{
			nodo *x=match_nc2(L->next, P+1, dimP-1);	//mi occupo di ciò che resta
			if(x)	//se x!=0 allora c'è match e mi serve il nodo attuale
			{
				nodo *y=L;	//chiamo y il nodo attuale (backup)
				L=L->next;	//oppure: "L=y->next;" attacco (per side-effect) il nodo precedente con il successivo rispetto a me
				y->next=x;	//attacco il nodo attuale in cima alla lista-pattern da restituire
				return y;	//restituisco la lista pattern aggiornata
			}
			else	//x==0, quindi il match non c'è, più avanti non si completerà mai
				return 0;
		}	
	}
	else	//il nodo attuale non matcha, quindi non mi interessa, lo lascio là dov'è
		return match_nc2(L->next, P, dimP);
}	/* POST=(se esiste match completo (anche non contiguo) tra P[0..dimP-1] e lista(vL) allora:
				- con il return viene restituita una lista(L2) corretta contenente i nodi di lista(vL) che metchavano con elementi di P[0..dimP-1], 
				- lista(L) corretta, conterrà i rimanenti nodi;
			 altrimenti:
			 	- il return restituisce 0,
			 	- lista(L)==lista(vL). */





//V3 - molto stringata, può risultare di più ardua comprensione
nodo *match_nc2(nodo *&L, int *P, int dimP)
{	//PRE=(lista(L) corretta, P ha dimP>0 elementi, lista(vL)=lista(L)).

	if(!L)	//caso base: sono uscito dalla lista, niente da fare
		return 0;
		
	if(L->info==*P)	//il nodo attuale mathca, in caso di match completo mi serve
	{
		nodo *y=L;	//chiamo y il nodo attuale (backup)
		nodo *x=0;	//preparo il puntatore da infilare nel campo "next" del nodo attuale
		
		if(dimP!=1)	//sono su un nodo valido e dimP>1
		{
			x=match_nc2(L->next, P+1, dimP-1);	//mi occupo di ciò che resta, eventualmente il risultato sarà in x
			if(!x)	//se non c'è possibilità di avere un match completo	
				return 0;	//non devo fare nulla
		}
		
		L=L->next;	//attacco (per side-effect) il nodo precedente con il successivo rispetto a me
		y->next=x;	//attacco il nodo attuale in cima alla lista-pattern da restituire; nel caso fossi sull'ultimo elem del pattern e fosse valido: x==0
		return y;	//restituisco la lista-pattern aggiornata
	}
	else	//il nodo attuale non matcha, quindi non mi interessa, lo lascio là dov'è
		return match_nc2(L->next, P, dimP);
}	/* POST=(se esiste match completo (anche non contiguo) tra P[0..dimP-1] e lista(vL) allora:
				- con il return viene restituita una lista(L2) corretta contenente i nodi di lista(vL) che metchavano con elementi di P[0..dimP-1], 
				- lista(L) corretta, conterrà i rimanenti nodi;
			 altrimenti:
			 	- il return restituisce 0,
			 	- lista(L)==lista(vL). */
