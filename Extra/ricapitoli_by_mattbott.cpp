#include<iostream>
#include<fstream>
using namespace std;
//strutture utilizzate
//struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a;next=b;}};//liste
struct nodo{int info; nodo* left, * right; nodo(int a=0, nodo* b=0, nodo* c=0){info=a;left =b;  right=c;}};//alberi
struct punt{nodo* p; punt* next; punt(nodo* a=0,punt* b=0){p=a;next=b;}};
struct FIFO{punt* primo, *fine; FIFO(punt* a=0, punt*b=0){primo=a; fine=b;}};
struct dueL {nodo* prima, * seconda; dueL(nodo*a=0, nodo* b=0){prima=a; seconda=b;}};

/*QUESTO FILE CONTIENE UNA RACCOLTA DI ALCUNI ESERCIZI TIPICI, DOVREBBERO ESSERE TUTTI GIUSTI, MA È MEGLIO VERIFICARE
LA MAGGIOR PARTE DELLE SOLUZIONI SONO MIE, ALCUNE SONO ISPIRATE AD ALTRI O A FILÈ */

/*
 * da un albero, ricavare una lista dei nodi con capo info=y(=1 in questo caso) con ricorsione
  punt* conc(punt*a,punt*b){
	if(!a) return b;
	a->next=conc(a->next,b);
	return a;
}
punt* build_list(nodo*r,int y){ //r è l'albero
	if(!r) return 0;
	punt*a=build_list(r->left,1);
	punt*b=build_list(r->right,1);
	if(r->info==y)
		b=new punt(r,b);
	return conc(a,b);	
}
* VARIANTE DI CONC
* void conc2(nodo*&a,nodo*&b){
*     if(!a) a=b;
*     else conc2(a->next,b);
* }
* ------
* Da un albero ricavare la lista dei nodi che matcha dal vettore P. uso di FIFO
* FIFO aggiungi_fondo(FIFO x, nodo *y){
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
  FIFO dx = match(R->right, P, dimP);
  if(b){ // qui dentro avrò i nodi matchati ma al ritorno, FIFO mi serve per costruire la lista "al contrario" 
	  if(!sx.fine) sx=aggiungi_fondo(sx,R);//se non sono stati inseriti nodi
	  else  sx.primo=new punt(R,sx.primo); // ricordiamo che stiamo costruendo la lista al ritorno
  }
  if(!sx.fine) sx=dx; // se non ci sono match a sinistra -> la pongo uguale alla parte destra
  else if(dx.primo){ // se ce ne sono a sinistra e anche a destra -> concateno la parte sinistra con quella destra
	  sx.fine->next=dx.primo;
	  sx.fine=dx.fine;
  }
  return sx;
}
* ------
* da un albero, aggiungere un nodo alla foglia più a sinistra in maniera iterativa
* bool leaf(nodo*r){
	return !r->right && !r->left;
}
nodo* f(nodo*r,ifstream & INP,int dim){
	if(!r) return 0;
	nodo*tmp=r;int x;
	while(dim){//dim=1, n di nodi da aggiungere
		if(leaf(r)){
			INP>>x;
			r->left=new nodo(x);
			dim--;
		}
		if(r->left) r=r->left;
		if(!r->left && r->right) r=r->right;
	}
	return tmp;
}
* ------
*  DATO UN ALBERO, SCORRERLO PER LIVELLI E RESTITUIRE LA LISTA DEI NODI CON CAMPO INFO == y. ITERAZIONE
* 
* FIFO f1(nodo* r){ // serve per partire, cioè costruire la lista FIFO iniziale.
	if(!r) return FIFO(); // Se l'albero è vuoto -> FIFO è banalmente vuota
	punt* a=new punt(r); // altrimenti si crea la lista FIFO con la radice dalla quale cominciare a lavorare.
	return FIFO(a,a); // e la si ritorna
}
FIFO togli_primo(FIFO x){
	if(x.primo==x.fine) return FIFO();
	punt*tmp=x.primo;
	x.primo=x.primo->next;
	delete tmp;
	return x;
}
FIFO metti_fondo(FIFO x, nodo*a){
	if(a->left){
		x.fine->next=new punt(a->left);
		x.fine=x.fine->next;
	}
	if(a->right){
		x.fine->next=new punt(a->right);
		x.fine=x.fine->next;
	}
	return x;
}
punt* f2(FIFO x, int y, ofstream & OUT){
	punt*tmp=0,*start=0;int i=0;
	while(x.primo && !start){ // con questo while ricavo il primo nodo della lista
		if(x.primo->t->info==y) start=new punt(x.primo->t,0); // se esiste la corrispondenza -> creo il nodo e posso continuare a lavorare
		x=metti_fondo(x,x.primo->t); // e aggiorno FIFO
		x=togli_primo(x);
	}
	tmp=start; // uso un nodo temporaneo per costruire il resto della lista
	if(tmp){ // se abbiamo creato una testa -> possiamo lavorare
		while(x.primo){
			if(x.primo->t->info==y){ // se esiste la corrispondenza -> creo il nodo
				tmp->next=new punt(x.primo->t);
				tmp=tmp->next; // e sposto il puntatore
			}
		    x=metti_fondo(x,x.primo->t); // e aggiorno FIFO
		    x=togli_primo(x);
		}
		tmp->next=0; // alla fine chiudo la lista
	}
	return start; // e ritorno la testa
}
* ------
* DATO UN ALBERO, SCORRERLO PER LIVELLI E RESTITUIRE LA LISTA DEI NODI CON CAMPO INFO == y. RICORSIONE 
* 
* FIFO f1(nodo* r){ // serve per partire, cioè costruire la lista FIFO iniziale.
	if(!r) return FIFO(); // Se l'albero è vuoto -> FIFO è banalmente vuota
	punt* a=new punt(r); // altrimenti si crea la lista FIFO con la radice dalla quale cominciare a lavorare.
	return FIFO(a,a); // e la si ritorna
}
FIFO togli_primo(FIFO x){
	if(x.primo==x.fine) return FIFO();
	punt*tmp=x.primo;
	x.primo=x.primo->next;
	delete tmp;
	return x;
}
FIFO metti_fondo(FIFO x, nodo*a){
	if(a->left){
		x.fine->next=new punt(a->left);
		x.fine=x.fine->next;
	}
	if(a->right){
		x.fine->next=new punt(a->right);
		x.fine=x.fine->next;
	}
	return x;
}
punt* f2(FIFO x, int y, ofstream & OUT){
	if(!x.primo) return 0;
	if(x.primo->t->info==y){
		punt*tmp=new punt(x.primo->t,tmp);
		x=metti_fondo(x,x.primo->t);
		x=togli_primo(x);
		tmp->next=f2(x,y,OUT);
		return tmp;
	}else{
		x=metti_fondo(x,x.primo->t);
	    x=togli_primo(x);
	    return f2(x,y,OUT);
	}
	
} 
* ------
* dato un albero, restituire la profondità minima
* bool leaf(nodo*x){
*    return !x->left && !x->right;
* }
* int prof_min(nodo*r,int prof){
*   if(leaf(r))
*      return prof;
*   int a=INT_MAX,b=INT_MIN;
*   if(r->left) a=prof_min(r->left,prof+1);
*   if(r->right) b=prof_min(r->right,prof+1);
*   if(a<=b) return a;
*   else return b;
* }
* ------
* Come prima ma restituendo il puntatore alla foglia
*  foglia prof_min(nodo*r,int prof){
*   if(!r)
*      return foglia(0,INT_MAX);
*   if(leaf(r)) return foglia(r,prof)
*   foglia a=prof_min(r->left,prof+1);
*   foglia b=prof_min(r->right,prof+1);
*   if(a.prof<=b.prof) return a;
*   else return b;
* }
* ------
* Dato un array di cammini(divisi da -1) costruire un albero iterativamente. L'array termina con un -2
nodo* c_alb(int*T){
	nodo*a=0;
	if(T[0]!=-2){//posso creare la radice
	   a=new nodo();
	   nodo*b=a;
	   for(int i=0;T[i]!=-2;i++){
		   if(T[i]!=-1){
		      if(!T[i]){ // se devo andare a sinistra
				  if(!b->left) b->left=new nodo(); // se a sinistra si può mettere un nodo
				  b=b->left; // in ogni caso avanzo nell'albero
		      }else{ // T[i]==1, se devo andare a destra
				  if(!b->right) b->right=new nodo(); // se a destra posso mettere un nodo
				  b=b->right; //in ogni caso avanzo nell'albero
			  }   
		 }else{ //T[i]==-1, se un cammino è terminato -> torno alla radice
			 b=a;
		 }  
	   }
    }
    return a;
}
* ------
* Dati due alberi, verificare se hanno la stessa struttura
* bool conf(nodo*a, nodo*b){
    if((!a || !b) && !(!a && !b)) return false; //se solo uno dei due è vuoto
    if(!a && !b) return true; // se sono tutti e due vuoti
    return conf(a->left,b->left);
    return conf(a->right,b->right);
}
* ------
* da un albero, ricavare la lista dei nodi che sono ad un livello pari
* punt*conc(punt*a,punt*b){
	if(!a) return b;
	a->next=conc(a->next,b);
	return a;
}
punt*build_list(nodo*r,int lev){
	if(!r) return 0;
	punt*a=build_list(r->left,lev+1);
	punt*b=build_list(r->right,lev+1);
	if(!(lev%2))
		b=new punt(r,b);
	return conc(a,b);	
}
* ------
* scorrere un albero per livelli. Utilizzo di FIFO e punt
* FIFO f1(nodo* r){ //da questa funzione parte tutto, diamo un valore iniziale ad una variabile FIFO
	if(!r)
	   return FIFO(0,0); // se l'albero è vuoto->FIFO vuota(banale)
	punt* n=new punt(r); // altrimenti=radice
	return FIFO(n,n);   
}
FIFO togli_primo(FIFO x){
	if(x.primo==x.fine) // vuol dire che il primo = ultimo, abbiamo finito quindi di lavorare
		return FIFO();
	punt*tmp=x.primo; // salvo il primo
	x.primo=x.primo->next; // il secondo diventa il primo
	delete tmp; // elimino il "vecchio" primo
	return x;
}
FIFO metti_fondo(FIFO x, nodo*a){ // a è il puntatore al primo nodo i quali figli dovranno essere messi in coda a FIFO
	if(a->left){ 
		punt* n=new punt(a->left);
		x.fine->next=n; //l'ultimo punta ad un "nuovo" ultimo nodo
		x.fine=x.fine->next; // l'ultimo "nuovo" prende il posto dell'ultimo "vecchio"
	}
	if(a->right){
		punt* n=new punt(a->right);
		x.fine->next=n;
		x.fine=x.fine->next;
	}
	return x;	
}
nodo* f2(FIFO x, int y, ofstream & OUT){
	if(!x.primo) // possiamo interpetarlo come if(!list)
	   return 0;
	nodo*tmp=x.primo->t; // prelevo il primo nodo da FIFO
	!------!------!
	//qui si dovrebbe(ovviamente parlo in generale) scrivere il codice che fa la necessaria analisi sul nodo
	if(tmp->info > 0) // per esempio...
	*   tmp->info=-1;
	!------!------!  
	x=metti_fondo(x,tmp); // si mettono nel fondo di FIFO gli eventuali figli di tmp(tmp era il primo nodo, mettiamo in coda i suoi figli)
	x=togli_primo(x); // e qui lo eliminiamo dalla testa
	return f2(x,y,OUT);  
}
*  NEL MAIN --->  FIFO x=f1(R); nodo* a=f2(x,y,OUT); //da fare
* ------
* costruire un albero bilanciato a sinistra
int conta_n(nodo*r){
   if(!r) return 0;
     else
    return 1+conta_n(r->left)+conta_n(r->right);
}
nodo* insert(nodo*r, int y){
  if(!r) return new nodo(y);
  if(conta_n(r->left)<=conta_n(r->right))// se ci sono più nodi nel lato destro che in quello sinistro...
    r->left=insert(r->left,y);
   else   
    r->right=insert(r->right,y); 
  return r;
}
nodo* rep_ins(nodo*r, int dim, ifstream & INP){
  if(dim){
    int z;
    INP>>z;
    nodo*x=insert(r,z);
    return rep_ins(x,dim-1,INP);
   }
  return r;
}
* /// NEL MAIN ---> nodo* R=rep_ins(0,dim,IN); dove dim è il numero di nodi totali
* -----
* DATE DUE LISTE "T" E "C" ELIMINARE DA T TUTTI I NODI CON CAMPO INFO UGUALE A QUELLI DI C. ITERAZIONE E UTILIZZO DI FIFO
FIFO metti_fondo(FIFO x, nodo*a){
	if(!x.fine){ // se la fine non esiste, cioè la coda non è ancora stata usata
		x.fine=a; // la istanziamo
		x.primo=x.fine; // e poniamo l'inizio uguale alla fine
	}else{ // se esiste
		x.fine->next=a; // si punta alla nuova fine
		x.fine=x.fine->next;
	}
	return x;
}

nodo* elim(nodo* T, int y){
	FIFO x;
	while(T){
		if(T->info==y){ // se abbiamo la corrispondenza
			nodo*tmp=T; // eliminiamo il nodo usandone uno temporaneo
			T=T->next;
			delete tmp;
		}else{ // altrimenti
			x=metti_fondo(x,T); // mettiamo in fondo a FIFO il nodo
			T=T->next; // e avanziamo nella lista
		}
	}
	if(x.fine) x.fine->next=0;	
	return x.primo; // ritorniamo quindi la testa.
}
nodo* togli_nodo(nodo* T, nodo* C){
	FIFO x(T); // x.primo punta al primo nodo della lista
	while(C){
		if(T->info==C->info){ // se trovo una corrispondenza
			T=elim(x.primo,C->info); // elimino TUTTI i nodi in T == C->info. T=x.primo, cioè il primo nodo della nuova lista che ritorna da elim
			x.primo=T; //in elim passo x.primo perchè è la testa della lista. Dopo averla modificata con elim, aggiorno la testa
	    }else T=T->next; // se non trovo una corrispondenza, avanzo in T
	    if(!T){ // se T è terminata
			T=x.primo; // la riporto all'inizio
			C=C->next; // e prendo in considerazione l'elemento dopo nella lista
		}
	}
	return x.primo;	
}
* -----
* Eliminare l'ultimo nodo di una lista, passaggio per riferimento
* void del(nodo* &L,int x){
	if(!L) L=new nodo(x,0);  // questo è possibile perchè L è passata per riferimento. L non è il nodo in sè, ma il collegamento(ovvero il puntatore) ad esso...
	else del(L->next,x);//...cioè con L = new nodo dico l'equivalente di L->next=new nodo nel passaggio per valore 
}
* -----
* Aggiungere un nodo in testa alla lista, passaggio per riferimento
* void add_head(nodo* &L,char info){
	nodo* testa=new nodo(info,L);
	L=testa; 
}
* -----
* Eliminare nodo coda lista
* void del_nodo_coda_2(nodo* &L) // lista passata per riferimento
{
	if(!L) return; // lista già vuota, non c'è nulla da deallocare
	
	if(!L->next) {nodo* fine=0;delete L;L=fine;}
	else del_nodo_coda_2(L->next);
}
* -----
* Elimino nodi da una lista con iter e passaggio per riferimento
* void elim(nodo*& C, int y){
	nodo*start=C,*prev=0;
	if(!C) return;
	while(C->next){
		if(C->next->info==y){
			nodo* tmp=C->next;
			C->next=tmp->next;
			delete tmp;
		}else C=C->next;
	}
	if(start->info==y){
		C=start->next;
		delete start;
	}else C=start;
}
* -----
*  elimino nodi da una lista con campo info=y con iterazione
*  nodo* togli(nodo* C,int y){
*     if(!C) return 0;
*     nodo*a=C; 
*     while(C->next){  
*         if(C->next->info==y){ 
*             nodo*tmp=C->next; 
*             C->next=tmp->next;  
*             delete tmp; 
*          }else C=C->next; 
*      } 
*     if(a->info==y){ //controllo del primo nodo
*         nodo*tmp=a; 
*         a=tmp->next; 
*         delete tmp; 
*      } 
*     return a;
*    } 
* ------
* elimino nodi da una lista con campo info=y con ricorsione 
*   nodo* togli(nodo* C,int y){ 
*       if(!C) return 0; 
*       C->next=togli(C->next,y);
*       if(C->info==y){ 
*           delete C; 
*           C=C->next; 
*        } 
*     return C; 
*    }
* ------
* da una lista, restituire quella match(non per forza contiguo e non per forza completo) in modo iterativo
* bool cerca(nodo* T,int* P,int dimP,nodo*& start){
	if(!T) return false;
	if(T->info1==*P){ 
		start=T;
		return true;
	}
	return cerca(T->next,P,dimP,start);
}
nodo* build_match(nodo*&T,int*P,int dimP){
	if(!T) return 0;
	if(T->info1==*P) return T;
	return build_match(T->next,P,dimP);
}

nodo* M1(nodo* T, int*P, int dimP){
	if(!T) return 0;
	nodo*start=0;
	if(cerca(T,P,dimP,start)){//start punta al primo nodo matchato
		nodo*tmp=start;
		for(int i=1;tmp;i++){
		    tmp->next=build_match(tmp->next,P+i,dimP);//questa funzione restituisce un nuovo nodo matchato ad ogni iterazione.//P+i serve per analizzare elemento per elemento nell'array Pattern
		    tmp=tmp->next;//e poi avanzo
		}
		cout<<endl;
		return start;
	}
	return 0;
}
* Altro modo più semplice ed elegante
* nodo* M1(nodo* T,int* P,int dimP){
	nodo* head=0,*body=0;bool first=true;
	while(T && dimP){
		if(T->info==*P){
			if(first){
				head=T;
				body=head;
				first=false;
			}else{
				body->next=T;
				body=body->next;
			}
			dimP--;P++;
		}
		T=T->next;
	}
	body->next=0;
	return head;
}
* ------
* da una lista, restituisco la sottolista contenente i nodi col campo info=y e quella dei nodi restanti. Sfrutto il passaggio per riferimento.
nodo* del_z(nodo*& list, int z){
	if(!list) return 0;
	if(list->info==z){
		nodo*tmp=list;
		list=list->next;
		tmp->next=del_z(list,z);
		return tmp;
	}
	return del_z(list->next,z);
} 	
* NEL MAIN ----> if(list){
           nodo*list2=del_z(list,z); stampa(list2); cout<<endl; stampa(list);
	      }
Altra soluzione migliore e fatta al ritorno
nodo* del_z(nodo*& L,int z){
	if(L){
		nodo* h=del_z(L->next,z);
		if(L->info==z){
			nodo* tmp=L;
			L=L->next;
			tmp->next=h;
			return tmp;
		}return h;
	}return 0;
}
* ------
* da una lista trovare il match contiguo e completo e restituire le due sottoliste(match e l-match cioè la restante)
* bool cerca(nodo* list,int *P,int dimP){//true sse esiste il match
     if(!dimP) return true;
     if(!list) return false;
     if(*P!=list->info) return false;
     return cerca(list->next,P+1,dimP-1);      
}
void calcolo(nodo* list,int dimP,nodo*&tmp){
   if(dimP==1){
	  tmp=list->next;
	  list->next=0;
  }else calcolo(list->next,dimP-1,tmp);
}
nodo* match(nodo*& list,int* P,int dimP){
	if(!list)
	   return 0;
	if(cerca(list,P,dimP)){ //qui list=primo nodo del match
		nodo* tmp;nodo*inizio=list;
		calcolo(list,dimP,tmp);
		list=tmp;
		return inizio;
	}   
	return match(list->next,P,dimP);	
}
* Come prima,ma versione più semplice ed elegante
bool cerca(nodo* L,int* P, int dimP){
	if(!dimP)return true;
	if(!L)return false;
	if(L->info!=*P) return false;
	return cerca(L->next,P+1,dimP-1);
}
nodo* match(nodo*& L,int* P,int dimP){
	if(L){
		if(cerca(L,P,dimP)){
			nodo* h=L;
			L=L->next;
			if(L && L->info!=*(P+1)) h->next=0;
			else h->next=match(L,P+1,dimP-1);
			return h;
		}return match(L->next,P,dimP);
	}return 0;
}
* 
* -----
* Da una lista, eliminare gli ultimi k nodi con campo info == y. ricorsione
* nodo* F(nodo*& L,int y, int& k){ // eliminare gli ultimi k nodi di L con campo info = y
	if(L){
		nodo* head=F(L->next,y,k);
		if(L->info==y && k){ // se ho trovato l'occorrenza e se ho ancora nodi da eliminare
			nodo* body=L; 
			//cout<<"BODY["<<body<<"]";
			L=L->next; // e cucio L
			body->next=head; 
			k--;
			return body;
		}
		return head;
	}
	return 0;
}
* -----
* /* SOLUZIONE DEL PROF
nodo* F(nodo*& L, int y, int k, int& v){
    if(L){
		if(L->info==y){
			v++; 
			nodo* T=F(L->next,y,k,v);
			if(v!=-1 && v<k){
				nodo* w=L;
				L=L->next;
				w->next=T;
				v++;
				return w;
			}
			return T;
		}
		return F(L->next,y,k,v);
	} if(v>=k) v=0;
	else v=-1;
	return 0;
}
* *
* 
* MADE BY Mattia Bottaro
 */ 
