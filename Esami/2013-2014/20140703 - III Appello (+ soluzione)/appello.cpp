#include <iostream>
#include <fstream>

using namespace std;


struct nodo{
  int info; 
  nodo* next; 
  nodo(int a=0, nodo* b=0){info=a;next=b;}
};

struct nodoG{
  nodo*N; 
  nodoG* next; 
  nodoG(nodo*a=0, nodoG* b=0){N=a; next=b;}
};

struct match{
  int   ip, //inizio della sottosequenza di P[0..dimP-1] che viene matchata 
        im, //indice di T[0..dimT-1] nel quale inizia il match 
        fm; //indice di T[0..dimT-1] nel quale finisce il match
  match(int a=0, int b=0, int c=0){ip=a; im=b; fm=c;}
};



//PRE_costruisciLista=(l_match è una lista corretta, i è un intero 0<=i<=dimT-1)
void costruisciLista(nodo *l_match, int i){
  nodo *aux=l_match; //lista ausiliare per spostarmi all'ultimo nodo (lista) di l_match
  while(aux->next)
     aux=aux->next;
  aux->next=new nodo(i);

}//POST_costruisciLista=(aggiunge un nodo con campo info=i alla fine della lista del match di P su T[0..dimT-1])


//PRE_cercaMatch=(T è un array di dimT>0 elementi, P è definito)&&(tutti i valori di P[0..dimP-1] sono presenti su T[0..dimT-1])
nodo *cercaMatch(int *T, int dimT, int *P){
  nodo *l_match=0;
  for(int i=0; i<dimT; i++){
    if(T[i]==*P){
      if(!l_match)
        l_match=new nodo(i);
      else costruisciLista(l_match, i);
    }
  }
  return l_match;
}//POST_cercaMatch=(ritorna la lista del match di P su T[0..dimT-1])


//PRE_costruisciListaG=(l_match è una lista corretta, l_match è una lista corretta non vuota)
void costruisciListaG(nodoG *l_match, nodo *l_match_aux){
  nodoG *aux=l_match; //lista ausiliare per spostarmi all'ultimo nodo (lista) di l_match
  while(aux->next)
    aux=aux->next;
  aux->next=new nodoG(l_match_aux);
}//POST_costruisciListaG=(aggiunge la lista del match di P su T[0..dimT-1] sulla lista del match di P[0..dimP-1] su T[0..dimT-1])


//PRE_M=(T è un array di dimT interi, P un array di dimP interi, dimT e dimP>=0)
nodoG* M(int* T, int dimT, int* P, int dimP){
  nodoG *l_match=0;
  if(dimT && dimP){
    //PRE=(T e P sono array di rispettivamente dimT>0 e dimP>0 elementi)
    for(int i=0; i<dimP; i++){
      // R=(0<=i<=dimP)&&(l_match è una lista composta dalle liste L_i dei match dei singoli elementi di P[0..i-1] su T[0..dimT-1])
      nodo *l_match_aux=cercaMatch(T, dimT, P+i);
      if(!l_match)
        l_match=new nodoG(l_match_aux);
      else costruisciListaG(l_match, l_match_aux);
    }//POST=(l_match è la lista delle liste dei match di ogni singolo elemento di P[0..dimP-1] su T[0..dimT-1])
  }
  return l_match;
}//POST_M=(M restituisce una lista di dimP liste tale che la lista L_i (i in [0..dimP-1]) contiene gli indici di tutte le occorrenze di P[i] in T, da sinistra a destra)


/* PROVA DI CORRETTEZZA: PRE < for(C){B} > POST

  Condizione iniziale: PRE → R
------------------------------
Dato PRE, se i=0 allora l_match è vuota infatti contiene le liste dei match dei singoli elementi di P[0..-1] su T[0..dimT-1] → vale R

  Condizione di invarianza: R && (C) < B > R
--------------------------------------------
Dato PRE, se 0<i<dimP l_match è una lista composta dalle liste dei match dei singoli elementi di P[0..i-1] su T[0..dimT-1] ed aggiungiamo in coda alla lista l_match la lista del match di P[i] su T[0..dimT-1] → vale R

  Condizione di uscita: R && !(C) → POST
----------------------------------------
Se i=dimP allora l_match è la lista composta dalle liste dei match dei singoli elementi di P[0..dimP-1] su T[0..dimT-1] → vale POST
*/


//PRE_lung=(MT è una struttura con campi (interi) 0<=ip<=dimP-1, 0<=im<=dimT-1, 0<=fm<=dimT-1)
int lung(match MT){

  int lunghezza=MT.fm-MT.im+1;
    //fm : indice di T nel quale finisce il match
    //im : indice di T nel quale inizia il match
    //1 : bisogna sommare 1 in quanto non abbiamo considerato l'elemento di inizio match
  return lunghezza;

}//POST_lung=(ritorna la lunghezza del match)


//PRE_ricerca=(L è una lista corretta, pos è un intero >0)
bool ricerca(nodo *L, int pos){
  if(!L)
    return 0;
  if(L->info==pos)
    return 1;
  else return ricerca(L->next,pos);
}//POST_ricerca=(la funzione ritorna true se trova un indice uguale a pos; false altrimenti)


//PRE_cercaSequenza=(G è una lista corretta non vuota, pos è un intero >=0)
int cercaSequenza(nodoG *G, int pos){
  if(!G)
    return pos;
  if(ricerca(G->N,pos+1))
    return cercaSequenza(G->next,pos+1);
  else return pos;
}//POST_cercaSequenza=(la funzione ritorna la massima lunghezza della sequenza che fa match a partire dalla lista di liste G)


//PRE_FM1_ric=(G sia una lista corretta di liste tutte corrette e contenenti valori interi non negativi e crescenti, e sia L una lista corretta e possibilmente vuota di interi non negativi e i>=0)
match FM1_ric(nodoG *G, nodo *L, int i){
  if(!L)
    return match(i,0,-1); //se non ci sono altri match di lunghezza >0 verrà comunque restituita quella con i minore, cioè i=0
    // i : considero il match che inizia dalla lista L_i (in questo caso vuota)
    // 0 : (per ipotesi) inizia dall'indice 0
    // -1 : (per ipotesi) finisce nell'indice -1
  match prossimo_match=FM1_ric(G,L->next,i); //mi sposto alla fine della lista: al ritorno cerchiamo la sequenza più lunga
  int lung_match=cercaSequenza(G,L->info); //lunghezza del match a partire da L->info
  match aux(i,L->info,lung_match); //massimo match a partire da L
  if(lung(prossimo_match)>lung(aux)){
    //non ci sono match più lunghi partendo da elementi successivi di L
    //potrei fare anche : if(lung(prossimo_match)>lung_match-i+1){..}
    return prossimo_match;
  }else return aux;
}//POST_FM1_ric=(la funzione restituisce il valore [i, x, y] che corrisponde a MAX_S_(G,L) . Se L è vuota, allora FM1_ric restituisce [0,0,-1] a indicare l'assenza di match)

/* PROVA DI CORRETTEZZA: PRE_FM1_ric < FM1_ric() > POST_FM1_ric

  Caso base: !L
---------------
Dato PRE_FM1_ric se L è una lista vuota allora non ci può essere alcun match: per ipotesi facciamo partire il match dall'indice 0 e lo facciamo finire all'indice -1, quindi ritorna [i,0,-1], infatti la lunghezza del match è -1+0+1=0 → vale POST_FM1_ric

  Caso ricorsivo: 
-----------------
Dato PRE_FM1_ric se L è una lista corretta non vuota allora invoco la chiamata ricorsiva FM1_ric(G,L->next,i), con G lista corretta di liste corrette, L lista corretta possibilmente vuota e i intero >=0: la funzione restituirà il valore [i,x,y], cioè il match di lunghezza massima a partire dall'indice nel nodo L; al ritorno confronterà la lunghezza del massimo match tra il nodo L ed il successivo e ritornerà il match di lunghezza massima nella lista delle liste G a partire dalla lista L → valgono PRE_FM1_ric e POST_FM1_ric 
*/


//PRE_FM=(IG è una lista corretta di liste corrette e tutte contenenti interi non negativi e crescenti. IG ha lunghezza dimP>=0)
match FM(nodoG* IG, int dimP){
  int cG=0, //indice della lista L_cG (0<=cg<=dimP-1)
    lmmax=0, //lunghezza del match massima
    lmatch; //lunghezza match ausiliare
  match M(0,0,-1), MT;
  while (IG && lmmax<dimP-cG){
    //lmmax<dimP-cG : se il numero di elementi rimanenti è uguale a lmmax allora se ce ne fosse un altro a noi interessa il primo, altrimenti non ha senso cercare
    MT=FM1_ric(IG->next,IG->N,cG);//FM1_ric da fare
      //IG->next : cerca nella lista G', cioè nelle liste L_i+1..L_dimP-1
      //IG->N : lista L_cG degli indici degli inizi del match
      //cG : indice del nodo della lista
    lmatch=lung(MT); //lung da fare, calcola lunghezza di un match
    if(lmatch>lmmax){
      lmmax=lmatch;
      M=MT;
    }
    cG++;
    IG=IG->next;
  }
  return M;
}//POST=(restituisce un valore match [a,b,c] tale che se k=c-b, allora P[a..a+k]  è uguale a T[b..c] e tale che tra tutti i match di sotto-sequenze di P in T, k+1 è la lunghezza massima, inoltre, se ci fossero vari match con la stessa lunghezza, FM restituisce quello con  minimo a e a partità di a, con minimo b. In caso IG fosse vuota, oppure, tutte le liste appese a IG fossero vuote, FM restituisce [0,0,-1] a indicare l'assenza di match.)


void stampa(nodo*y, ofstream & OUT){  
  while(y){
    OUT<<y->info<<' '; 
    y=y->next;
  }
}

void stampaG(nodoG* x, ofstream & OUT){ 
  while(x){
    stampa(x->N, OUT);
    x=x->next;
    OUT<<endl;
  }
}


main(){
  try{
    ifstream INP("input");
    ofstream OUT("output");
    if(!INP) 
      throw(0);
    if(!OUT) 
      throw(1);
    int T[200],P[40],dimP, dimT; 
    INP>>dimT>>dimP;
    //cout<<dimT<<' '<<dimP<<' '<<endl;
    for(int i=0; i<dimT; i++)
      INP>>T[i];
    for(int i=0; i<dimP; i++)
      INP>>P[i];
    nodoG* X=M(T,dimT,P,dimP);  // M da fare 
    stampaG(X, OUT);// data
    match y=FM(X,dimP);//data
    OUT<<endl<<y.ip<<' '<<y.im<<' '<<y.fm<<endl;
  }
  catch(int x){
    switch(x){
      case 0: 
        cout<<"problemi con input"<<endl; 
        break;
      case 1: 
        cout<<"problemi con output"<<endl; 
        break;
    }
  }
}