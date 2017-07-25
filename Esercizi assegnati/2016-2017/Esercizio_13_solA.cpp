// soluzione di B.Cosentino
#include<iostream>
using namespace std;
//PRE: cin contiene un intero n e n caratteri
int main() {
	
	int n;
	cin >> n;
	char P[n];
	//PRE_for1: P e' vuoto  
	for (int i=0; i<n; i=i+1) { //R_for1: 0<=i<=n && letti caratteri in P[0...i-1]
		cin>> P[i];
	} 
	//POST_for1: letti n caratteri in cin e messi in P
	
	bool palindroma=true;
	//PRE_for2: (i=0, confrontati [0,-1] e [0,-1] [nessun confronto])
	for (int i=0; i<n-i-1 && palindroma; i=i+1) { //R_for2: (0<=i<=n-i-1) && (palindroma=true <=> [0...i-1]=[n-i...n-1]) && (confrontati da [0...i-1] e [n-i...n-1])
		if (P[i]!=P[n-i-1]) {
			palindroma=false;
		}
	}
	//POST_for2: palindroma=true <=> la parola e' palindroma
	
	if (palindroma)	{
		cout << "La sequenza e' palindroma"<<endl;
	} else { 
		cout << "La sequenza non e' palindroma" <<endl;
	}
	
	cout << "end" <<endl;
}			
//POST: verifica se la sequenza e' palindroma

// for1 banale

// for2
// PRE_for2 -> R_for2: i=0 && P[0,-1]==P[n,n-1]=insieme vuoto-> R valida
 
// R_for2 && condperm -> R_for2:  (0<=i<=n-i-1) && (palindroma=true <=> [0...i-1]=[n-i...n-1]) && (confrontati da [0...i-1] e [n-i...n-1]) &&
// && (i<n-i-1 && palindroma) -> (0<=i<n-i-1) && ([0...i-1]=[n-i...n-1]) && (confrontati da [0...i-1] e [n-i...n-1])
// <C>
// Eseguo il confronto P[i]==P[n-i-1]. Se il risultato e' positivo allora non faccio niente, altrimenti pongo palindroma = false.
// In ogni caso, (palindroma=true <=> [0...n-i]=[n-i+1...n-1]) e (confrontati da [0...i] e [n-i+1...n-1]) . 
// Infine, i=i+1 -> (0<=i<=n-i-1) && (palindroma=true <=> [0...i-1]=[n-i...n-1]) && (confrontati da [0...i-1] e [n-i...n-1]) -> R_for2 valida

// R_for2 && !condperm -> POST_for2: (0<=i<=n-i-1) && (palindroma=true <=> [0...i-1]=[n-i...n-1]) && (confrontati da [0...i-1] e [n-i...n-1]) &&
// && !(i<n-i-1 && palindroma) 
// -> ((0<=i<=n-i-1) && (palindroma=true <=> [0...i-1]=[n-i...n-1]) && (confrontati da [0...i-1] e [n-i...n-1])) && (i>=n-i-1 || !palindroma) 
// -> ((0<=i<=n-i-1) && (palindroma=true <=> [0...i-1]=[n-i...n-1]) && (confrontati da [0...i-1] e [n-i...n-1]) && (i>=n-i-1)) ||
//    || ((0<=i<=n-i-1) && (palindroma=true <=> [0...n-i-1]=[n-i...n-1]) && (confrontati da [0...i-1] e [n-i...n-1]) && !palindroma) ->
//  -> 2 CASI: ~ (i=n-i-1) && (palindroma=true <=> [0...i-1]=[n-i...n-1]) && (confrontati da [0...i-1] e [n-i...n-1]) ->
//               -> (2i=n-1) && (palindroma=true <=> [0...i-1]=[n-i...n-1]) && (confrontati da [0...i-1] e [n-i...n-1]) ->
//               -> (i=(n-1)/2, se n dispari) || (i=n/2, se n pari).
//               n dispari -> (palindroma=true <=> [0...((n-1)/2)-1]=[(n-1)/2)+1...n-1]) && (confrontati da [0...(n-1)/2)-1] e [(n-1)/2)+1...n-1]) ->
//               -> POST_for2 valida
//               n pari ->  (palindroma=true <=> [0...n/2-1]=[n/2+1...n-1]) && (confrontati da [0...n/2-1] e [n/2+1...n-1]) -> POST_for2 valida
//             ~ (palindroma==false) && (palindroma=true <=> [0...i-1]=[n-i...n-1]) && (confrontati da [0...i-1] e [n-i...n-1]) ->
//               -> [0...i-1]!=[n-i...n-1] -> (l'intera parola non e' palindroma) && (palindroma=false) -> POST_for2
