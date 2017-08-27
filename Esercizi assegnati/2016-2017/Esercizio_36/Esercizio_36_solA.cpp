// soluzione di B.Cosentino
#include<iostream>
using namespace std;
// PRE = (alla funzione vengono passati l'array dei dati di gara, il numero di righe dei dati di gara e l'ID di un corridore)
int conta(int P[][5], int righe, int cor){
    int k=0;
    for (int i=0; i<righe; i=i+1){
        if (P[i][1]==cor)
            k=k+1;
    }
    return k;
}
// POST = (restituisce k=il numero di volte che il partecipante cor e' passato da un sensore)

// PRE = (alla funzione vengono passati un'array O non definito, l'array dei dati di gara, l'ID di un corridore, un numero di sensore e il numero di righe dei dati di gara)
void preleva_dati(int O[], int P[][5], int cor, int sens, int righe){
    
    bool trov=false;
    for (int i=0; i<righe && !trov; i=i+1){
        if (P[i][0]==sens && P[i][1]==cor){
            O[0]=P[i][2]; 
            O[1]=P[i][3]; 
            O[2]=P[i][4];
            trov=true;
        }
    }
}
// POST = (riempie O con l'orario di arrivo del partecipante cor al sensore sens)


// PRE = (alla funzione viene passato un'array di orari O e l'array che contiene le posizioni dei sensori e il loro numero)
bool controlla(int O[][3], float Sens[], int n_sens){
    bool baro=false;
    
    // PRE_for = (O contiene gli orari di arrivo ai sensori) & (Sens contiene la posizione dei sensori) & (n_sens=numero dei sensori) &
    //          & (baro=false) & (non ho trovato tempi minori del previsto) & (i=1)
    for (int i=1; i<n_sens && !baro; i=i+1){
    // R_for = (1<=i<=n_sens) & (baro==true sse ho trovato fino alla coppia di sensori contigui (i-2, i-1) un tempo sospetto)
        float tempo1=O[i-1][0]*3600 + O[i-1][1]*60 + O[i-1][2]; // orario al primo sensore espresso in secondi
        float tempo2=O[i][0]*3600 + O[i][1]*60 + O[i][2];   // orario del secondo sensore espresso in secondi
        
        float interSt=165*(Sens[i]-Sens[i-1]);  // tempo intermedio standard  espresso in secondi
        
        baro=((tempo2-tempo1)<interSt);
    }
    // POST_for = (baro==true sse uno dei tempi intermedi e' minore di quello previsto)
    return baro;
}
// POST = (restituisce true sse uno dei tempi intermedi e' piu' breve del previsto)

//*****************************************
// DIMOSTRAZIONE

// PRE <baro=false> PRE_for: ovvia

// PRE_for -> R_for : (O contiene gli orari di arrivo ai sensori) & (Sens contiene la posizione dei sensori) & (n_sens=numero dei sensori) &
//                  & (baro=false) & (non ho trovato tempi minori del previsto) & (i=1) -> 
//                  -> (1<=i<=n_sens) & (baro==false) & (ho trovato fino alla coppia di sensori contigui (-1, 0) un tempo sospetto) -> 
//                  -> R_for valida

// R_for & B <C> R_for : (1<=i<=n_sens) & (baro==true sse ho trovato fino alla coppia di sensori contigui (i-2, i-1) un tempo sospetto) & (i<n_sens) & (baro==false) -> 
//                      -> (1<=i<n_sens) & (non ho trovato fino alla coppia di sensori contigui (i-2, i-1) un tempo sospetto)
//                      <C>
//                      tempo1 contiene l'orario di partenza dal sensore i-1 (espresso in secondi)
//                      tempo2 contiene l'orario di arrivo al sensore i
//                      interSt contiene il tempo minimo legale tra il sensore i-1 e il sensore i
//                      baro=((tempo2-tempo1)<interSt); ovvero controlla se il tempo tra il sensore i-1 e il sensore i sia legale
//                      1) se il tempo e' legale, allora baro=false -> (non ho trovato fino alla coppia di sensori contigui (i-1, i) un tempo sospetto)
//                      Infine i=i+1; -> (1<=i<=n_sens) & (baro==false) & (non ho trovato fino alla coppia di sensori contigui (i-2, i-1) un tempo sospetto) ->
//                      -> R_for valida
//                      2) se il tempo non e' legale, allora baro=true -> (ho trovato fino alla coppia di sensori contigui (i-1, i) un tempo sospetto)
//                      Infine i=i+1; -> (1<=i<=n_sens) & (baro==true) & (ho trovato fino alla coppia di sensori contigui (i-2, i-1) un tempo sospetto) ->
//                      -> R_for valida

// R_for & !B -> POST_for : (1<=i<=n_sens) & (baro==true sse ho trovato fino alla coppia di sensori contigui (i-2, i-1) un tempo sospetto) & ((i>=n_sens) || (baro==true)) ->
//                      -> 2 casi:
//                      1) (1<=i<=n_sens) & (baro==true sse ho trovato fino alla coppia di sensori contigui (i-2,i-1) un tempo sospetto) & (i>=n_sens) & (baro==false) ->
//                      -> (i=n_sens) & (baro==true sse ho trovato fino alla coppia di sensori contigui (n_sens-2, n_sens-1) un tempo sospetto) & (baro==false) -> 
//                      -> (baro==false) & (non ho trovato fino alla coppia di sensori contigui (n_sens-2, n_sens-1) un tempo sospetto) -> 
//                      -> (baro==false) & (tutti i tempi intermedi sono maggiori del previsto) -> 
//                      -> (baro==true sse uno dei tempi intermedi e' minore di quello previsto) -> POST_for verificata
//                      2) (1<=i<=n_sens) & (baro==true sse ho trovato fino alla coppia di sensori contigui (i-2,i-1) un tempo sospetto) & (i<n_sens) & (baro==true) ->
//                      -> (1<=i<n_sens) & (ho trovato fino alla coppia di sensori contigui (i-2,i-1) un tempo sospetto) & (baro==true) ->
//                      -> (uno dei tempi intermedi e' minore di quello previsto) & (baro=true) ->
//                      -> (baro==true sse uno dei tempi intermedi e' minore di quello previsto) -> POST_for verificata

// POST_for <return baro> POST: ovvia
//*****************************************



// PRE =(cin contiene il numero di sensori, la loro posizione, il numero dei partecipanti, l'orario di inizio e i dati della gara(sensore, ID, orario))
int main() {
	cout << "start" << endl;
    
    int n_sens;
    float Sens[10];
    
    cin >> n_sens;
    Sens[0]=0; Sens[n_sens-1]=42.195;
    
    for (int i=1; i<n_sens-1; i=i+1){
        cin >> Sens[i];
    }
    
	int n_part, oraI, minI, secI, p=0;
	cin >> n_part >> oraI >> minI >> secI;
	
	int P[100][5];
	
	bool fine=false;
	
	int s;
	while (!fine){
		
		cin >> s;
		if (s!=-1){
            P[p][0]=s;
            cin >> P[p][1] >> P[p][2] >> P[p][3] >> P[p][4];
            p=p+1;
		} else {
		    fine = true;
		}
	}
	
	bool regolare=true;
	
	for (int i=0; i<n_part; i=i+1){
        if (conta(P,p,i)!=n_sens){
            regolare=false;
            cout << i << ": salto sensore"<< endl;
        } else {
            int X[n_sens][3];
            for (int j=0; j<n_sens; j=j+1){
                preleva_dati(X[j],P,i,j,p);
            }
            if (controlla(X,Sens,n_sens)){
                regolare=false;
                cout << i << ": tempo sospetto"<<endl;
            }
        }
	    
	}
    if (regolare) 
        cout << "gara regolare"<<endl;
    
    cout << "end" << endl;
}
// POST = (se regolare==true stampa "gara regolare", altrimenti stampa il numero di gara del sospetto baro e il motivo di tale sospetto)
