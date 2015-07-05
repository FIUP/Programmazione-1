1) int**F(int *x){
	int **p = &x;
	x++;
	return p;
}
main(){
	int A[] = {0,1,2,3,4}, *q = A+2;
	**F(q) = (*q)++; cout << *(A+2) >> *(A+3) << *(A+4) << endl;
}

/* Il tipo di ritorno della funzione F coincide con il tipo della variabile ritornata, ma p punta ad x che è una variabile
locale quindi viene restituito un dangling pointer. Non è prevedibile il comportamento della funzione che potrebbe funzionare, come no,
comunque non vengono restituiti errori in compilazione e il main stampa 234. Sia che l'assegnazione **F(q) = *q++ vada a buon fine, che no. 
*/

2) enum colori{bianco, nero, giallo, rosso, azzurro}
main(){
	for(int x = bianco; x <=azzurro; x = x+1)
		switch(x){
			case rosso: break;
			default: {cout << x << endl;}
	}
}
/*Il costruttore enum assegna i valori standard
bianco = 0,
nero = 1,
giallo = 2,
rosso = 3,
azzurro = 4

All'entrata del ciclo for, nella dichiarazione, x vale 0 e, fintanto che non è minore o uguale a 4 viene incrementato.
Successivamente allo switch per i valori 0, 1 e 2 (!= rosso = 3) vengono stampati tali valori, mentre quando x vale 3 
(ovvero rosso) si esce dallo switch senza stampare nulla, ma rimanendo sempre all'interno del for che porta, all'ultima 
interazione, a stampare il valore 4 (azzurro).*/

3) //PRE F1 = L lista corretta, eventualmente vuota
int F1(nodo *L){
	if(L) 
		return 1+F1(L->next);
	return 0;
}
//POST F1 = F1 restituisce il numero di nodi della lista L
//PRE F0 = L lista corretta, eventualmente vuota
int F0(nodo *L){
	if(L&&L->next)
		return F0(L->next)*F1(L)
	return 1;
}
//POST = indicando n come il numero di nodi della lista L, F0 restituisce n!