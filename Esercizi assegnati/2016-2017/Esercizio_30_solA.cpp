// soluzione di B.Cosentino
#include<iostream>
using namespace std;


void leggiV(int* A, int n_strati, int n_righe, int n_colonne, int N){
    
    bool continua=true;
    
    for (int c=0; c<n_colonne & continua; c=c+1){
        for (int s=0; s<n_strati & continua; s=s+1){
            for (int r=0; r<n_righe & continua; r=r+1){
                cin >> A[s*n_righe*n_colonne+r*n_colonne+c];
                if (r*c*s>=N) continua=false;
            }
        }
    }
}

// PRE = (A viene vista come Y[lim1][lim2][lim3] e riempito per V-fette con M valori, dove M=min(lim1*lim2*lim3, n_ele))

void stampaS(int *A,int n_strati, int n_righe, int n_colonne, int N){
	
    int ufetta=N/(n_righe*n_strati); // numero di fette piene e indice della fetta non piena
    int uriga=N%(n_righe*n_strati); // ultima riga piena o con ufetta elementi
    // PRE1 = (A e' riempito per V-fette con min(n_strati*n_righe*n_colonne, N) valori) & (n_strati, n_righe, n_colonne, N>0)
    for (int r=0; r<n_strati*n_righe; r=r+1){
    // R1 = (0<=r<=n_strati*n_righe) & (ho stampato le righe definite di A da 0 a r-1 per strati)
        if (r==uriga)
            ufetta=ufetta-1;
        
        if (ufetta>-1){
            if (r%n_righe==0) 
                cout << "strato:" << r/n_righe <<endl;
            // PRE2 = (ufetta>=0) & (r fissato, ho stampato le prime r-1 righe per strati) & (gli elementi della riga sono definiti da 0 a min(n_colonne-1,ufetta))
            for (int c=0; c<n_colonne && c<ufetta+1; c=c+1)
            // R2= (0<=c<=min(n_colonne,ufetta+1)) & (ho stampato gli elementi della riga r da 0 a c-1)
                cout << *(A+r*n_colonne+c) << " ";
            // POST2 = (ho stampato gli elementi della riga r da 0 a min(n_colonne-1,ufetta), ovvero quelli definiti)
            cout << endl;
        }
    }
    // POST1 = (stampa per riga tutte e solo le righe definite di A per strati)
}
// POST=(stampa per riga gli elementi definiti di ciascuno strato di Y, non stampa nulla se lo strato non ha elementi definiti)

// PRE1 -> R1 : (A e' riempito per V-fette con min(n_strati*n_righe*n_colonne, N) valori) & (n_strati, n_righe, n_colonne, N>0) & (non ho stampato alcuna riga di A) ->
//          -> (ho stampato le righe definite di A da 0 a -1 per strati) & (r=0) -> R1 valida

// R1 & B <C> R1 : (0<=r<=n_strati*n_righe) & (ho stampato le righe definite di A da 0 a r-1 per strati) & (r<n_strati*n_righe) ->
//              -> (0<=r<n_strati*n_righe) & (ho stampato le righe definite di A da 0 a r-1 per strati) -> R1 valida
//              <C>
//              Se r e' l'ultima riga completa allora le prossime avranno ufetta-1 elementi.
//              Se ufetta e' ancora un indice valido, allora eseguo la stampa di "strato: (numero strato)"
//              Alla fine del ciclo for_2 vale POST2, ovvero (ho stampato gli elementi della riga r da 0 a min(n_colonne-1,ufetta), ovvero quelli definiti).
//              Quindi, vale che (ho stampato le righe definite di A da 0 a r per strati).
//              Infine, viene incrementato r -> R1 valida

// R1 & !B -> POST1 : (0<=r<=n_strati*n_righe) & (ho stampato le righe definite di A da 0 a r-1 per strati) & (r>=n_strati*n_righe) ->
//                  -> (r=n_strati*n_righe) & (ho stampato le righe definite di A da 0 a r-1 per strati) ->
//                  -> (ho stampato tutte e solo le righe definite di A per strati) -> POST1 verificata

// PRE2 -> R2 : (ufetta>=0) & (r fissato, ho stampato le prime r-1 righe per strati) & (gli elementi della riga sono definiti da 0 a min(n_colonne-1,ufetta)) & (non ho stampato elementi della riga r) ->
//          -> (ho stampato gli elementi della riga r da 0 a -1) & (r=0) -> R2 valida

// R2 & B <C> R2 : (0<=c<=min(n_colonne,ufetta+1)) & (ho stampato gli elementi della riga r da 0 a c-1) & (c<n_colonne && c<ufetta+1) -> 
//              -> (0<=c<=min(n_colonne,ufetta+1)) & (ho stampato gli elementi della riga r da 0 a c-1) & (c<min(n_colonne,ufetta+1)) ->
//              -> (0<=c<min(n_colonne,ufetta+1)) & (ho stampato gli elementi della riga r da 0 a c-1)
//              <C>
//              Stampo l'elemento di indice c della riga. Quindi, vale (ho stampato gli elementi della riga r da 0 a c).
//              Infine, c viene incrementato -> R2 valida


// R2 & !B -> POST2 : (0<=c<=min(n_colonne,ufetta+1)) & (ho stampato gli elementi della riga r da 0 a c-1) & (c>=n_colonne || c>=ufetta+1) ->
//                  -> (0<=c<=min(n_colonne,ufetta+1)) & (ho stampato gli elementi della riga r da 0 a c-1) & (c>=min(n_colonne,ufetta+1)) ->
//                  -> (c=min(n_colonne,ufetta+1)) & (ho stampato gli elementi della riga r da 0 a min(n_colonne,ufetta+1)-1) ->
//                  -> (ho stampato gli elementi della riga r da 0 a min(n_colonne-1,ufetta), ovvero quelli definiti) -> POST2 verificata




main()
{
	int X[400];
	
	for(int i=0; i<400; i=i+1)
		X[i]=-1;
	
	int lim1,lim2,lim3,n_ele;
	cin >> lim1 >>lim2>>lim3 >>n_ele;
	
	leggiV(X,lim1,lim2,lim3,n_ele);
	
	cout<<"start"<<endl;
	
	stampaS(X,lim1,lim2,lim3,n_ele);
	
	cout<<"end"<<endl;

}
