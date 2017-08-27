// soluzione di B.Cosentino
#include<iostream>

using namespace std;

// PRE = (a e b sono array definiti)
void scambioM(float *a, float *b, int &ma, int &na, int mb, int nb){
    ma=mb;
    na=nb;
    
    for (int i=0; i<ma*na; i=i+1)
        *(a+i)=*(b+i);
}
// POST = (copio tutti gli elementi di b in a)

// PRE = (a e' un carattere)
bool controllo_op(char a){
    return (a=='t' || a=='+' || a=='*' || a=='q');    
}
// POST = (restituisce true sse a e' un'operazione definita, ovvero sse a=t o a=+ o a=* o a='q')

// PRE = (a e' un array di dimensione m*n e m,n>0)
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
void somma(float *a, float *b, int m, int n){

	for (int i=0; i<m*n; i=i+1)
		*(a+i)=*(a+i)+*(b+i);

}
// POST = (somma le matrici a e b e salva il risultato in c (c[i][j]=a[i][j]+b[i][j]))


// PRE = (a e b sono matrici definite rispettivamente di dimensioni m x n e n x p) & (c e' una matrice m x p)
void prodotto(float *a, float *b, float *c, int m, int n, int p){

	for (int i=0; i<m; i=i+1){
		for (int j=0; j<p; j=j+1){
			*(c+i*p+j)=0;
			for (int r=0; r<n; r=r+1)
				*(c+i*p+j)= *(c+i*p+j) + (*(a+i*n+r))*(*(b+r*p+j));
		}
	}
}
// POST = (esegue il prodotto (riga per colonna) tra le matrici a e b e lo salva in c (c[i][j]=sommatoria(r=0 -> n-1, a[i][r]*b[r][j])))

// PRE = (a e' una matrice definita m x n e b e' una matrice n x m)
void trasponi(float* a, float *b, int m, int n){
	
	for (int i=0; i<m; i=i+1){
		for (int j=0; j<n; j=j+1)
			*(b+j*m+i) = *(a+i*n+j);
	}
	
}
// POST = (esegue la trasposizione di a e la salva in b (b[j][i]=a[i][j]). Poi stampa b)


int main() {
    float a[100], b[100], c[100];   // array con i dati
    int ma, na, mb, nb, mc, nc;     // dimensioni delle tre matrici
    char operazione;                // operazione da eseguire
    bool input_corretto=true;
    
    cout << "start" << endl;
    
    leggiM(a, ma, na);
    cin >> operazione;
    
    input_corretto=controllo_op(operazione);
    
    // PRE = (a e' un array definito per ma righe e na colonne) & (input_corretto==true sse controllo_op(operazione) == true) & (non ho effettuato operazioni)
    while (input_corretto & operazione!='q'){
        // R = (a contiene il risultato delle precedenti operazioni matriciali) & (input_corretto == true sse controllo_op(operazione)==true e i precedenti input erano tutti corretti) 
        
        if (operazione == 't'){ // se operazione = t effettuo la trasposizione
         	mc=na;
        	nc=ma;
        	trasponi(a,c,ma,na);
        	stampaM(c,mc,nc);
        	scambioM(a,c,ma,na,mc,nc);
        } else { // altrimenti devo effettuare un'operazione tra due matrici 
        	leggiM(b,mb,nb);
        	if (operazione == '+'){ // se operazione = + effettuo la somma
        		if (controllo_somma(ma,na,mb,nb)){ // controllo le dimensioni e passo quelle corrette a mc e nc
        			somma(a,b,ma,na);
        			stampaM(a,ma,na);
        		} else { // altrimenti le dimensioni sono sbagliate e l'input e' sbagliato
        			input_corretto=false;
        		}
        	}
        	if (operazione == '*'){ // se operazione = * effettuo il prodotto
        		if (na == mb){ // controllo le dimensioni e passo quelle corrette a mc e nc
        			mc=ma;
        			nc=nb;
        			prodotto(a,b,c,ma,na,nb);
        			stampaM(c,mc,nc);
        			scambioM(a,c,ma,na,mc,nc);
        		} else { // altrimenti le dimensioni sono sbagliate e l'input e' sbagliato
        			input_corretto=false;
        		}
    		}
    	}

    	cin >> operazione;
    	input_corretto=input_corretto && controllo_op(operazione);  // considero tutti gli input precedenti e controllo l'etichetta operazione prima di ripetere il corpo del ciclo
    }
    // POST =  (l'array a contiene la matrice risultato) && (ho svolto operazioni definite tra matrici sse input_corretto==true)
    
    if (!input_corretto)
        cout << "ERRORE: input non corretto"<<endl;
    
    cout << "end" << endl;
  
}


// PRE -> R : (a e' un array definito per ma righe e na colonne) & (input_corretto==true sse controllo_op(operazione) == true) & (non ho effettuato operazioni) -> 
//          -> (input_corretto == true sse controllo_op(operazione) == true e non ho precedenti input) & (non ho effettuato operazioni) & (a e' un array definito per ma righe e na colonne) -> R valida


// R & B <C> R : (a contiene il risultato delle precedenti operazioni matriciali) & 
//               & (input_corretto == true sse controllo_op(operazione)==true e i precedenti input erano tutti corretti) & (input_corretto==true) & (operazione!='q') ->
//              -> (a contiene il risultato delle precedenti operazioni matriciali) & (controllo_op(operazione)==true e i precedenti input erano tutti corretti) & (operazione!='q')
//              <C>
//              # Se l'operazione e' "t" allora pongo mc = na e nc = ma ed effettuo la trasposizione. Infine viene effettuato lo scambio tra a e c ->
//                -> (a contiene il risultato delle precedenti operazioni matriciali) & (i precedenti input erano tutti corretti)
//              # Altrimenti l'operazione scelta coinvolge due matrici. Leggo la seconda e la salvo in b (con le rispettive dimensioni in mb e nb)
//                2 CASI: - Se l'operazione e' "+" e le dimensioni di b sono corrette allora eseguo la somma e la salvo in a -> 
//                          -> (a contiene il risultato delle precedenti operazioni matriciali) & (i precedenti input erano tutti corretti) -> 
//                          -> (a contiene il risultato delle precedenti operazioni matriciali) &
//                              & (input_corretto == true sse controllo_op(operazione)==true e i precedenti input erano tutti corretti)
//                          Altrimenti, gli input sono errati e input corretto viene impostato a false e non viene svolta alcuna operazione -> 
//                          -> (a contiene il risultato delle precedenti operazioni matriciali) &
//                              & (input_corretto == true sse controllo_op(operazione)==true e i precedenti input erano tutti corretti)
//                        - Se l'operazione e' "*" e le dimensioni di b sono corrette allora eseguo il prodotto e lo salvo in c.
//                          Infine eseguo lo scambio tra a e c -> 
//                          -> (a contiene il risultato delle precedenti operazioni matriciali) & (i precedenti input erano tutti corretti) -> 
//                          -> (a contiene il risultato delle precedenti operazioni matriciali) &
//                              & (input_corretto == true sse controllo_op(operazione)==true e i precedenti input erano tutti corretti)
//                          Altrimenti, gli input sono errati e input corretto viene impostato a false e non viene svolta alcuna operazione -> 
//                          -> (a contiene il risultato delle precedenti operazioni matriciali) &
//                              & (input_corretto == true sse controllo_op(operazione)==true e i precedenti input erano tutti corretti)
//              Alla fine dell'operazione, viene prelevato da cin l'etichetta della prossima e viene controllata (controllo_op(operazione)). 
//              Dopo <input_corretto=input_corretto && controllo_op(operazione)> vale che 
//              (input_corretto == true sse controllo_op(operazione)==true e i precedenti input erano tutti corretti) -> R valida

// R & !B -> POST : (a contiene il risultato delle precedenti operazioni matriciali) & 
//                  & (input_corretto == true sse controllo_op(operazione)==true e i precedenti input erano tutti corretti) & 
//                  & ((input_corretto == false) || (operazione=='q')).
//                  2 casi: # (a contiene il risultato delle precedenti operazioni matriciali) & 
//                            & (input_corretto == true sse controllo_op(operazione)==true e i precedenti input erano tutti corretti) & 
//                            & (input_corretto == false) -> (qualche input e' errato) -> (non sono state svolte operazioni definite tra matrici) ->
//                            -> (ho svolto operazioni definite tra matrici sse input_corretto==true)
//                            (a contiene la matrice risultato di operazioni non definite) -> (l'array a contiene la matrice risultato)
//                            Comunque, vale la POST
//                          # (a contiene il risultato delle precedenti operazioni matriciali) & 
//                            & (input_corretto == true sse controllo_op(operazione)==true e i precedenti input erano tutti corretti) & (operazione == q) -> 
//                            -> (a contiene il risultato delle precedenti operazioni matriciali) & (input_corretto == true) ->
//                            -> (l'array a contiene la matrice risultato) && (ho svolto operazioni definite tra matrici sse input_corretto==true) = POST
