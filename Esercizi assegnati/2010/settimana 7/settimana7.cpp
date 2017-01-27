#include<iostream>
using namespace std;

struct nodo {int info; nodo* next; nodo(int, nodo*);};
nodo::nodo (int a=0, nodo* b=0) {info=a; next=b;}
	
struct DN {nodo* L1, * L2;};

// PRE = (L e' una lista con 0 o piu' nodi a1, a2... an)
DN S(nodo*L){
	DN x; x.L1 = 0; x.L2 = 0;	
	if (L){
		if (L->next){
			x = S(L->next->next);		
			L->next->next = x.L2;
			x.L2 = L->next;
			L->next = x.L1;
		}
		x.L1 = L;
	}
	return x;
}
/* POST = {La funzione restituisce una struttura Doppio Nodo dove nel campo L1 c'e' una lista con i nodi
dispari di L, cioe' a1, a3, .. an (se n % 2 = 0 altrimenti n-1) mentre in L2 con i nodi pari,
cioe' a2, a4, .. an (se n % 2 = 1 altrimenti n-1)}

 --- DIMOSTRAZIONE PER INDUZIONE: ---
 Invocazione ricorsiva:
	Quando arrivo al punto di invocare ricorsivamente S, L->next->next e' un nodo valido, quindi vale la PRE, in quanto ci siamo assicurati che 
	L e L->next esistono e quindi L->next->next al massimo puo' essere NULL che e' comunque un nodo valido [che ritorna x(0,0)].
 Caso base: 
	*L == 0: La lista e' vuota o sono arrivato alla fine della lista. Ritorno x.L1 e x.L2 uguali a zero. La funzione e' corretta perche'
	da una lista vuota mi aspetto che venga prodotto un doppio nodo con liste vuote.
	*L->next == 0:
		Se il campo next vale zero, vuol dire che il nodo L e' un nodo dispari visto che saltiamo due nodi alla volta. Quindi la lista ha
		o un nodo solo, o tre o cinque e cosi' via e siamo sull'ultimo nodo. Pertanto, non tocchiamo x.L2 che contiene solo i nodi pari e 
		ritorniamo x.L1 che contiene l'ultimo nodo che punta a zero e x.L2 che punta a zero.	
 Passo induttivo:
	*L->next != 0:
		Viene fatta un'invocazione ricorsiva della funzione saltando due nodi alla volta in modo da arrivare all'ultimo nodo che ha un
		campo next valido. Viene quindi assegnato al campo L->next->next il puntatore x.L2 e si collega il nodo successivo
		di L al nodo puntato da x.L2, cioe'al resto della lista L2. Si "aggiorna" poi x.L2 facendolo puntare al nuovo nodo che e' stato aggiunto a L2.	
	A questo punto, sappiamo che abbiamo almeno un nodo e che se ne abbiamo due abbiamo gia' gestito il secondo nel caso L->next != 0.
	Colleghiamo allora il primo nodo dei due o l'unico che abbiamo (che e' comunque dispari, dato che saltiamo due nodi alla volta) al resto
	della lista x.L1 e aggiorniamo x.L1 in modo che punti al nuovo nodo processato, ovvero L. In realta', colleghiamo L->next con x.L1 solo
	se abbiamo due nodi, visto che se L->next non esiste, vuol dire che L e' l'ultimo nodo che abbiamo che punta gia' a zero, che e' inutile
	collegarlo a x.L1 che e' a zero.
	
	Pertanto, cosi' facendo, la funzione crea due nuove liste x.L1 e x.L2 che hanno gli stessi nodi di L, con indici alterni (L1 con gli indici 
	dispari, L2 con quelli pari) come richiesto dalla POST.
*/

// PRE = (L e' una lista con 0 o piu' nodi a1, a2... an, 
//		  L1 e L2 sono due nodi, separati, che possono essere inizializzati gia' a zero come no)
void R(nodo*L, nodo*&L1, nodo*&L2){
	L1 = 0; L2 = 0;	
	if (L){
		if (L->next){
			R(L->next->next, L1, L2);		
			L->next->next = L2;
			L2 = L->next;
			L->next = L1;
		}
		L1 = L;
	}
}
/* POST = {La funzione produce side-effect su L1 e L2 passati per riferimento, in questo modo
in L1 c'e' una lista con i nodi dispari di L, cioe' a1, a3, .. an (se n % 2 = 0 altrimenti n-1) 
mentre in L2 con i nodi pari, cioe' a2, a4, .. an (se n % 2 = 1 altrimenti n-1)}

 --- DIMOSTRAZIONE PER INDUZIONE: ---

 Caso base: 
	*L == 0: La lista e' vuota o sono arrivato alla fine della lista. L1 e L2 non vengono modificati e rimangono uguali a zero. 
	La funzione e' corretta perche' da una lista vuota mi aspetto che la funzione definisca L1 e L2 con liste vuote 
	(supportando anche il caso non fossero gia' state definite come tali).
	*L->next == 0:
		Se il campo next vale zero, vuol dire che il nodo L e' un nodo dispari visto che saltiamo due nodi alla volta. Ne consegue che la lista ha
		o un nodo solo, o tre o cinque e cosi' via e siamo sull'ultimo nodo. Quindi, non tocchiamo L2 che contiene solo i nodi pari e 
		modifichiamo L1 in modo che contenga l'ultimo nodo che punta a zero e L2 che punta direttamente a zero.	
 Passo induttivo:
	*L->next != 0:
		Viene fatta un'invocazione ricorsiva della funzione saltando due nodi alla volta in modo da arrivare all'ultimo nodo che ha un
		campo next valido. Viene poi assegnato al campo L->next->next il puntatore L2 e si collega il nodo successivo
		di L al nodo puntato da L2, cioe'al resto della lista L2. Si "aggiorna" quindi L2 facendolo puntare al nuovo nodo che e' stato aggiunto.	
	A questo punto, sappiamo che abbiamo almeno un nodo e che se ne abbiamo due abbiamo gia' gestito il secondo nel caso L->next != 0.
	Colleghiamo allora il primo nodo dei due o l'unico che abbiamo (che e' comunque dispari, dato che saltiamo due nodi alla volta) al resto
	della lista L1 e aggiorniamo L1 in modo che punti al nodo processato, ovvero L. In realta', colleghiamo L->next con L1 solo
	se abbiamo due nodi, visto che se L->next non esiste, vuol dire che L e' l'ultimo nodo che punta gia' a zero, ed e' inutile
	farlo puntare nuovamente a 0.
	
	Pertanto, cosi' facendo, la funzione modifica attraverso il side-effect le due liste L1 e L2 che alla fine hanno gli stessi nodi di L, 
	con indici alterni (L1 con gli indici dispari, L2 con quelli pari) come richiesto dalla POST.
*/

void R2(nodo*L, nodo*&L1, nodo*&L2){
	L1 = 0; L2 = 0;	
	if (L){
		L1 = L;
		if (L->next){
			L2 = L->next;
			R(L->next->next, L1->next, L2->next);		
		}
	}
}

int main(){} 
