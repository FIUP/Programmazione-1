#include<iostream>
using namespace std;

// PRE = (A e' un array monodimensionale in cui sono presenti i numeri su cui lavorare
//		  top e' limite dell'array dato, top > 0) && (vA = A)
void S(int * A, int top);
// POST = (La funzione produce un array A = [0..top-2] che e' uguale a vA[1..top-1])

// PRE = (A[0..top-1] e' un array monodimensionale definito
//		  top e' il limite dell'array dato, valore int >= 0
//		  y valore int > 0 da cercare e da eliminare da A) && (siano [a1.. ak] gli elementi di A[0..top-1] che sono
//        != y nello stesso ordine che hanno A[0..top-1])
int F(int*A, int top, int y);
// POST = ( La funzione restituisce k per riferimento e A per side-effect, tali che A[0..k-1] = [a1...ak])

void S(int * A, int top){
	if (top > 1){
		*A = *(A+1);
		S(A+1, top-1);
	}else{
		*A = 0;
	}
}

int F(int*A, int top, int y){
	if (!top){
	    return 0;
	}
    if (*A == y){
        S(A, top);
        return F(A, top-1, y);
    }else{
        return 1+F(A+1, top-1, y);
    }
}

/*
 Caso base: top == 0: sono arrivato alla fine dell'array, ritorno zero che e' quindi il valore iniziale di ntop, corretto rispetto alla POST.
 Passo induttivo:
 	*A==y:
		viene invocata la funzione S che cancella l'elemento y semplicemente spostando tutti gli elementi dopo y di
		una posizione a sinistra. Quindi, invoco F(A, top-1, y) e salvo il suo valore nella variabile ntop.
	*A!=y:
		non devo cancellare il valore in soggetto, quindi mi limito a invocare la funzione F con A spostato di uno in avanti
		per processare l'elemento successivo. Incremento poi ntop perche', al contrario di prima, non ho accorciato l'array.
	Il processo andra' avanti fino a quando top ==0, ovvero fino al caso base, quando l'array non ha piu' elementi da processare.
Invocazione ricorsiva:
    sappiamo che top-1 e' come minimo zero (perche' se arriviamo al punto dell'invocazione vuol dire che top e' almeno 1), quindi corretto
    rispetto alla PRE. y rimane y, A rimane A nel primo caso, nel secondo diventa A+1, ma essendo top > 0 allora vuol dire che almeno il
    prossimo elemento e' definito, quindi possiamo farlo. Corretto rispetto alla POST.
*/

main(){
}
