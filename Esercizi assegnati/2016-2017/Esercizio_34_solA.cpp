// soluzione di B.Cosentino
#include<iostream>

using namespace std;

// PRE = (P e' un pattern che termina con '\0' && S e' una sequenza di char che termina con '\0')
bool match(char* P, char* S){
    
    bool OK=true;
    int i = 0;
    // PRE_ciclo = (P e' un pattern che termina con '\0') & (S e' una sequenza di char che termina con '\0') & (OK==true) & (i=0)
    while ( P[i]!='\0' && OK){ // finche' non finisco il pattern e ogni suo carattere in posto i e' uguale al corrispondente carattere di S
    // R_ciclo = (OK == true sse P[0...i-1] occorre in S[0...i-1]) & (0<=i<=lunghezza del pattern)    
    
		if (S[i]=='\0') // se incontro la sentinella in S, allora S e' troppo corto e non puo' contenere P
            OK = false;    

        if (P[i]!='?') // se incontro il carattere jolly non devo controllare che corrisponda a un carattere di S poiche' considero il confronto valido a priori
            OK = OK && (P[i]==S[i]);

        i=i+1;
    }
    // POST_ciclo = (OK==true sse P occorre in S a partire dalla posizione 0)
    return OK;
}
// POST = (la funzione ritorna true se e solo se P occorre in S a partire dalla posizione 0)


// DIMOSTRAZIONE

// PRE < OK=true; i=0 > PRE_ciclo : (P e' un pattern che termina con '\0') & (S e' una sequenza di char che termina con '\0') -> dopo aver eseguito le suddette istruzioni, 
//                                  (P e' un pattern che termina con '\0') & (S e' una sequenza di char che termina con '\0') & (OK==true) & (i=0) = PRE_ciclo


// PRE_ciclo -> R_ciclo : (P e' un pattern che termina con '\0') && (S e' una sequenza di char che termina con '\0') & (OK==true) & (i=0) ->
//          -> (P[0...i-1] occorre in S[0...i-1]) & (OK==true) & (i=0) -> R valida

// R_ciclo & B <C> R_ciclo : (OK == true sse P[0...i-1] occorre in S[0...i-1]) & (0<=i<=lunghezza del pattern) & (P[i]!='\0') & (OK == true) -> 
//                          -> (P[0...i-1] occorre in S[0...i-1]) & (0<=i<lunghezza del pattern) & (OK == true)
//							<C>
//							# Se P[i] == '?', allora P[i] si trova in S, se S e' sufficientemente lungo ->
//							  -> (P[0...i] occorre in S[0...i]) & (0<=i<lunghezza del pattern) & (OK == true)
//							  Infine i viene incrementato -> 
//							  -> (P[0...i-1] occorre in S[0...i-1]) & (0<=i<=lunghezza del pattern) & (OK == true) -> 
//							  -> (OK == true sse P[0...i-1] occorre in S[0...i-1]) & (0<=i<=lunghezza del pattern) = R
//							# Se P[i] != '?', allora OK==true sse P[i] == S[i], se S e' sufficientemente lungo -> 
//							  -> (OK == true sse P[0...i] occorre in S[0...i]) & (0<=i<lunghezza del pattern)
//							  Infine i viene incrementato -> (OK == true sse P[0...i-1] occorre in S[0...i-1]) & (0<=i<=lunghezza del pattern) = R

// R_ciclo & !B -> POST_ciclo -> POST : (OK == true sse P[0...i-1] occorre in S[0...i-1]) & (0<=i<=lunghezza del pattern) & ((P[i]=='\0') || (OK == false)) ->
//                          -> 2 casi:
//                          1) (OK == true sse P[0...i-1] occorre in S[0...i-1]) & (0<=i<=lunghezza del pattern) & (P[i]=='\0')  ->
//                          -> (OK == true sse P[0...i-1] occorre in S[0...i-1]) & (i == lunghezza del pattern) -> 
//                          -> (OK == true sse P occorre in S a partire dalla posizione 0) -> POST_ciclo valida
//                          2) (OK == true sse P[0...i-1] occorre in S[0...i-1]) & (0<=i<=lunghezza del pattern) & (OK == false) -> 
//                          -> (non tutti gli elementi di P[0...i-1] sono uguali ai corrispondenti in S[0...i-1]) & (OK == false)-> 
//                          -> (P non occorre in S a partire da 0) & (OK == false) -> POST_ciclo valida -> POST della funzione match valida




// PRE = (cin contiene un pattern P, seguito un intero n_righe, seguito da un testo T lungo n_righe righe)
int main() {
    char P[100], T[100][100];
    int n_righe = 0;
    
    cin.getline(P, 100);
    cin >> n_righe;
    cin.ignore();       // ignora il carattere "a capo" dopo la lettura del numero di righe 
    for(int i = 0; i < n_righe; i++) {
        cin.getline(T[i],100);
    }
    cout << "start" << endl;
    
    bool esiste=false;
    
    
    for (int r=0; r<n_righe; r=r+1){ // devo effettuare la ricerca per ogni riga
    // R1 = (0<=r<=n_righe) & (ho stampato "riga: r colonna: j" per ogni occorrenza j di P in T[0...r-1])
        bool trov=true;    
        
        int k=0;
        
        while (T[r][k]!='\0'){ // finche' non finisco la riga r di T
        // R2 = (0<=i<=x, dove x e' l'indice di fine riga) & (ho stampato "riga: r colonna: j" per ogni occorrenza j di P in T[r][0...k-1])
            trov=match(P,T[r]+k); // trov == true sse esiste un pattern a partire da i
            esiste=(esiste || trov); // esiste == true sse esiste un pattern in una delle righe precedenti o nella riga corrente fino alla posizione k
            
            if (trov) // se trovo un pattern stampo le coordinate
                cout << "riga: " << r << "   colonna:" << k << endl;
            
            k=k+1; // passo alla posizione successiva
            
        }
        // POST2 = (stampa "riga: r colonna: j" per ogni occorrenza j di P in T[r] se esiste)
        
    }
    // POST1 = (stampa "riga: i colonna: j" per ogni occorrenza i,j di P in T se esiste. Altrimenti esiste==false )
    
    
    if (!esiste) cout << "Pattern non trovato" << endl;
   
    cout << "end" << endl;
}
// POST = (stampa "riga: i colonna: j" per ogni occorrenza i,j di P in T, 
//         oppure "Pattern non trovato" se P non occorre in T)
