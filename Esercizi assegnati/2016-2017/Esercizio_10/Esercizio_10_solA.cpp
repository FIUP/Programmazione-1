// soluzione di B.Cosentino
#include<iostream>
using namespace std;
//PRE: cin contiene un intero n
int main () {
	int n, a=0, b=0, c=0, d=0;
	int quad=0;
	cin >> n;
	if (n>3) {
		int i=0;
		cin >> a >> b >> c >>d; // prendo 4 elementi da cin (ne restano n-4)
		//PRE_while: n>=4, i=0, quad=0 quadruple in (0...-4) e cin contiene (n-4) elementi
		while (i<n-4) { //R_while= (i<n) && quad=(numero quadruple in (0...i-1)) && cin contiene (n-4-i) elementi
			if (a==b+c+d) { //uguaglianza verificata --> incrementa di 4
				quad=quad+1;
				i=i+4;
				cin >> a >> b >> c >> d;
			} else { //uguaglianza non verificata --> scambia e incrementa di 1
				a=b;
				b=c;
				c=d;
				cin >> d;
				i=i+1;
			}
		}
		//POST_while: quad=(numero di quadruple in (0...n-1)) 
        cout << "trovate " << quad << " quadruple" <<endl; 	
	} else { //se n<=3
		cout << "non ci sono abbastanza numeri" << endl;
	}			
	cout << "end" << endl;
}

//POST: se n<=3, scrive "non ci sono abbastanza numeri", altrimenti scrive quante quadruple ho tra i miei n numeri.

// R_while: (i<=n-4) && quad=(numero quadruple in (0...i-1))

// PRE_while -> R_while: n>=4 && i=0 && quad=0 && cin contiene (n-4) elementi-> i<=n-4 && quad=0 && cin contiene (n-4-0) elementi 
//                      -> i<=n-4 && quad=(numero quadruple in (0...i-1)) && cin contiene (n-4-i) elementi

// R_while && condperm -> R_while: ((i<=n-4) && quad=(numero quadruple in (0...i-1)) && cin contiene (n-4-i) elementi)&& (i<n-4) ->
// -> (i<n-4) && quad=(numero quadruple in (0...i-1)) && cin contiene (n-4-i) elementi
// <C>
// 2 casi:
//      - Se l'uguaglianza a=b+c+d viene rispettata allora incremento quad di 1 -> quad=(numero quadruple in (0...i+3)) e cin contiene (n-4-(i+4)) elementi
//        Incremento i di 4 -> i<n, quad=(numero quadruple(0...i-1)) e cin contiene (n-4-i) elementi -> R_while valida
//      
//      - Se l'uguaglianza non e' verificata, allora eseguo gli scambi e prendo da cin un elemento solo ->
//        -> cin contiene (n-4-(i-1)) elementi). Incremento i di 1 -> i< n-3 < n  e cin contiene (n-4-i) elementi) -> R_while valida


// R_while && !condperm -> POST_while: ((i<n) && (quad=(numero quadruple in (0...i-1))) && (cin contiene (n-4-i) elementi)) && !(i<n-4) ->
// -> ((i<n) && (quad=(numero quadruple in (0...i-1))) && (cin contiene (n-4-i) elementi)) && (i>=n-4) ->
// -> ((n-4<=i<n) && (quad=(numero quadruple in (0...i-1))) && (cin contiene (n-4-i) elementi))
// (n-4<=i<n) comporta che ci sono meno di 4 elementi in cin, e quindi non ci sono piu' quadruple da poter esaminare ->
// -> (quad=(numero quadruple in (0...i-1)), dove n-i<4 -> (quad=(numero quadruple in (0...n-1)) -> POST_while
