//Soluzione di S.Righetto

#include<iostream>
using namespace std;

/* PRE=(T ha almeno dimT elementi definiti e P ne ha dimP) */
int match(int *T,int *P,int dimT,int dimP){

    if(T[0]==P[0] && dimP>0 && dimT>0){
        return 1+match(T+1,P+1,dimT-1,dimP-1);
    }
    else
        return 0;

}
/* POST=(restituisce la lunghezza del più lungo match di P che inizia in T[0]) */

/*  Prova di correttezza
*   1. Nelle condizioni iniziali cerchiamo un match di P[0] in T[0]:
*       - se il match non viene trovato la funzione restituisce 0, che e' la 
*           lunghezza del match piu lungo, che in questo caso e' 0, quindi soddisfa la POST
*   2. Se viene trovato un match, si effettua la chiamata ricorsiva, andando ad analizzare
*   un sottoproblema piu breve. Ora anche qui ci troviamo difronte i due casi:
*       -  match non trovato, e restituisce 0, che con nella fase di ritorno della ricorsione
*           viene sommato a 1, quindi la funzione resituisce 1 che e' infatti la lunghezza del match
*           trovato, la POST e' quindi soddisfatta
*   3. Se il match invece viene trovato, induttivamente abbiamo dimostrato che ritornera la lunghezza
*       del match trovato a partire da 0.
*   La POST viene soddisfatta.
*/


/* PRE=(T ha dimT elementi definiti e P ne ha dimP) */
void F(int *T,int *P,int dimT,int dimP, int &inizio,int &lung){
	int sp=0,lc=0; //scorriP, lungCorrente
	for(int st=0; st<dimT; st++){
		if(T[st] == P[sp]){
			lc = match(T,P,dimT-st,dimP);
			if(!lung || lung < lc){
				lung = lc;
				inizio = st;
			}
		}
	}
	if(!lung){
		inizio = -1;
	}
}
/*
    int x=0; // lunghezza prossimo match
    int k=0; //
    int j=0; //contatore che scorre P (se non trovo un match devo ricominciare da 0)

    lung = match(T,P,dimT,dimP); //prende la prima lunghezza(può essere 0)

    // R=(lung<=i<=dimT)>&&>(si esaminano i match successivi al match piu lungo 
    //  che inizia dall'indice 0)&&(indice inizio di match piu lungo nella parte
    //  di T(i...dimT) )&&(lunghezza di match piu lungo nella parte di T(i...dimT)) 
    for(int i=lung; i<dimT;i++){ //i è il contatore che scorre T da dopo il primo match
        if(T[i]==P[j]){ 
            k++;
            j++;
            if(k > x) 
                x = k;
                inizio = i-x+1;
        }
        else{
            j = 0; //non ho trovato il match ricomincio da capo
            k = 0;
        }
    }
    //fine del ciclo
    
    if(lung>=x && lung!=0) //se la lunghezza trovata è più lunga della attuale
        inizio=0; 
    else 
    	if(lung==0 && x==0) //se lung è vuota (non ho trovato un match)
        	inizio=-1; //non inizio mai
		else
		    lung=x;
}
/* POST=(se c'e un match di P in T di lunghezz maggiore di 0, la funzione 
    restituisce in inizio l'indice di inizio del match piu lungo e in
    lung la sua lunghezza , altrimenti restituisce inizio=-1)
*/




main()
{
    int T[100],P[20];
    int dimT,dimP;

    cin>>dimT>>dimP;

    for(int i=0; i<dimT;i++)
        cin>>T[i];
    for(int i=0; i<dimP;i++)
        cin>>P[i];

    int inizio,lung;
    F(T,P,dimT,dimP,inizio,lung);

    cout<<"start"<<endl;

    if(inizio==-1)
        cout<<"nessun match"<<endl;
    else

    cout<<"il match piu' lungo inizia in "<<inizio<<" ed e' lungo "<<lung<<endl;

  cout<<"end"<<endl;
}

