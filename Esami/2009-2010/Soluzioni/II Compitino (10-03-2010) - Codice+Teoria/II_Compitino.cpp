#include<iostream>
using namespace std;

/*
TEORIA
(i) Si consideri il frammento di programma:

int y=1, *p=&y;
char c=static_cast<char>(p);

spiegate brevemente cosa fa e se è un’operazione corretta o no.

No: compie un'operazione errata in quanto cerca di cambiare il tipo di p in char tramite uno static cast.
Per compiere quest'operazione non si possono utilizzare cast alla C++, ma solo un cast alla C.

(ii) Si consideri il seguente programma e si spieghi se è corretto o no motivando la risposta:

int*& f(int** z) 
{
	int a=1;
	*z=&a;
	return *z;
}
main(){
	int a=2, *p=&a, **q=&p;
	*f(q)=*p+a;
}

Il programma e' banalmente errato, in quanto la funzione solleva un dangling pointer. Si assegna infatti a *z l'indirizzo di a
che e' una variabile locale della funzione e che verra' quindi deallocata al termine della funzione. Poi, se non ci fosse
il dangling pointer, la funzione sarebbe utilizzata correttamente in quanto si dereferenzia un puntatore avendo quindi la variabile
e assegnandoci un valore ovvero 4.

************* PROGRAMMAZIONE **************
1)data una lista L=l1->l2->l3->l4->..., per un k >0 dato, vogliamo prendere i suoi nodi lk, l(k*2), l(k*3), eccetera
e formare con essi una nuova lista Q= lk->l(k*2)->l(k*3)->..., mentre L conterrà i nodi della lista originale che non sono in Q.

(i) Scrivere PRE e POST per una funzione ricorsiva con prototipo nodo* slice(nodo*& L,int k, int n) che realizzi l’operazione descritta;
il parametro formale k è l’intero, usato nella descrizione precedente, che determina quali nodi "togliere" da L,
mentre n serve a scandire il numero dei nodi per sapere "quando è ora" di togliere un nodo da L.

(ii) Scrivere il codice di una funzione ricorsiva che realizzi l’operazione descritta;

(iii) dimostrare (usando l’induzione) che la funzione (ii) è corretta rispetto alla PRE e POST di (i).
*/

struct nodo {int info; nodo* next; nodo(int, nodo*);};
nodo::nodo (int a=0, nodo* b=0) {info=a; next=b;}

/* PRE = (L, lista valida con 0 o piu' nodi
		  k, valore int > 0
		  n, valore int > 0 che corrisponde al numero del nodo che stiamo processando)
*/
nodo* slice(nodo*& L,int k, int n){
	nodo * res, * temp;
	if (!L){
		return 0;
	}
	res = slice(L->next, k, n+1);
	if (n%k == 0){
		temp = L;
		L = L->next;
		temp->next = res;
		res = temp;
	}
	return res;
}
/*
POST = (La funzione ritorna la lista res direttamente che e' una lista composta dai nodi lk, l(k*2), l(k*3)
		della lista fornita in input e ritorna la lista L tramite un side effect che contiene tutti i nodi della
		vecchia lista L nello stesso ordine, senza pero' i nodi della lista res)

DIMOSTRAZIONE INDUTTIVA:
	Caso base:
		L == 0:
			La lista e' vuota o siamo arrivati alla fine della lista. Ritorna zero, corretto rispetto alla POST perche'
			da una lista vuota ci aspettiamo che il risultato sia un'altra lista vuota e che L non venga modificata (rimanendo
			quindi vuota anch'essa).
	Invocazione ricorsiva:
		Corretta rispetto alla PRE in quanto L-> e' sempre una lista valida con zero o piu' nodi visto che eseguiamo il controllo col caso base
		mentre k non varia e n+1 continua ad identificare il nodo corrente in quanto ci spostiamo di un nodo alla volta. Quindi, supponiamo vera
		anche la POST.
	Caso induttivo:
		n % k == 0:
			Se il numero che identifica il nodo diviso k da' come resto zero, signica che abbiamo in mano un nodo da processare. Togliamo quindi
			il nodo che abbiamo dalla lista L e lo mettiamo nella lista res, come ci chiede di fare la POST.
*/

/*
2) OPZIONALE: se voleste scomporre una lista L in k nuove liste la prima che contiene i nodi l1->l(k+1)->l(k*2+1)->…,
la seconda che contiene i nodi l2->l(k+2)->l(k*2+2)->…, …..e la k-esima che contiene i nodi lk->l(k*2)->l(k*3)->…,
come affrontereste il problema? Scrivere una PRE ed una POST ed il prototipo della funzione.
Questa funzione deve avere un parametro formale int k che indica il numero di liste
in cui scomporre quella originale.

PRE = (L, lista definita con zero o piu' nodi.
k, numero int > 0 che identifica il numero di liste in cui dobbiamo dividere la lista data.
A, array di lunghezza k con le liste che vogliamo come risultato.
n, int > 0, numero che identifica il nodo che stiamo processando della lista L.)

void F(int L, int k, nodo * * A, int n)

POST = (L modifica tramite side effect l'array A, inserendo in A[1] la lista l1->l(k+1)->l(k*2+1)->…,
		in A[2] la lista l2->l(k+2)->l(k*2+2)->…, ..., in A[k] la lista lk->l(k*2)->l(k*3)->…,
*/

/*
VERSIONE DEL PROF:


PRE = (L = l1->l2.. possibilmente vuoto, k > 0 e 1 <= n <= k)

POST = (L = P1P2P3.. e restituisce x1->x2->..)



*/
nodo* slice_prof(nodo*& L,int k, int n){
	if (!L){
		return 0;
	}
	if (n == k){
		nodo * x = slice_prof(L->next, k, 1);
		nodo * y = L;
		L = L->next;
		y->next = x;
		return y;
	}else{ // n<k
		return slice_prof(L->next, k, n+1);
	}
}

nodo* slice_prof2(nodo*& L,int k, int n){
	if (!L){
		return 0;
	}
	if (n == k){
		nodo * x = L;
		L = L->next;
		x->next = slice_prof2(L, 1, k);
		return x;
	}
}

int main(){
}
