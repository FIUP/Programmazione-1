// soluzione di B.Cosentino
#include<iostream>

#include<fstream>
using namespace std;


struct nodo{int info; nodo* left,*right; nodo(int a=0, nodo* b=0, nodo*c=0){info=a; left=b;right=c;}};
int contanodi(nodo* r);
nodo* alberobil (nodo*r, int k);
nodo* buildtree(nodo* r, int n);
void stampa_l(nodo* r);


// PRE_cerca = (albero(r) è corretto e non vuoto, k>=0 e y valore qualsiasi, C ha almeno tanti elementi quanta è l'altezza di albero(r))
bool cerca_cam(nodo*r, int k, int y, int*C){
    
    if (r->info==y) k--;
    
    // se r->info == y, k >= -1, altrimenti k >= 0
    
    if (k == -1) return false;
    
    // se r->info == y, k = vk-1 >= 0, altrimenti k >= 0 
    if (!r->left && !r->right){
        if (k==0){
            *C=-1;        
            return true; 
        }
        return false;
    }
    // (r->left || r->right) & (se r->info == y, k = vk-1 >= 0, altrimenti k >= 0)
    
    if (r->left){
        // PRE_ric1 = (albero(r->left) è corretto e non vuoto, k>=0 e y valore qualsiasi, C+1 ha almeno tanti elementi quanta è l'altezza di albero(r->left))
        bool cam = cerca_cam(r->left, k, y, C+1);
        // POST_ric1 = (restituisce true sse in r->left esiste un cammino da r->left ad una foglia con k nodi con campo info=y e false altrimenti) &
        // & (se restituisce true, C contiene una sequenza di 0/1 seguita da -1 che individua il cammino più a sinistra in albero(r->left) con esattamente k y)
        
        if (cam){
            *C=0;
            return true;
        }
    }
    
    // albero(r->left) vuoto || non esiste un cammino in albero(r->left)
    if (r->right){
        // PRE_ric2 = (albero(r->right) è corretto e non vuoto, k>=0 e y valore qualsiasi, C+1 ha almeno tanti elementi quanta è l'altezza di albero(r->right))
        bool cam = cerca_cam(r->right, k, y, C+1);
        // POST_ric2 = (restituisce true sse in r->right esiste un cammino da r->right ad una foglia con k nodi con campo info=y e false altrimenti) &
        // & (se restituisce true, C contiene una sequenza di 0/1 seguita da -1 che individua il cammino più a sinistra in albero(r->right) con esattamente k y)
        
        if (cam){
            *C=1;
            return true;
        }
    }
    // non esiste un cammino in albero(r->left) e in albero(r->right) 
    return false;
}

// POST_cerca = (restituisce true sse in r esiste un cammino da r ad una foglia con k nodi con campo info=y e false altrimenti) &
// (se restituisce true, C contiene una sequenza di 0/1 seguita da -1 che individua il cammino più a sinistra in albero(r) con esattamente k y). 

/*******************************************************************************
Dimostrazione

Se la radice e' nodo(y), allora cerco k-1 nodi con campo info = y, altrimenti ne
cerco sempre k.

Caso base:
    - Se k == -1, allora il nodo(y) trovato e' di troppo -> restituisco false -> 
      -> POST
    
    - So che k >= 0, allora se la radice r non ha rami e k == 0 non devo cercare altri
      nodi con campo info = y. Quindi, esiste un cammino e ne segno la fine in C
      con -1 e restituisco true. Altrimenti k >= 1 e non posso continuare a cercare
      perche' l'albero e' formato solo dalla radice -> non esiste un cammino con k
      nodi con campo info = y. Restituisco false -> POST 
    
    
Caso induttivo:
    So che esiste albero(r->left) o albero(r->right) corretti e non vuoti e k >= 0.
    
    - Se esiste albero(r->left) corretto e non vuoto, cerco un cammino con k >= 0 
      nodi con campo info = y in albero(r->left). 
      albero(r->left) e' piu' basso di albero(r) di 1 e C+1 ha un elemento 
      in meno di C -> C+1 ha tanti elementi quanta e' l'altezza di albero(r->left)
      Quindi, vale PRE_ric1. PRE_ric1 <cercacam> POST_ric1 comporta che 
      cam = (true sse esiste un cammino da r->left a una foglia con k nodi con 
      campo info = y e false altrimenti). Inoltre, C contiene una sequenza di 0/1 
      seguita da -1 che individua il cammino più a sinistra in albero(r->left) 
      con esattamente k y.
    
      2 casi:
        # Se cam == true, allora ho trovato il cammino e indico che percorre il 
          ramo sinistro ponendo *C = 0. Restituisco true -> POST
        # Se cam == false, allora non esiste il cammino cercato in albero(r->left)
        e cerco nel ramo a destra (guardare altro caso induttivo)

    - So che non esiste albero(r->left) oppure non esiste un cammino con 
      esattamente k nodi con campo info = y in albero(r->left).
      Se esiste albero(r->right) corretto e non vuoto, cerco un cammino con k >= 0 
      nodi con campo info = y in albero(r->right). 
      albero(r->right) e' piu' basso di albero(r) di 1 e C+1 ha un elemento 
      in meno di C -> C+1 ha tanti elementi quanta e' l'altezza di albero(r->right)
      Quindi, vale PRE_ric2. PRE_ric2 <cercacam> POST_ric2 comporta che 
      cam = (true sse esiste un cammino da r->right a una foglia con k nodi con 
      campo info = y e false altrimenti). Inoltre, C contiene una sequenza di 0/1 
      seguita da -1 che individua il cammino più a sinistra in albero(r->right) 
      con esattamente k y.
    
      2 casi:
        # Se cam == true, allora ho trovato il cammino e indico che percorre il 
          ramo destro ponendo *C = 1. Restituisco true -> POST
        # Se cam == false, allora non esiste il cammino cercato in albero(r->right)
    
    
    - Se non esiste un cammino in albero(r->left) e in albero(r->right), 
      restituisco false.
*******************************************************************************/

void sc(int C[]){
    
    if (*C != -1){
        cout << *C << ' ';
        sc(C+1);
    } else
        cout << "fine cammino" << endl;
    
}

main()
{
    int n, k,y;
    cin>>n;
    
    nodo* R=buildtree(0,n);//da esercizio 2
    
    cout<<"start"<<endl;
    
    stampa_l(R);
    
    cin>>k>>y;
    int C[30];
    
    bool b=cerca_cam(R,k,y,C); //da fare
    
    cout<<endl;
    if(b)
        {cout<<"trovato  cammino= "; sc(C);} //sc da fare 
    else
        cout<<"nessun cammino con "<<k<<" valori="<<y<<endl;
    cout<<"end";
}

int contanodi(nodo* r){
    
    if (!r)
        return 0;
        
    // r e' non vuoto
    
    return 1+contanodi(r->left)+contanodi(r->right);
    
}

// PRE = (albero(r) è corretto e bilanciato, valbero(r)=albero(r))
nodo* alberobil (nodo*r, int k){
    
    if (!r)
        return new nodo(k,0);
        
    // r non e' vuoto
    
    int countL = contanodi(r->left);
    int countR = contanodi(r->right);
    
    if (countL <= countR)
        r->left = alberobil(r->left, k);
    else    
        r->right = alberobil(r->right, k);
        
    return r;
}
// POST = (albero(r) è corretto e ancora bilanciato ed è ottenuto da valbero(r) aggiungendogli una nuova foglia con info=k)


// PRE = (albero(r) è corretto e bilanciato, n>=0, valbero(r)=albero(r))
nodo* buildtree(nodo* r, int n){
    
    if (!n)
        return r;
    
    int k;
    cin >> k;
    
    r = alberobil(r,k);
    
    return buildtree(r, n-1);
    
}
// POST = (restituisce valbero(r) con n nodi aggiuntivi inseriti in modo da conservare il bilanciamento)


void stampa_l(nodo* r){
    
    if (!r)
        cout << '_';
    else {
        cout << r->info << '(';
        stampa_l(r->left); 
        cout << ',';
        stampa_l(r->right);
        cout << ')';
    }
}
