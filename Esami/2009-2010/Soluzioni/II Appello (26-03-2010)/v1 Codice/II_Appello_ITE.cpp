#include <iostream>
using namespace std;

struct nodo {int info; nodo* next; nodo(int a=0,nodo* b=0){info=a;next=b;}};

nodo* crea(int dim,int n) {
    if(!dim) return 0;
    else{
        return new nodo(n,crea(dim-1,n+1));
    }
}

void stampa(nodo* L) {
    if(L){
        cout<<L->info<<" ";
        stampa(L->next);
    }
}
/*
devo assolutamente gestire la lista con due indici perchè
se usassi la lista stessa andrei a cancellare tutti i nodi
perchè per scorrerla userei il comando L=L->next, il che è un
errore, come ben sappiamo quindi, l'unica maniera è quella di
usare due puntatori a nodo. Due perchè uno mi servirà per fare
il controllo sull'uguaglianza e un altro, per andare ad agganciare
in nodo successivo a quello che soddisfa la nostra ricerca.
QUANDO ABBIAMO UNA LISTA PASSATA PER RIFERMENTO È FONDAMENTALE USARE
UN PUNTATORE A NODO PER MUOVERMI DENTRO LA LISTA.
*/
void estrae (nodo* &L,nodo* N) {
    nodo *primo=L;
    nodo *secondo=L->next;
    if(primo->info==N->info) {
        L=L->next;
    }
    else
        {
        bool OK=false;
        while(secondo && !OK) {
            if(secondo->info==N->info) {primo->next=secondo->next; OK=true;}
            else
                primo=secondo;
                secondo=secondo->next;
        }
    }
}

nodo* MI(nodo*&L, int*P, int dim_P)
{
nodo** M=new nodo*[dim_P];//array di puntatori a nodo
int n=0;

nodo* origin=L;

while(origin && n<dim_P)
{
    if(origin->info==P[n])
    {
    M[n]=origin;
    n++;
    }
origin=origin->next;
}

nodo* E= 0,*fine;
if(n==dim_P)
    {
    E=fine=M[0];
    estrae(L,M[0]);
    for(int i=1; i<dim_P;i++)
        {
        estrae(L,M[i]);
        fine->next=M[i];
        fine=M[i];
    }
    fine->next=0;
}
delete[] M;

return E;
}

main() {
    nodo* L= crea(10,-3);
    stampa(L);cout<<endl;
    int P[3]={1,2,6};
    nodo*E=MI(L,P,3);
    stampa(L);cout<<endl;
    stampa(E);
}
