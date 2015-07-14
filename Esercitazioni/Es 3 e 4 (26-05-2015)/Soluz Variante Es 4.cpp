
//Variante proposta dell'Esercizio 4 svolto in aula il 26.06.2015
//by: Leo M.

nodo_lista *match_alb_nc(nodo_albero *r, int *P, int dimP)
{	//PRE=(albero(r) corretto, P ha dimP>0 elementi).
	if(!r)	//caso base: albero vuoto
		return 0;	//è andata male, ritorno 0
	if(r->info==*P)	//se il nodo attuale matcha con l'elem in esame di P
	{
		if(dimP==1)	//questo match è per l'ultimo elemento di P
			return new nodo_lista(r, 0);	//creao l'ultimo nodo della lista che dovrò restituire (ritorno una cosa diversa da zero)
		else	//non ho ancora verificato tutti gli elementi di P, questo nodo mi interesserà se c'è il match completo
		{
			nodo_lista *x=match_alb_nc(r->left, P+1, dimP-1);	//esploro a sx
			if(!x)	//se a sx non c'è
				x=match_alb_nc(r->right, P+1, dimP-1);	//esploro a dx
			if(x)	//se l'ho trovato o a sx o a dx, questo nodo mi interessa, quindi aggiungo un nodo in testa alla lista da tornare
				return new nodo_lista(r, x);
			else
				return 0;	//il match non c'è, quindi restituisco 0
		}
	}
	else	//il nodo attuale NON matcha con l'elem in esame di P, quindi non mi serve, lo salto
	{
		nodo_lista *x=match_alb_nc(r->left, P, dimP);	//esploro a sx
		if(!x)	//se a sx non c'è
			x=match_alb_nc(r->right, P, dimP);	//esploro a dx
		return x;	//ritorno quel che sarà, se c'è a dx bene, sennò ritornerò 0 (non c'è)
	}
}	/* POST=(se c'è un match completo (e non necessariamente contiguo) di P[0..dimP-1] su albero(r) allora:
				ritorna una lista (corretta) di puntatori ai nodi di albero(r) che hanno un match in P, albero(r)==albero(vr) cioè non è stato modificato;
			 altrimenti: ritorna una lista vuota e albero(r)==albero(vr)). */
