
//soluzione by: Riccardo M.

#include<iostream>
#include<fstream>
using namespace std;

/////////////////////////////////////////////////////////////////////////
///////////////////////////  FUNZIONI DATE  /////////////////////////////
/////////////////////////////////////////////////////////////////////////

struct nodo{
    
    int info;
    nodo* left, *right;
    
    nodo(int a=0, nodo* b=0, nodo*c=0){
        
        info=a;
        left=b;
        right=c;
        
    }
    
};

struct innesto{
    
    bool l, r;
    nodo* N;
    innesto* next;
    
    innesto(bool a=false, bool b=false, nodo* c=0, innesto* d=0){
        
        l=a;
        r=b;
        N=c;
        next=d;
        
    }
    
};

void stampa_l(nodo *r, ofstream & OUT){
  
    if(r){
      
        OUT<<r->info<<'(';
        stampa_l(r->left,OUT);
        OUT<<',';
        stampa_l(r->right,OUT);
        OUT<<')';
    }
    
    else{
        
        OUT<< '_';
        
    }
    
}

int conta_n(nodo*r){
    
    if(!r){
        
        return 0;
        
    }
    
    else{
        
        return conta_n(r->left)+conta_n(r->right)+1;
        
    }
    
}

nodo* insert(nodo*r, int y){
    
    if(!r){
        
        return new nodo(y);
        
    }
   
    if(conta_n(r->left)<=conta_n(r->right)){
        
        r->left=insert(r->left,y);
        
    }
    
    else{
        
        r->right=insert(r->right,y); 
        
    }
    
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

void stampa(innesto* a, ofstream & OUT){
  
    if(a){
        
        OUT<<"left="<<a->l<<" right="<<a->r<<" nodo="<<a->N->info<<endl;
        stampa(a->next,OUT);
        
    }
    
    else{
    
        OUT<<endl;
        
    }

}


/////////////////////////////////////////////////////////////////////////
/////////////////////////  FUNZIONI CREATE  /////////////////////////////
/////////////////////////////////////////////////////////////////////////

//PRE_fine=(lista è lista corretta)
innesto* fine(innesto *lista){
    
    while(lista->next){         //Finchè esiste un nodo successivo
    
     /* R=(mi trovo al nodo lista e il nodo successivo esiste) */
    
        lista=lista->next;          //mi sposto
    }
    
    return lista;               //Ritorno il puntatore all'ultimo nodo
    
}
//POST_fine=(restituisce il puntatore all'ultimo nodo di tipo innesto della lista)


//PRE=(albero(R) corretto) //// bool l, bool r, nodo N, next
innesto* f0(nodo *R){
    
    if(!R){                         //Se l'albero è vuoto
        return 0;                       //non potrò avere punti di innesto
    }
    
    if(!R->left && !R->right){      //Se mancano entrambi i rami sinistro e destro
        return new innesto(1, 1, R, 0);     //allora questo sarà un punto di innesto con l e r true
    }
    
    
    if(!R->left || !R->right){      //Se manca solo il ramo sinistro o solo quello destro
    
        innesto *lista;                 //Crea una lista

        if(R->left){                            //Se manca solo il ramo destro (e quindi è presente quello sinistro)
            lista=f0(R->left);                      //crea una lista cercando nel ramo sinistro
            lista->next = new innesto(0, 1, R, 0);  //completa la lista inserendo le info sul nodo attuale
            return lista;                           //ritorna la lista
        }
        
        if(R->right){                           //Se manca solo il ramo sinistro (e quindi è presente quello destro)
            lista=new innesto(1, 0, R, 0);      //completa la lista inserendo le info sul ramo attuale
            lista->next = f0(R->right);
            return lista;                           //ritorna la lista
        }
        
    }
    
    else{                           //Se ci sono entrambi i rami sinistro e destro
        innesto *listaSx = f0(R->left);     //crea la lista sinistra cercando nel ramo sinistro
        innesto *listaDx = f0(R->right);    //crea la lista destra cercando nel ramo destro
        fine(listaSx)->next = listaDx;      //concatena la lista sinistra con quella destra
        return listaSx;                     //ritorna la lista completa
    }
    
}
//POST=(restituisce la lista dei punti d'innesto di albero(R) in ordine infisso)


//PRE=(lista(Inn) è corretta, in particolare ciascun nodo punta ad un corrispondente punto d'innesto di un qualche albero, INP contiene m interi seguiti dalla sentinella -2, 0<=m,
//     sia vInn il valore iniziale di lista(Inn))
int f1(innesto *&Inn, ifstream & INP){
    
    if(!Inn){                           //Se non ho alcun punto di innesto
        return 0;                           //non potrò innestare alcun nodo
    }
    
    int x=0, innesti=0;                 //Valore del campo info del nodo da innestare e numero di innesti fatti
    
        
    if(Inn->l){                         //Se posso innestare a sinistra
        INP>>x;                             //leggo il valore del nodo
 
        if(x!=-2){                          //se è diverso da -2
            Inn->N->left=new nodo(x);           //innesto
            innesti++;                          //conto l'innesto
            Inn->l=false;                       //segnalo che non potrò più innestare nello stesso punto
        }
    
        else{                               //altrimenti sono alla fine dell'input
            return innesti;                     //ritorno il numero di innesti fatti
        }
 
    }
  
    if(Inn->r){                         //Se posso innestare a destra
        INP>>x;                             //leggo il valore del nodo
  
        if(x!=-2){                          //se è diverso da -2
            Inn->N->right = new nodo(x);        //innesto
            innesti++;                          //conto l'innesto
            Inn->r=false;                       //segnalo che non potrò più innestare nello stesso punto
        }
    
        else{                               //altrimenti sono alla fine dell'input
            return innesti;                     //ritorno il numero di innesti fatti
        }
   
    }
    
    if(!Inn->l &&  !Inn->r){            //Se ho utilizzato sia il figlio sinistro che destro del nodo non potrò più innestare
        innesto* temp = Inn;                //creo un puntatore temporaneo
        Inn=Inn->next;                      //sposto la lista
        delete temp;                        //elimino il primo nodo inutilizzabile
    }
    return innesti+f1(Inn, INP);        //Ritorno il numero di innesti fatti fin'ora sommati a quelli che verranno fatti nei nodi successivi

}
//POST=(se vInn contiene n campi l/r a true, allora vengono letti x=min(m,n) valori da INP e aggiunti x nuovi nodi usando i punti di innesto di vInn in ordine;
//      f1 restituisce il valore di x e, in caso resti una parte di vInn non usata (succede quando n>m), questa lista rimasta deve essere il valore finale del parametro Inn.
//      La parte di vInn che è usata viene deallocata)



main(){
    
    ifstream IN("input");
    ofstream OUT("output");
    
    if(IN && OUT){ 
        
        int dim;
        IN>>dim;
        
        nodo* R=rep_ins(0,dim,IN);
        stampa_l(R,OUT);
        OUT<<endl;
        
        innesto* x=f0(R);
        
        stampa(x,OUT);
        
        int a=f1(x,IN);
        
        OUT<<"n. innesti="<<a<<endl;
        
        stampa_l(R,OUT);
        OUT<<endl;
        stampa(x,OUT);
   
        IN.close();
        OUT.close(); 
    }
  
    else{
        
        cout<<"errore con i files";
        
    }
 }
