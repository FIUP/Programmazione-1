// esercizio infrasettimanale
// ho una lista, un certo k>=0 e intero y. noi vogliamo buttare via gli ultimi k nodi con campo info y. restituisco due liste: una con i nodi staccati e una con quello che rimane
// con il return restituisco la lista di quelli che stacco, mentre con il riferimento resrituisco il resto

//PRE=(L lista corretta, y,k interi, v=0) 
nodo* f0(nodo*&L, int y, int k, int &v){
	if(L){
		if(L->info==y){
			v++;
			nodo*T=f0(L->next, y,k,v);
			if(v !=-1 && v<k){
				nodo*w=L;
				L=L->next;
				w->next=T;
				v++;
				return w;
			}
			else{
				return T; 
			}
		}
		else
			return f0(L->next, y,k,v);
	}
	else{
			{	if(v>=k)
					v=0;
				else
					v=-1;	
			}
		return 0;
	}
}
//POST=(se vL contiene meno di max(0,k-vv) allora L=vL, altrimenti L è la lista ottenuta da vL togliendo da vL min nodi con info=y in L)
//---------------------------------//
//per casa, da fare
// funzione ricorsiva che invece di staccare gli ultimi k nodi, stacca i primi k nodi, ma solo se ce ne sono k, ma solo se ce ne sono almeno k nodi.