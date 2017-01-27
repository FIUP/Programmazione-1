#include<iostream>
using namespace std;

/*
******************* Teoria *******************

1) Dato l'array char X[10][5][10], rispondere ai seguenti due punti:
i) che tipo ha *(*X-4)+2 e che differenza c'e' tra il suo valore e quello di X
RISPOSTA:
	Ha tipo char (*), *(*X-4)+2 si puo' scrivere anche come X[0][-4][2]
	quindi il suo valore e': x-(4*10*1)+(2*1) ovvero: x-40+2 = x-38
	dove x e' il valore di X.
ii) che tipo ha X[-1] e che differenza c'e' tra il suo valore e quello di X
RISPOSTA:
	Ha tipo char (*)[10], il suo valore e': x-(1*5*10*1) = x-50 dove x e' il valore
	iniziale di X.
2) Dire se e' corretto o no il seguente programma, spiegando la propria risposta:

int * f(int **p){
	int b = 3, *x = &b;
	**p = b;
	x = *p;
	return x;
}
main(){
	int y=5, b = 2, *q = &b;
	*f(&q)=y*2;
}
RISPOSTA:
	Il programma invoca correttamente rispetto ai tipi la funzione, dereferenzia infatti un puntatore
	per ottenere la variabile salvandoci dentro il valore 10. Il parametro passato poi alla funzione e'
	anch'esso corretto rispetto ai tipi visto che e' un doppio puntatore come richiesto dalla funzione.

	Anche la funzione e' corretta, in quanto prende il doppio puntatore e ritorna il puntatore
	"intermedio" che punta ad una variabile del main e non a una variabile locale della funzione, non
	sollevando alcun dangling-pointer. Quindi, sebbene la funzione faccia una cosa inutile
	(**p = b non ha alcun effetto, se venisse tolto la funzione funzionerebbe correttamente lo stesso)
	e' corretta.

******************* Programmazione iterativa *******************

Si tratta di fondere degli array ordinati per formare un unico array ordinato. Abbiamo un array int
A[limite][20] nel quale ogni riga e' ordinata in modo crescente e vogliamo con gli elementi di A riempire
un altro array R di interi ad una dimensione che contenga tutti gli elementi di A in ordine crescente. La
funzione che deve eseguire questo compito e' la seguente:
*/
int * F(int(*A)[20], int limite)
{
	int *R = new int[limite*20], *Inizio=new int[limite], r=0, k=0;
	for(int i=0; i<limite;i++) Inizio[i] = 0;
	for(int i=0; i<limite*20; i++){
		M(A, Inizio, limite, r, k);
		R[i] = A[r][k];
	}
	delete[] Inizio;
	return R;
}
/*
R e' l'array che contiene la fusione delle righe di A e Inizio serve per ricordarci "dove siamo arrivati
a prelevare" da ciascuna riga di A. Quindi ogni elemento di Inizio viene inizializzato a 0. Si chiede di
realizzare la funzione iterativa M che ad ogni invocazione restituisce gli indici r e k (passati per
riferimento) che individuano la posizione del minimo elemento di A tra quelli non ancora copiati in R.
Ovviamente M deve sfruttare il fatto che le righe di A sono ordinate. Si chiede:

(i) 	scrivere la PRE e POST di M. Nella PRE potete assumere che tutti gli elementi di A siano minori di MAX_INT.
(ii) 	scrivere il codice della funzione iterativa M che deve avere prototipo:
			void M(int(*A)[20], int * Inizio, int limite, int & r, int & k);
		in accordo all'invocazione nel corpo di F.
(iii) 	per il ciclo iterativo principale di M, scrivere la condizione che deve essere vera dopo il ciclo e usare
		la ricetta delineata nel Capitolo 6 della dispensa per ricavare in modo automatico l'invariante del ciclo.
*/

/*
PRE = (A, array di "limite" righe, 20 elementi per riga, definito e ogni riga ha i suoi elementi che sono ordinati
	   in modo crescente, tutti gli elementi di A sono < di MAX_INT.
	   Inizio, array definito di lunghezza "limite",
	   limite, valore int >= 0, r, valore int >= 0, k, valore int >= 0)
*/
void M(int(*A)[20], int * Inizio, int limite, int & r, int & k){
	k = Inizio[0]; r = 0;
	while (k = 20){
		r++;
		k = Inizio[r];
	}
	int min = A[r][k];
	// R = (A[r][k] < ogni elemento A[i][j] dove 0 <= i < riga e Inizio[i] <= j < 20)
	for (int riga = 0; riga < limite; riga++){
		int elem = Inizio[riga];
		if (elem < 20 && A[riga][elem] < min){
			min = A[riga][elem];
			r = riga;
			k = elem;
		}
	} // POST = (A[r][k] < ogni elemento A[i][j] dove 0 <= i < limite e Inizio[i] <= j < 20)
	Inizio[r] = Inizio[riga]+1;
}
/*
POST = (La funzione ritorna tramite side-effect r e k che indicano la riga e la colonna di A dove si trova
		l'elemento di valore minimo dell'array A dove da ogni riga di A sono stati esclusi gli elementi con
		indice < Inizio[riga])
*/

/*
******************* Programmazione ricorsiva *******************

Il problema e' analogo al precedente, ma A e' una lista tale che OGNI suo nodo punti ad un'altra lista
(possibilmente) vuota "normale" ordinata in modo crescente rispetto al campo info dei suoi nodi. Con i
nodi delle liste "normali" si vuole costruire un'unica lista ordinata R. I nodi della lista A hanno tipo
struct nodoP(nodo * info; nodoP*next;}; mentre le liste "normali" cosi' come la lista R da costruire, hanno
nodi del solito tipo: struct nodo{int info; nodo * next;}; La funzione ricorsiva che risolve il problema e'
la seguente:
*/
void H(nodoP * A, nodo *& R){
	nodoP * x = G(A);
	if (x){
		nodo * y = x->info;
		x->info = y->next;
		R = y;
		H(A, R->next);
	}else{
		R = 0;
	}
}
/*
Si chiede di realizzare la funzione ricorsiva G che ad ogni invocazione, sceglie tra le liste puntate da A quella
con il primo nodo minimo e restituisce il puntatore x al nodo di A che punta a questa lista. La funzione H (che e'
data) toglie il primo nodo dalla lista puntata da x e lo inserisce alla fine di R. Il prototipo di G deve essere
nodoP* G(nodoP*). Ovviamente alla fine di H il campo info di ogni nodo di A sara' diventato 0.

Precisamente sono richiesti i seguenti punti:
(i) 	scrivere PRE e POST per G
(ii) 	scrivere il codice della funzione ricorsiva G con prototipo: nodo P* G(nodoP * )
(iii) 	dimostrare con l'induzione la correttezza di G rispetto alla PRE e POST di (i)

*/

/*
PRE = (A, lista (anche vuota) di tipo nodoP * dove ogni suo campo info punta ad un'altra lista di tipo nodo * (anche vuota)
ordinata in modo crescente rispetto al campo info dei suoi nodi)
*/
nodoP * G(nodoP * A){
	if (!A){
		return 0;
	}
	nodoP * x = G(A->next)
	if (!A->info || x && x->info->info < A->info->info){
		return x;
	}
	return A;
}
/*
POST = (La funzione ritorna la lista puntata da A che ha il primo nodo il cui campo info e' minore rispetto
		al campo info di tutti gli altri primi nodi di ogni altra lista puntata da A)

DIMOSTRAZIONE PER INDUZIONE:

	Caso base:
		A == 0:
			La lista A e' vuota o sono arrivato alla fine della lista A fornita dalla prima invocazione.
			Ritorno zero, corretto rispetto alla POST.
	Invocazione ricorsiva:
		A siamo sicuri che esiste, quindi A->next e' un altro nodo valido o il nodo NULL, come richiestoci
		dalla PRE, pertanto vale la POST per ipotesi induttiva.
	Caso induttivo:
		x != 0 && x->info->info < A->info->info o A->info non esiste:
			Se x esiste e il suo campo info e' < del campo info di A allora il suo nodo ha il campo info
			minore rispetto a tutti gli altri processati pertanto ritorniamo x, come ritorniamo x anche quando
			A->info non esiste (quindi quel nodo punto ad una lista vuota) altrimenti se x non
			esiste o il suo campo info e' maggiore di quello di A, ritorniamo A, come richiestoci dalla POST.
*/
