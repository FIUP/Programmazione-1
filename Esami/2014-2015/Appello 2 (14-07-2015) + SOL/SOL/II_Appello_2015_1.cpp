
//soluzione by: Riccardo M.

#include<iostream>
#include<fstream>
using namespace std;

/////////////////////////////////////////////////////////////////////////
///////////////////////////  FUNZIONI DATE  /////////////////////////////
/////////////////////////////////////////////////////////////////////////

struct nodo{
    int info;
    nodo* next;
    
    nodo(int a=0, nodo* b=0){
        info=a;
        next=b;
    }
    
};

struct nodoT{
    int info;
    nodoT* left,* right;
    
    nodoT(int a=0, nodoT* b=0, nodoT* c=0){
        info=a;
        left=b;
        right=c;
    }
 
};

//PRE=(alt>=0)
nodo* costruisci_L(int alt){
    
    nodo* r=0;
    while(alt){
        r=new nodo(0,r);
        alt--;
    }
    return r;

}
//POST=(restituisce una lista con alt nodi con info=0)

nodoT*buildt(){
    nodoT* f1=new nodoT(10);
    nodoT* f2=new nodoT(20);
    nodoT*I=new nodoT(15,f1,f2);
    nodoT*R=new nodoT(2,I, new nodoT(23));
    return R;
}
//restituisce un albero per provare la vostra F1
//stampa gli alberi in forma lineare
void stampa_l(nodoT *r, ofstream & OUT){
    if(r){
        OUT<<r->info<<'(';
        stampa_l(r->left,OUT);
        OUT<<',';
        stampa_l(r->right, OUT);
        OUT<<')';
    }
    
    else
        OUT<< '_';
}

//stampa lista 
void stampa_L(nodo* x,ofstream& OUT){
    if(x){
        OUT<<x->info<<' ';
        stampa_L(x->next,OUT);
    }
    
    else
        OUT<<endl;
}
 

/////////////////////////////////////////////////////////////////////////
/////////////////////////  FUNZIONI CREATE  /////////////////////////////
/////////////////////////////////////////////////////////////////////////

//PRE=(L lista corretta, vL = L)
void azzera(nodo* L){
    if(!L){             //Lista vuota
        return;
    }

    L->info=0;          //Azzera il campo info del nodo corrente
    azzera(L->next);    //Azzera i successivi
}
//POST=(restituisce vL dove vL = L con tutti i campi info =0)

//PRE=(list(L) corretta, L=vL)
void F0(nodo*L, bool & b){

    if(!L){     //Lista vuota o non da modificare
        b=false;
        return;
    }

    F0(L->next, b);         //Scorri fino alla fine della lista

    if(!L->info && !b){     //Se il campo info di un nodo è 1 e b==false (ovvero la lista successiva è composta da solo nodi con campo info=1
        L->info =1;             //Metti il campo info del nodo attuale a 1
        azzera(L->next);        //Azzera i campi successivi
        b = true;               //Imposta b a true (la lista non sarà più composta da soli nodi con campo info = 0
        return;
    }

}
//POST=(b => lista(L) è ottenuta da lista(vL) facendo la trasformazione richiesta)&&(!b=> lista(vL) è tale che ogni nodo ha campo info=1 e lista(L)=lista(vL)

/*

    Dimostrazione della correttezza di F0 rispetto a PRE e POST date

    (1) Caso base = lista vuota
        L non contiene alcun nodo quindi, paradossalmente, il campo info dei suoi nodi può essere considerato 1, e dunque b viene impostata a false => rispetta POST

    (2) Passo induttivo = lista corretta con almeno un nodo
        L'invocazione ricorsiva di F0 rispetta PRE_F0 in quanto ci troviamo in un nodo definito e, di conseguenza, L->next e' una lista corretta alla quale non è stato
        cambiato il valore di nessun campo info => PRE=(list(L) corretta, L=vL) rispettata

        L'invocazione ricorsiva di F0 rispetta anche POST_F0 in quanto se si ha un solo nodo quello successivo sarà vuoto e, come visto nel caso base (1) questa
        casistica rispetta POST_F0.

        Ora vengono eseguite le istruzioni successive, ovvero:

        (a) Se il campo info del nodo considerato è uguale a 0 e la lista che parte da L->next è composta solamente da nodi con campo info = 1 (ovvero b == false),
            allora il campo info del nodo attuale viene posto a 1, e vengono azzerati i campi info successivi (*), inoltre b viene posto a true per identificare che
            non tutta la lista è composta da 1.

        (b) Se il campo info del nodo considerato è uguale a 1, non viene eseguito nulla, a significare che la lista è attualmente composta da soli nodi con campo
            info = 1 (b==false).

        Entrambi i casi (a) e (b) rispettano POST_F0.


        (*) All'interno di F0 viene utilizzata azzera. Vediamo di verificarne la correttezza rispetto a PRE_ric.

            Se il nodo di L considerato è stato posto a 1, significa che esso esiste e, dunque, L->next sara' una lista corretta => rispetta PRE_azzera

            Al ritorno, L->next, data POST_azzera, sara' composta da tutti i nodi con campo info = 0 => rispetta POST_azzera

*/


//PRE=(R albero corretto, vuoto)
nodoT* aggiungi_nodo(nodoT* R, ifstream &INP){    //Aggiunge un nodo ad un nodo inesistente

    int x;              //Creo una variabile intera dove poter salvare il valore letto da INP
    INP>>x;             //Leggo il valore
    R=new nodoT(x);     //Creo un nuovo nodo con quel valore letto
    return R;           //Restituisco l'indirizzo del nodo appena creato

}
//POST=(restituisce l'indirizzo di un nuovo nodo R creato leggendo da INP il valore del campo info)

//PRE=(albero(R)corretto, 0<prof, INP ifstream definito, R=vR, INP contiene (almeno) 2(alt+1)-1 valori)
nodoT * F1(nodoT* R, int alt, ifstream & INP){

    if(!R){                 //Se non c'e' la radice creala
        int x;
        INP>>x;
        R = new nodoT(x);
    }

    nodo* L=costruisci_L(alt);  //Costruisci la prima lista vuota
    nodo* currL =L;             //Puntatore di riferimento all'interno di L
    nodoT* currT =R;            //Puntatore di riferimento all'interno dell'albero R
    bool b = true;              //Booleana per F0

    while(b){                   //Fintato che la lista L non e' composta tutta da 1 e non vi si puo' aggiungere piu' nulla

        /* R = (b == true => la lista L presenta almeno uno 0 al suo interno)*/

        currL = L;              //Imposta il puntatore all'interno di L all'inizio di L
        currT = R;              //Imposta il puntatore all'interno dell'albero alla sua radice

        while(currL){                               //Data una lista la scorre tutta e aggiunge i nodi che non ci sono

            /* R=(currL non e' vuota)&&(mi trovo al nodo di R che si trova seguendo il percorso scritto dal primo nodo a quello attuale di L) */

            if(!currL->info){                                   //Se leggo 0
                if(!currT->left){                                   //Se non ho il ramo di sinistra
                    currT->left = aggiungi_nodo(R->left, INP);          //Lo creo
                }
                currT = currT->left;                                //Mi sposto a sinistra
            }

            else{                                               //Se leggo 1
                if(!currT->right){                                  //Se non ho il ramo di destra
                    currT->right = aggiungi_nodo(R->right, INP);        //Lo creo
                }
                currT = currT->right;                               //Mi sposto a destra
            }

            currL = currL->next;

        }

        F0(L, b);                                               //Aggiungo un 1 a L
    }

        return R;

}
//POST=(albero(R)è ottenuto da albero(vR) aggiungendo tutti i nodi non già presenti in albero(vR) di tutti i cammini di lunghezza alt, i campi info dei nodi sono
//      letti da INP. I cammini vanno considerati partendo del cammino con soli 0, poi applicando F0 ripetutamente


main(){
    
    ifstream IN("input");
    ofstream OUT("output");
    if(IN && OUT){ 
        
        int alt;
   
        IN>>alt;
        nodo*L=costruisci_L(alt);
        bool b=true;
        
        while(b){
            stampa_L(L,OUT); 
            F0(L, b);
        }

        nodoT*R=F1(0,alt,IN);
        stampa_l(R,OUT);
        
        OUT<<endl;
        
        nodoT*K=buildt();
        stampa_l(K,OUT);
        
        OUT<<endl;
        
        K=F1(K,alt,IN);
        stampa_l(K,OUT);
        
        IN.close();
        OUT.close();
        
    }
  
  else
    cout<<"errore con i files";
 }
