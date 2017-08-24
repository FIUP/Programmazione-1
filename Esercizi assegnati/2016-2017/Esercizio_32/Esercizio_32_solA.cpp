// soluzione di B.Cosentino
#include<iostream>

using namespace std;

// Prototipi delle funzioni da implementare

// PRE = (a e' un array di dimensione e m,n>0)
void leggiM(float *a, int &m, int &n){
	cin >> m >> n;
	for (int i=0; i<m*n; i=i+1)
		cin >> *(a+i);
}
// POST = (a viene riempito per m righe e n colonne)

// PRE = (a[m][n] e' un array di elementi definiti)
void stampaM(float *a, int m, int n){
    cout << m << "    "<<n<<endl;
	for (int i=0; i<m; i=i+1){
		for (int j=0; j<n; j=j+1)
			cout << *(a+i*n+j) << "    ";
		cout << endl;
	}
}
// POST = (a viene stampato per righe)

// PRE = (m1,n1,m2,n2>0 e sono dimensioni di due matrici)
bool controllo_somma(int m1, int n1, int m2, int n2) {

	return (m1==m2 && n1==n2);
}
// POST = (restituisce true sse m1==m2 e n1==n2)

// PRE = (a, b e c sono matrici m x n e m,n>0)
void somma(float *a, float *b, float *c, int m, int n){

	for (int i=0; i<m*n; i=i+1)
		*(c+i)=*(a+i)+*(b+i);

}
// POST = (somma le matrici a e b e salva il risultato in c (c[i][j]=a[i][j]+b[i][j]))

// PRE = (n1,m2>0 e sono dimensioni riga di una matrice e colonna dell'altra matrice )
bool controllo_prodotto(int m1, int n1, int m2, int n2){
	return n1==m2;
}
// POST = (restituisce true sse n1==m2)

// PRE = (a e b sono matrici definite rispettivamente di dimensioni m x n e n x p) & (c e' una matrice m x p)
void prodotto(float *a, float *b, float *c, int m, int n, int p){
    
    // PRE1 = (a e b sono matrici definite rispettivamente di dimensioni m x n e n x p) & (c e' una matrice m x p) & (non ho eseguito prodotti riga per colonna)
	for (int i=0; i<m; i=i+1){
    // R1 = (0<=i<=m) & (ho eseguito il prodotto riga per colonna tra le righe [0...i-1] di a e tutte le colonne di b e l'ho salvato nelle rispettive righe di c)
        
        // PRE2 = (a e b sono matrici definite rispettivamente di dimensioni m x n e n x p) & (c e' una matrice m x p) & (ho eseguito i prodotti riga per colonna delle prime i-1 righe)
		for (int j=0; j<p; j=j+1){
		//R2 = (0<=j<=p) & (ho eseguito il prodotto riga per colonna tra la riga i e le colonne [0...j-1] di b e l'ho salvato nella rispettiva posizione della riga i di c)
			*(c+i*p+j)=0;
			
			// PRE3 = (a e b sono matrici definite rispettivamente di dimensioni m x n e n x p) & (c e' una matrice m x p) & (c[i][j]=0)
			for (int r=0; r<n; r=r+1)
			// R3 = (0<=r<=n) & (ho moltiplicato ogni elemento della riga i in [0...r-1] di a con il rispettivo elemento della colonna j in [0...r-1] e sommato gli r prodotti ottenuti e l'ho salvato in c[i][j])
				*(c+i*p+j)= *(c+i*p+j) + (*(a+i*n+r))*(*(b+r*p+j));
            // POST3 = (ho moltiplicato ogni elemento della riga i di a con il rispettivo elemento della colonna j di b e sommato gli n prodotti ottenuti e l'ho salvato in c[i][j]) 
		
		}
		// POST2 = (ho eseguito il prodotto riga per colonna tra la riga i di a e tutte le colonne di b e l'ho salvato nella rispettiva posizione della riga i di c)
	}
	// POST1 = (ho eseguito il prodotto riga per colonna tra tutte le righe di a e tutte le colonne di b e l'ho salvato nelle rispettive righe di c)
}

// POST = (esegue il prodotto (riga per colonna) tra le matrici a e b e lo salva in c (c[i][j]=sommatoria(r=0 -> n-1, a[i][r]*b[r][j])))


// PRE1->R1 : (a e b sono matrici definite rispettivamente di dimensioni m x n e n x p) & (c e' una matrice m x p) & (non ho eseguito prodotti riga per colonna) -> 
//              -> (ho eseguito il prodotto riga per colonna tra le righe [0...-1] di a e tutte le colonne di b e l'ho salvato nelle rispettive righe di c) -> 
//              -> (ho eseguito il prodotto riga per colonna tra le righe [0...j-1] di a e tutte le colonne di b e l'ho salvato nelle rispettive righe di c) & (j=0) -> R1 valida
 
// R1 & B <C> R1 : (0<=i<=m) & (ho eseguito il prodotto riga per colonna tra le righe [0...i-1] di a e tutte le colonne di b e l'ho salvato nelle rispettive righe di c) & (i<m) ->
//              -> (0<=i<m) & (ho eseguito il prodotto riga per colonna tra le righe [0...i-1] di a e tutte le colonne di b e l'ho salvato nelle rispettive righe di c)
//              <C>
//              Alla fine del ciclo for_2 vale POST2, ovvero 
//              (ho eseguito il prodotto riga per colonna tra la riga i di a e tutte le colonne di b e l'ho salvato nella rispettiva posizione della riga i di c).
//              Quindi, vale che (ho eseguito il prodotto riga per colonna tra le righe [0...i] di a e tutte le colonne di b e l'ho salvato nelle rispettive righe di c).
//              Infine, viene incrementato i -> R1 valida

// R1 & !B -> POST1 : (0<=i<=m) & (ho eseguito il prodotto riga per colonna tra le righe [0...i-1] di a e tutte le colonne di b e l'ho salvato nelle rispettive righe di c) & (i>=m) ->
//                  -> (i=m) & (ho eseguito il prodotto riga per colonna tra le righe [0...i-1] di a e tutte le colonne di b e l'ho salvato nelle rispettive righe di c) ->
//                  ->(ho eseguito il prodotto riga per colonna tra le righe [0...m-1] di a e tutte le colonne di b e l'ho salvato nelle rispettive righe di c) -> 
//                  -> (ho eseguito il prodotto riga per colonna tra tutte le righe di a e tutte le colonne di b e l'ho salvato nelle rispettive righe di c) -> POST1 verificata


// PRE2 -> R2 : (a e b sono matrici definite rispettivamente di dimensioni m x n e n x p) & (c e' una matrice m x p) & (ho eseguito i prodotti riga per colonna delle prime i-1 righe e l'ho salvato nella rispettiva posizione della riga i di c) ->
//          -> (ho eseguito i prodotti riga per colonna tra la riga i e le colonne [0...-1]  di b e l'ho salvato nella rispettiva posizione della riga i di c) -> 
//          -> (ho eseguito i prodotti riga per colonna tra la riga i e le colonne [0...j-1] di b e l'ho salvato nella rispettiva posizione della riga i di c) & (j=0) -> R2 valida

// R2 & B <C> R2 :  (0<=j<=p) & (ho eseguito il prodotto riga per colonna tra la riga i e le colonne [0...j-1] di b e l'ho salvato nella rispettiva posizione della riga i di c) & (j<p ) -> 
//              -> (0<=j<p) & (ho eseguito il prodotto riga per colonna tra la riga i e le colonne [0...j-1] di b e l'ho salvato nella rispettiva posizione della riga i di c)
//              <C>
//              c[i][j] viene impostato a 0.
//              Alla fine del ciclo for_3 vale POST3, ovvero 
//              (ho moltiplicato ogni elemento della riga i di a con il rispettivo elemento della colonna j di b e sommato gli n prodotti ottenuti e l'ho salvato in c[i][j]).
//              Quindi, vale che 
//              (ho eseguito il prodotto riga per colonna tra la riga i e le colonne [0...j] di b e l'ho salvato nella rispettiva posizione della riga i di c).
//              Infine, j viene incrementato -> R2 valida

// R2 & !B -> POST2 : (0<=j<=p) & (ho eseguito il prodotto riga per colonna tra la riga i e le colonne [0...j-1] di b e l'ho salvato nella rispettiva posizione della riga i di c) & (j>=p) -> 
//                  -> (j=p) & (ho eseguito il prodotto riga per colonna tra la riga i e le colonne [0...j-1] di b e l'ho salvato nella rispettiva posizione della riga i di c) -> 
//                  -> (ho eseguito il prodotto riga per colonna tra la riga i e le colonne [0...p-1] di b e l'ho salvato nella rispettiva posizione della riga i di c) ->
//                  -> (ho eseguito il prodotto riga per colonna tra la riga i di a e tutte le colonne di b e l'ho salvato nella rispettiva posizione della riga i di c) -> POST2 verificata


// PRE3 -> R3 : (a e b sono matrici definite rispettivamente di dimensioni m x n e n x p) & (c e' una matrice m x p) & (c[i][j]=0) ->
//          -> (ho moltiplicato ogni elemento della riga i in [0...-1] di a con il rispettivo elemento della colonna j in [0...-1] e sommato gli r prodotti ottenuti e l'ho salvato in c[i][j]) ->
//          -> (r=0) & (ho moltiplicato ogni elemento della riga i in [0...r-1] di a con il rispettivo elemento della colonna j in [0...r-1] e sommato gli r prodotti ottenuti e l'ho salvato in c[i][j]) -> R3 valida

// R3 & B <C> R3 : (0<=r<=n) & (ho moltiplicato ogni elemento della riga i in [0...r-1] di a con il rispettivo elemento della colonna j in [0...r-1] e sommato gli r prodotti ottenuti e l'ho salvato in c[i][j]) & (r<n) ->
//              -> (0<=r<n) & (ho moltiplicato ogni elemento della riga i in [0...r-1] di a con il rispettivo elemento della colonna j in [0...r-1] e sommato gli r prodotti ottenuti e l'ho salvato in c[i][j])
//              <C>
//              Viene effettuato il prodotto tra a[i][r] e b[r][j] e sommato a c[i][j]. 
//              Quindi, vale che (ho moltiplicato ogni elemento della riga i in [0...r] di a con il rispettivo elemento della colonna j in [0...r] e sommato gli r prodotti ottenuti e l'ho salvato in c[i][j]).
//              Infine, r viene incrementato -> R3 valida

// R3 & !B -> POST3 : (0<=r<=n) & (ho moltiplicato ogni elemento della riga i in [0...r-1] di a con il rispettivo elemento della colonna j in [0...r-1] e sommato gli r prodotti ottenuti e l'ho salvato in c[i][j]) & (r>=n) ->
//                  -> (r=n) & (ho moltiplicato ogni elemento della riga i in [0...r-1] di a con il rispettivo elemento della colonna j in [0...r-1] e sommato gli r prodotti ottenuti e l'ho salvato in c[i][j]) -> 
//                  -> (ho moltiplicato ogni elemento della riga i in [0...r-1] di a con il rispettivo elemento della colonna j in [0...n-1] e sommato gli r prodotti ottenuti e l'ho salvato in c[i][j]) ->
//                  -> (ho moltiplicato ogni elemento della riga i di a con il rispettivo elemento della colonna j di b e sommato gli n prodotti ottenuti e l'ho salvato in c[i][j]) -> POST3 verificata


// PRE = (a e' una matrice definita m x n e b e' una matrice n x m)
void trasponi(float* a, float *b, int m, int n){
	
	for (int i=0; i<m; i=i+1){
		for (int j=0; j<n; j=j+1)
			*(b+j*m+i) = *(a+i*n+j);
	}
	
	stampaM(b, n, m);
}
// POST = (esegue la trasposizione di a e la salva in b (b[j][i]=a[i][j]). Poi stampa b)



int main() {
    float a[100], b[100], c[100];   // array con i dati
    int ma, na, mb, nb, mc, nc;     // dimensioni delle tre matrici
    char operazione;                // operazione da eseguire
    
    leggiM(a, ma, na);
    cin >> operazione;
        
    cout << "start" << endl;
    
    if (operazione == 't'){
    	trasponi(a,c,ma,na);
    } else{
    	leggiM(b,mb,nb);
    	if (operazione == '+'){
    		if (controllo_somma(ma,na,mb,nb)){
    			mc=ma;
    			nc=na;
    			somma(a,b,c,ma,na);
    			stampaM(c,mc,nc);
    		} else {
    			cout << "dimensioni non corrette" << endl;
    		}
    	}
    	if (operazione == '*'){
    		if (controllo_prodotto(ma,na,mb,nb)){
    			mc=ma;
    			nc=nb;
    			prodotto(a,b,c,ma,na,nb);
    			stampaM(c,mc,nc);
    		} else { 
    			cout << "dimensioni non corrette" << endl;
    		}
		}
	}
    cout << "end" << endl;
}
