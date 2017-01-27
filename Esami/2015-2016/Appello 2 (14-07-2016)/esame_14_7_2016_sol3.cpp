//Soluzione alternativa di Cristian Maschio
#include<iostream>
using namespace std;
#include<fstream>
struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}}; // nodo di lista
struct FIFO{nodo* primo, *ultimo;FIFO(nodo*a=0, nodo*b=0){primo=a; ultimo=b;}};
struct nodot{int info; nodot* left, *right; nodot(int a=0, nodot* b=0, nodot* c=0){info=a; left=b; right=c;}};//nodo di albero
FIFO push_end(FIFO a, nodo*b)
{
  if(!a.primo)
  {a.primo=a.ultimo=b;}
  else
   {a.ultimo->next=b; a.ultimo=b;}
  return a;
}

void stampa_L(nodo*L)
{
 if (L)
  {cout<<L->info<<' '; stampa_L(L->next);}
 else
   cout<<endl;

}
nodo* costruisci(int dim)
{
 if(dim)
   {int x; cin>>x; return new nodo(x,costruisci(dim-1));}
 return 0;
}
 nodo* clone(nodo*a)
 {
  if(a)
  {return new nodo(a->info, clone(a->next));}
  return 0;
 }

 FIFO  push_begin(FIFO x, nodo* b)
 {
     if (!x.primo) {
         x.primo=x.ultimo=b;
     }else
     {
         b->next=x.primo;
        x.primo=b;
     }
     return x;
 }
 //PRE(L(Q) e' una lista corretta
 bool togli (nodo*Q, int x)
 {
     if(!Q)return false;
     if (Q->info==x){
         return true;
     }
     return togli (Q->next,x);
 }//POST(ritorna true se e' presente un nodo con campo info=x altrimenti se non ha trovato nessun nodo con campo info=x ritorna falso)

 bool togli_iter (nodo*Q, int x)
 {
     while (Q)
     {
         if (Q->info==x){
         return true;
        }
        Q=Q->next;
     }
     return false;
 }
 FIFO unisci_fifo (FIFO a, FIFO b)
 {
     if (!b.primo)return a;
     if (!a.primo)return b;
     a.ultimo->next=b.primo;
     a.ultimo=b.ultimo;
     return a;
 }
//PRE=(L(Q) è una lista corretta e vL(Q)=L(Q))
 FIFO tieni_ultimo_ric(nodo*&Q)
 {
     if (!Q)return 0; //c.b.1
     bool c=togli(Q->next,Q->info);
     FIFO a;
     FIFO b;
     if (c) //c.b.2
     {
         nodo* app=Q;
         Q=Q->next;
         app->next=0;
         a=push_end(a,app);
         b=tieni_ultimo_ric(Q);
         a=unisci_fifo(a,b); //unisco i FIFO che mi torneranno con la ricorsione
     }else{
        b=tieni_ultimo_ric(Q->next);
        a=unisci_fifo(a,b); //unisco i FIFO che mi torneranno con la ricorsione
     }
     return a;
 }
/*POST=(L(Q) è ottenuta da vL(Q) eliminando i nodi con info ripetuto mantenendo solo l'ultimo nodo per ciascun campo info
e mantenendo l'ordine relativo che questi nodi hanno in vL(Q). Inoltre restituisce un valore FIFO a tale che a.pri
mo è la lista dei nodi eliminati nello stesso ordine relativo che essi hanno in vL(Q))*/

/*Prova induttiva:
    c.b.1: se !Q e' vuoto, ritorno 0, altrimenti continuo..
    c.b.2: a:(c==true) allora l'elemento della lista e' contenuto,
            quindi lo inserisco nella lista rimasti e lo elimino dalla
            lista base
           b:(c==false) significa che e' l'unico elemento della lista con quel
            campo info, quindi non lo elimino

PREric:(L(Q->next) è una lista corretta e vL(Q->next)=L(Q->next))
POST=(L(Q->next) è ottenuta da vL(Q->next) eliminando i nodi con info ripetuto mantenendo solo l'ultimo nodo per ciascun campo info
e mantenendo l'ordine relativo che questi nodi hanno in vL(Q->next). Inoltre restituisce un valore FIFO a tale che a.pri
mo è la lista dei nodi eliminati nello stesso ordine relativo che essi hanno in vL(Q->next))
*/



 //PRE=(L(Q) è una lista corretta e vL(Q)=L(Q))
  FIFO tieni_ultimo_iter(nodo*&Q)
 {
     if (!Q)return 0;

     FIFO a;
     FIFO b;
     nodo* B=Q;
     while (B)  //R=(B=lista corretta != 0) && c=true or c=false && FIFO a contiene primo e ultimo della lista eliminati
                //FIFO b contiene primo e ultimo lista con nodi non ripetuti
     {
         bool c=togli_iter(B->next,B->info);
         if (c)
         {
             nodo* app=B;
             B=B->next;
             app->next=0;
             a=push_end(a,app);
         }else{
            nodo* app=B;
            B=B->next;
            app->next=0;
            b=push_end(b,app);
         }
     }
     Q=b.primo;
     return a;
 }
 /*POST=(L(Q) è ottenuta da vL(Q) eliminando i nodi con info ripetuto mantenendo solo l'ultimo nodo per ciascun campo info
e mantenendo l'ordine relativo che questi nodi hanno in vL(Q). Inoltre restituisce un valore FIFO f tale che f.pri
mo è la lista dei nodi eliminati nello stesso ordine relativo che essi hanno in vL(Q))*/

main()
{

   int dim;

   cin>>dim;
   nodo*C=costruisci(dim);
   nodo* D=clone(C);
   cout<<"Lista costruita"<<endl;
   stampa_L(C);
   FIFO a =tieni_ultimo_ric(C);
   cout<<"soluzione ricorsiva"<<endl<<"nodi tolti:"<<endl;

   stampa_L(a.primo);
   cout<<"lista rimanente:"<<endl;
   stampa_L(C);
   FIFO b=tieni_ultimo_iter(D); //iter
   cout<<"soluzione iterativa"<<endl<<"nodi tolti:"<<endl;
   stampa_L(b.primo); //iter
//stampa_L(a.primo); //ric
   cout<<"lista rimanente:"<<endl;
   stampa_L(D); //iter
 //stampa_L(C); //ric
   cout<<"end";
}


/*TEORIA:
PRE(Albero(r) non vuoto, almeno un nodo)
POST (Conta i rami/nodi con una sola foglia all'interno,  nel caso non ci siano entrambe le foglie non conta nulla e torna 0)
*/
