// soluzione di B.Cosentino
#include<iostream>
using namespace std;

//PRE: cin contiene 25 interi 
int main() {
	int C[5][5];
  	bool B[5][5];
  	// PRE_for1: cin contiene 25 interi && C[0...4][0...4] vuoto
  	for(int i=0; i<5; i=i+1){   //R_for1: C[0...i-1][0...4] pieno && C[i...4][0...4] vuoto && (0<=i<=5)
  	    
  	    //PRE_for2: C[0...i-1][0...4] pieno && C[i...4][0...4] vuoto && i intero fissato
    	for(int j=0; j<5; j=j+1){   //R_for2: C[0...i][0...j-1] pieno && C[i...4][j...4] vuoto && (0<=j<=5) 
    		cin>>C[i][j];
    	}
    	//POST_for2:C[0...i][0...4] pieno
    }
    //POST_for1: C[0...4][0...4] pieno
    
    
    //PRE_for3: B[0...4][0...4] vuoto
    for (int i=0; i<5; i=i+1) { //R_for3: B[0...i-1][0...4] pieno && B[i...4][0...4] vuoto && (0<=i<=5)
    	
    	//PRE_for4: B[0...i-1][0...4] pieno && B[i...4][0...4] vuoto && i intero fissato
    	for (int j=0; j<5; j=j+1) { //R_for4: B[0...i][0...j-1] pieno && B[i...4][j...4] vuoto && (0<=j<=5)
    		bool ver=true;
    		//PRE_for5: ver=true && B[0...i][0...j-1] pieno && i e j interi fissati
    		for (int x=0; x<5 && ver; x=x+1) {  //R_for5: (0<=x<=5) && (ver=true <=> C[i][0...x-1]==C[0...x-1][j]) 
    			if (C[i][x]!=C[x][j]) {
    				ver=false;
    			}
    		}
    		//POST_for5: (ver=true <=> C[i][0...4]==C[0...4][j]) 
    		
    		B[i][j]=ver;
    	}
    	//POST_for4: B[0...i][0...4] pieno
    }
    //POST_for3: B[0...4][0...4] pieno
	
	
	for(int i=0; i<5; i=i+1){ 
	    cout<<"riga="<<i<<':';
    	for(int j=0; j<5; j=j+1){
    		cout<<B[i][j]<<' ';
    	}  
    	cout<<endl;
   } 
	cout<<"end"<<endl;     
}
//POST: stampa una matrice booleana B che con valori di verita' dipendenti dalle righe e dalle colonne di C
