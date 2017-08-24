// soluzione di B.Cosentino
#include<iostream>
using namespace std;

struct nodo{char info; nodo* left,*right; nodo(int a=0, nodo*b=0,nodo*c=0){info=a; left=b; right=c;}};

nodo* parse(char*& A){
    if(*A>='a' && *A<='z'){
        char p=*A;
        
        if(*(A+1) !='(') throw (1);
        A=A+2;
        
        nodo*l=parse(A);
        if(*A != ',') throw (2);
        A=A+1;
        
        nodo*r=parse(A);
        if(*A !=')') throw(3);
        
        A=A+1;
        return new nodo(p,l,r);
    }
    else
        if(*A=='_'){
            A=A+1;
            return 0;
        } else
            throw (4);
}





// PRE = (albero(r) è corretto, prof>=0, minprof>=0, minleaf è 0 o punta ad un nodo se e' stato trovato il minimo)
void mleaf(nodo* r, int prof, int & minprof, nodo *& minleaf){
    
    if (!r) return;
    
    // r e' non vuoto
    if (minleaf && prof>=minprof) return; // se minleaf non e' 0 e prof >= minprof allora non esploro l'albero(r)
    
    // r e' non vuoto e (o prof < minprof (la profondita' di r e' minore della profondita' minima) o minleaf = 0)
    if (!r->left && !r->right){
        minprof=prof;
        minleaf=r;
        return;
    }
    
    // r->left || r-> right e prof < minprof || minleaf = 0
    
    
    // PRE_ric1 = (albero(r->left) è corretto, prof+1 >=0, minprof>=0 e minleaf = 0 se non e' stato trovato il minimo, altrimenti minleaf punta a un nodo)
    mleaf(r->left, prof+1, minprof, minleaf);
    // POST_ric1 = ( (minprof = profondita' minima di una foglia di albero(r->left)) && (minleaf = puntatore a tale foglia di albero(r->left)) ) ||
    //             || (minleaf = vminleaf && minprof = vminprof se non esiste il minimo in albero(r->left))
    // minprof = profondita' minima albero(r->left) e minleaf punta alla foglia minima di albero(r->left)
    
    // PRE_ric2 = (albero(r->right) è corretto, prof+1 >=0, minprof>=0 e minleaf = 0 se non e' stato trovato il minimo, altrimenti minleaf punta a un nodo)
    mleaf(r->right, prof+1, minprof, minleaf);
    // POST_ric2 = ( (minprof = profondita' minima di una foglia di albero(r->right)) && (minleaf = puntatore a tale foglia di albero(r->right)) ) ||
    //             || (minleaf = vminleaf && minprof = vminprof se non esiste il minimo in albero(r->right))    
}
// POST = ( (minprof = profondita' minima di una foglia di albero(r)) && (minleaf = puntatore a tale foglia di albero(r)) ) || 
//        || (minleaf = vminleaf && minprof = vminprof se non esiste il minimo in albero(r))


/*******************************************************************************
Dimostrazione

Casi base:
    - Se r e' vuoto, allora non devo cercare il nodo a profondita' minima -> POST
    
    - So che r non e' vuoto. Se minleaf e' un valore valido e prof >= minprof, 
      allora albero(r) si trova a una profondita' maggiore di quella minima.
      Quindi, non cerco in albero(r) -> POST
      
    - So che albero(r) e' non vuoto e prof<minprof || minleaf=0.
      Se albero(r) e' composto solo da una foglia e minleaf = 0 (ovvero non ho 
      trovato nessun nodo a profondita' minima), allora il 
      nodo a profondita' minima e' nodo(r). Pongo minprof = prof e minleaf punta
      a nodo(r). -> POST
      Se albero(r) e' composto solo da una foglia e minprof > prof, allora il 
      nodo a profondita' minima e' nodo(r). Pongo minprof = prof e minleaf punta 
      a nodo(r). -> POST
      
Casi induttivi:
    So che albero(r->left) e' corretto e albero(r->right) sono corretti e 
    prof < minprof || minleaf = 0 oppure punta a un nodo.
    So dalla PRE che prof>=0 e che minprof>=0 -> prof+1 >=0 e minprof>=0.
    
    Quindi, vale PRE_ric1. Quindi, PRE_ric1<mleaf>POST_ric1 -> 
    -> ( (minprof = profondita' minima di una foglia di albero(r->left)) && 
    && (minleaf = puntatore a tale foglia di albero(r->left)) ) ||
    || (minleaf = vminleaf && minprof = vminprof se non esiste il minimo in albero(r->left))

    Quindi, vale PRE_ric2. Quindi, PRE_ric2<mleaf>POST_ric2 -> 
    -> ( (minprof = profondita' minima di una foglia di albero(r->right)) && 
    && (minleaf = puntatore a tale foglia di albero(r->right)) ) ||
    || (minleaf = vminleaf && minprof = vminprof se non esiste il minimo in albero(r->right))

    Quindi, se il minimo si trova in albero(r->left) allora dopo
    <mleaf(r->right, prof+1, minprof, minleaf)> 
    minprof = vminprof  
    minleaf = vminleaf,
    ovvero quelli trovati in albero(r->left) -> POST
    
    Se il minimo si trova in albero(r->right), allora dopo 
    <mleaf(r->right, prof+1, minprof, minleaf)> 
    minprof = profondita' minima di una foglia di albero(r->right) = minprof(albero(r)) 
    minleaf = puntatore a tale foglia di albero(r->right) = minleaf(albero(r))
    Quindi, vale POST
    
*******************************************************************************/
main(){
    try{
        char A[100],y,*q=A;
    
        while(y!='$'){
        	cin>>y;
        	*q=y;
        	q++;
        }
        
        q=A;
        nodo* R=parse(q);
        
        cout<<"start"<<endl;
        
        int a;
        nodo*b=0;
        
        mleaf(R,0,a,b);
        
        cout<<"prof="<<a<<" info foglia="<< b->info<<endl;
        cout<<"end"<<endl;
    }
    
    catch(int x){
        switch(x){
            case 1: cout<<"manca ("<<endl;   break;
            case 2: cout<<"manca ," <<endl; break;
            case 3: cout<<"manca )"<<endl;   break;
            case 4: cout<<"non albero"<<endl;   break;
        }
    }
}
