#include<iostream>
using namespace std;

main(){

    int T[10][5], P[10];
    int dimT, dimP, contaElementi=0;
    bool stop=false;

    //letti 2 interi positivi da cin, indicano numero elementi di T e P
    cin>>dimT>>dimP;

//PRE=(T[10][5] rimpito con valori casuali)
//R=(0<=i<10 e 0<=j<10 && stop è falso, se stop è vero sono stati letti dimT elementi in T[10][5] da cin)
    for(int i=0; i<10 && !stop; i++)
        for(int j=0;j<5 && !stop;j++){
            cin>>T[i][j];
            contaElementi++;
            if(contaElementi==dimT)
                stop=true;
        }
//POST=(T[10][5] contiene dimT valori interi letti da cin)

//PRE=(P[10] riempito con valori casuali)
    for(int p=0;p<dimP;p++)
        cin>>P[p];
//POST=(P[10] contiene dimP valori interi letti da cin)

    int righeIntere=dimT/5;     //numero righe intere
    int resto=dimT%5;           //numero elementi su ultima riga se resto>0

    bool continua;
    int match, colonnaMatch=-1, maxMatch=0;

//PRE(T[10][5] contiene dimT valori, P[10] contiene dimP valori)
    for(int j=0;j<5;j++){//ripetere per 5 colonne R=(0<=j<5)
        int i=0,p=0;//azzero i per scorrere colonne di T e P
        match=0;//numero di match per ogni colonna
//controllare colonne con P[p]
//ripetere per numero di righe intere oppure per righe intere piu 1 se riga finale non è completa
        //R=(0<=i<righeIntere || ((resto>0) && (o<=i<righeintere+1)))
        for(int i=0;i<righeIntere || (resto>0 && i<righeIntere+1);i++){
            int k=0;
			bool ok=true;
			while(k<dimP && ok){		//R2=(ok <=> c'è match tra P[0..k-1] e T[j..j+k-1][i])
				if(T[i+k][j] != P[k])
					ok=false;
				k++;
			}
			//POST2=(ok <=> c'è match tra P[0..dimP-1] e T[j..j+dimP-1][i])
			if(ok)
				match++;
        }
//dopo aver controllato una colonna, controllo se il suo match supera il match massimo che ho in memoria, e memorizzo la colonna j
//in caso di match uguale a 0 per tutte le colonne, colonnaMatch sarà -1 e maxMatch sarà 0
        if(match>maxMatch){
            colonnaMatch=j;
            maxMatch=match;
        }
    }
//POST=(colonnaMatch contiene valore della colonna con più match e maxMatch contiene in numero dei match)

    cout << "la miglior colonna e'  " << colonnaMatch << " con " << maxMatch << " match";
}
