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
    // PRE_for = (righe > 0) & (trov=false) & (P[righe][5] e' definito e ogni riga contiene in ordine [sensore, ID, ora, minuto, secondo]) & (O e' vuoto) &
    //          & (non ho trovato la coppia (sens,cor)) & (i=0)
    for (int i=0; i<righe && !trov; i=i+1){
    // R_for = (0<=i<=righe) & (trov==true sse ho trovato la coppia sensore-ID corretta, ovvero quella (sens,cor) e O contiene l'orario corrispondente alla coppia (sens,cor))
        if (P[i][0]==sens && P[i][1]==cor){ // se trovo la coppia
            O[0]=P[i][2]; O[1]=P[i][3]; O[2]=P[i][4]; // riempio O con l'orario
            trov=true;
        }
    }
    // POST_for = (O contiene l'orario corrispondente alla coppia (sens,cor))
}
// POST = (riempie O con l'orario di arrivo del partecipante cor al sensore sens)

//*****************************************
// DIMOSTRAZIONE

// PRE <trov=false; i=0> PRE_for : ovvia

// PRE_for -> R_for : (righe > 0) & (trov=false) & (P[righe][5] e' definito e ogni riga contiene in ordine [sensore, ID, ora, minuto, secondo]) & (O e' vuoto) &
//                  & (non ho trovato la coppia (sens,cor)) & (i=0) -> 
//                  -> (0<=i<=righe) & !(trov==true) & (non ho trovato la coppia sensore-ID corretta, ovvero quella (sens,cor) 
//                  e O contiene l'orario corrispondente alla coppia (sens,cor), ovvero nessuno) -> R_for valida

// R_for & B <C> R : (0<=i<=righe) & (trov==true sse ho trovato la coppia sensore-ID corretta, ovvero quella (sens,cor)) &
//                  & (O contiene l'orario corrispondente alla coppia (sens,cor)) & (i<righe) & (trov==false) -> 
//                  -> (0<=i<righe) & (non ho trovato la coppia sensore-ID corretta, ovvero quella (sens,cor)) &
//                  & (O e' vuoto) 
//                  <C>
//                  1) se non trovo la coppia (sens, cor) allora non faccio niente -> R_for e' ancora valida
//                  2) se trovo la coppia (sens, cor)
//                      O[0]=P[i][2]; O[1]==P[i][3]; O[2]=P[i][4]; ovvero riempio O con l'orario corrispondente alla coppia (sens,cor)
//                      trov=true; ovvero segnalo che ho trovato la coppia
//                      i=i+1; infine viene incrementato i
//                  -> (0<=i<=righe) & (trov==true) & (ho trovato la coppia (sens,cor)) & (O contiene l'orario corrispondente alla coppia (sens,cor) ) ->
//                  -> (0<=i<=righe) & (trov==true sse ho trovato la coppia sensore-ID corretta, ovvero quella (sens,cor) e
//                  O contiene l'orario corrispondente alla coppia (sens,cor)) = R_for e' valida

// R_for & !B -> POST_for: (0<=i<=righe) & (trov==true sse ho trovato la coppia sensore-ID corretta, ovvero quella (sens,cor)
//                      e O contiene l'orario corrispondente alla coppia (sens,cor)) & ((i>=righe) || (trov==true)) -> 
//                      -> 2 casi:
//                      1) (0<=i<=righe) & (trov==true sse ho trovato la coppia sensore-ID corretta, ovvero quella (sens,cor) 
//                      e O contiene l'orario corrispondente alla coppia (sens,cor)) & (i>=righe) & (trov==false) -> 
//                      -> (i=righe) & (non ho trovato la coppia sensore-ID corretta, ovvero quella (sens,cor)) &
//                      & (O resta vuoto, poiche' l'orario corrispondente alla coppia (sens,cor) non esiste) -> 
//                      -> (O contiene l'orario corrispondente alla coppia (sens,cor), ovvero nessun orario) -> POST_for verificata
//                      2) (0<=i<=righe) & (trov==true sse ho trovato la coppia sensore-ID corretta, ovvero quella (sens,cor) e 
//                      O contiene l'orario corrispondente alla coppia (sens,cor)) & (trov==true) & (i<righe) ->
//                      -> (ho trovato la coppia sensore-ID corretta, ovvero quella (sens,cor)) e O contiene l'orario corrispondente alla coppia (sens,cor)) -> 
//                      -> (O contiene l'orario corrispondente alla coppia (sens,cor)) = POST_for -> POST_for e' verificata                     

// POST_for -> POST

//*****************************************


// PRE = (alla funzione viene passato un'array contenente un orario O)
bool controlla(int O[][3]){

    float tempoI=O[0][0]*3600+O[0][1]*60+O[0][2];
    float tempoM=O[1][0]*3600+O[1][1]*60+O[1][2];
    float tempoT=O[2][0]*3600+O[2][1]*60+O[2][2];
    
    float inter1=tempoM-tempoI;
    float inter2=tempoT-tempoM;
    
    float interSt1=165*11;
    float interSt2=165*10.0975;
    
    return (inter1<interSt1 || inter2<interSt2);
}
// POST = (restituisce true sse uno dei tempi intermedi e' piu' breve del previsto)


// PRE =(cin contiene il numero dei partecipanti, l'orario di inizio e i dati della gara(sensore, ID, orario))
int main() {
	cout << "start" << endl;

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
        if (conta(P,p,i)!=3){
            regolare=false;
            cout << i << ": salto sensore"<< endl;
        } else {
            int X[3][3];
            for (int j=0; j<3; j=j+1){
                preleva_dati(X[j],P,i,j,p);
            }
            if (controlla(X)){
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
