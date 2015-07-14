/*
######################################
### Esercizio in Aula - 26-06-2015 ###
######################################

Preparazione al I Appello 2014-2015
svolgimento by: Gilberto Fil�
trascrizione by: Viviana A.
*/


/*
 * Abbiamo un albero binario (R) ed un array (P).
 * Vogliamo fare match dell'array sull albero. Pu� essere anche inclompleto.
 * Ordine prefisso (nodo -> figlio sx -> figlio dx).
 * Scriviamo una funzione che ritorna una lista di tipo FIFO
 * che descriva il match. Ogni nodo di tipo punt avrà nel suo campo informativo 
 * un puntatore ad un nodo dell'albero che matcha.
 */


// non scrivo i costruttori...
struct nodo{int info; nodo *left, *right};
struct punt{nodp *p; punt *next};
struct FIFO{punt *primo, *fine};


// questa funzione serve per aggiungere un nuovo nodo alla lista quando trovo un match nell'albero.
FIFO aggiungi_fondo(FIFO x, nodo *y){
  if(!x.fine){ //x è vuota quindi aggiungo il primo nodo.
    x.primo = new punt(y);
    x.fine = x.primo;
    return x;
  }
  else{
    x.fine -> next = new punt(y); // nuovo nodo dopo la fine di x
    x.fine = x.fine -> next; // sposto la fine dove ho creato il nuovo nodo
    return x;
  }
}

FIFO match(nodo *R, int *&P, int &dimP){
  if(!dimP || !R)
    return FIFO(0,0);
  bool b = false; // diventerà true se sul nodo corrente c'è un match
  if(R->info == *P){ // controllo il nodo corrente
    b = true; // mi salvo che devo aggiungere un nodo alla lista anche per il nodo corrente (radice)
    P++;
    dimP--;
  }
  // vengono create le liste dei match del sottoalbero sx e dx. Poi basterà concatenarle nel modo giusto
  FIFO sx = match(R->left, P, dimP); 
  FIFO dc = match(R->right, P, dimP);
  
  if(b){ //devo creare un nodo per la radice
    if(!sx.primo)
      sx = aggiungi_fondo(sx,R);
    else
      sx.primo = new punt(R,sx.primo);
  }
  else{
    if(!sx.primo) //in pratica ho solo i nodi creati nel sottoalbero dx
      sx = dx; 
    else{ // attacco dx dopo la fine di sx 
      sx.fine -> next = dx.primo;
      sx.fine = dx.fine; // metto apposto la fine di sx
    }
  }
  return sx;
}
