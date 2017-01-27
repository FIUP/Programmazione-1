
// I Appello di Programmazione (30-06-2015) - Parte di Teoria

//soluzione by: Federico S. B.
//thanks to: Riccardo M. - Leo M.


/* Es 1)
Dire se il seguente programma è corretto o meno. Spiegare la propria risposta.
Disegnare uno schema delle relazione tra le variabili del programma durante l'esecuzione.
*/

int**F(int *x){
  int **p = &x;
  x++;
  return p;
}
main(){
  int A[] = {0,1,2,3,4}, *q = A+2;
  **F(q) = (*q)++;
  cout << *(A+2) >> *(A+3) << *(A+4) << endl;
}

// SOLUZIONE:
// Il tipo di ritorno della funzione F coincide con il tipo della variabile ritornata,
// ma "p" punta ad "x" che è una variabile locale quindi viene restituito un dangling pointer.
// Il programma è sbagliato e non è prevedibile il comportamento della funzione che potrebbe funzionare, come no.
// Non ci sono errori in fase di compilazione e (99% delle volte) il main stampa 234.
// Si noti che l'assegnazione **F(q)=(*q)++; potrebbe portare ad un'ambiguiatà in quanto lo standard C++ non
// specifica se viene eseguita prima la parte destra o la parte sinistra di un'assegnazione;
// tuttavia in questo caso l'ordine di valutazione non influisce sull'effetto finale.



/* Es 2)
Dire se il seguente programma è corretto; motivare la risposta, e nel caso sia corretto dire cosa stampa.
*/

enum colori{bianco, nero, giallo, rosso, azzurro};
main(){
  for(int x = bianco; x <=azzurro; x = x+1)
    switch(x){
      case rosso: break;
      default: {cout << x << endl;}
  }
}

// SOLUZIONE:
// Il costrutto enum assegna i seguenti valori standard:
// bianco = 0,
// nero = 1,
// giallo = 2,
// rosso = 3,
// azzurro = 4
// All'entrata del ciclo for, nella dichiarazione, "x" vale 0 e, fintanto che non è minore o uguale a 4 viene incrementato.
// Successivamente allo switch per i valori 0, 1 e 2 (!= rosso = 3) vengono stampati tali valori, mentre quando x vale 3 
// (ovvero rosso) si esce dallo switch senza stampare nulla, ma rimanendo sempre all'interno del for che porta, all'ultima 
// interazione, a stampare il valore 4 (azzurro).



/* Es 3)
Cercate di scrivere una PRE ed una POST sensate per ognuna delle due funzioni ricorsive seguenti:
*/

//PRE_F1=(lista(L) corretta e possibilmente vuota, vL=L).
int F1(nodo *L){
  if(L) 
    return 1+F1(L->next);
  return 0;
}
//POST_F1=(restituisce il numero di nodi di lista(L) e L==vL).

//PRE_F0=(lista(L) corretta e possibilmente vuota, vL=L).
int F0(nodo *L){
  if(L&&L->next)
    return F0(L->next)*F1(L)
  return 1;
}
//POST_F0=(indicando con n come il numero di nodi di lista(L) allora F0 restituisce n! (fattoriale) e L==vL). 
