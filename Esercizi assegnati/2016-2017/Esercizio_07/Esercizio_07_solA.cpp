// soluzione di B.Cosentino
#include <iostream>
using namespace std;

//PRE: cin contiene un intero positivo>0

int main() {
    
    int n;
    cin >> n;
    
    if (n<=2) {		//Se n<=2, stampa "altezza non valida"
        cout << "altezza non valida" << endl;
    } else {
        //n>=3
        int i=1; 				//PRE righe: n>=3 && i=1   -->  1<=3 && stampate 0 righe. R vera.
        while (i<n) {			//Ciclo delle righe (bisogna arrivare alla riga n-1)   
        						//Invariante righe:(i<=n, stampate i-1 righe)
            int k,j;			//INVARIANZA: Invariante righe && i<n --> i<=n && stampate i-1 righe && i<n -->
            					// --> i<n && i-1 righe. Stampo una riga -> i righe stampate. i=i+1 -> i<=n e stampate i-1 righe.
            					//Invariante righe ancora vera
            
            k=1;				    	//PRE spazi: i<n && k=1 --> 0<n-i && k=1 --> 1=<n-i && 1-1 spazi --> k<=n-i && 0 spazi. 
            					    	//--> Invariante spazi vera.
            while (k<n-i) {
            //Spazi per riga (n-i, dove i e' il numero di riga)
                				    	//Invariante spazi:(k<=n-i, k-1 spazi stampati)
                cout <<' ';		    	//INVARIANZA: Invariante spazi && k<n-i --> k<=n-i && k-1 spazi stampati && k<n-i -->
                k=k+1;			    	// --> k<n-i && k-1 spazi stampati. Stampo uno spazio -> k spazi stampati. k=k+1 -> k<=n-i e stampati k-1 spazi. 
                                        //Invariante spazi è ancora vera
            } 					    	//Invariante spazi && !(k<n-i) --> k<=n-i && k-1 spazi stampati && k>=n-i --> 
            						    // --> k=n-i && n-i-1 spazi stampati
            						    //POST spazi: stampa n-i-1 spazi
            
            j=1;				    	//PRE asterischi: i>=1 && j=1 --> 2i>=2 && j=1--> 2i>1=j && j-1 asterischi stampati --> 
            while  (j<(2*i)) {    		//--> 2i>=j && 0 asterischi stampati --> Invariante asterischi vera.		
            //Asterischi per riga (2i-1)
            	cout <<'*';		    	//Invariante asterischi:(j<=2i, j-1 asterischi)
            	j=j+1;			    	//INVARIANZA: Invariante asterischi && j<2i --> j<=2i && j-1 asterischi stampati && j<2i
            					    	// --> j<2i && j-1 asterischi stampati. Stampo un asterisco -> j asterischi stampati. 
            					    	// j=j+1 -> j<=2i e stampati j-1 asterischi.
            					    	//Invariante asterischi ancora vera
            }						    //Invariante asterischi && !(j<2i) --> j<=2i && j-1 asterischi stampati && j>=2i --> 
            					    	// --> j=2i && 2i-1 asterischi stampati
            						    //POST asterischi: stampa 2i-1 asterischi
            cout << endl;
            i=i+1;
        }
              					 /* Invariante righe & !(i<n): ((i<=n && stampate i righe dell'albero) && !(i<n) --> 
         						 --> i<=n && (stampate i-1 righe dell'albero) && i>=n -->
        						 --> i=n && (stampate n-1 righe dell'albero)  */
        
        						 //POST righe: stampa n-1 righe dell'albero
       
       
        int c;					        //PRE spazi tronco: i<n && c=1 --> 0<n-i && c=1 --> 1=<n-i && 1-1 spazi --> 
        c=1;					        // --> c<=n-i && 0 spazi --> Invariante spazi tronco vera
        while (c<n-1) {     		
        //Spazi prima del tronco (n-2)
            cout << ' ';			    //Invariante spazi tronco: (c<=n-1, c-1 spazi stampati)
            c=c+1;				        //INVARIANZA: Invariante spazi tronco && c<n-1 --> c<=n-1 && c-1 spazi stampati && c<n-1 -->
            					        // --> c<n-1 && c-1 spazi stampati. Stampo uno spazio -> c spazi stampati. c=c+1 -> k<=n-1 e stampati c-1 spazi.
            					        // Invariante spazi è ancora vera
            					        //Invariante spazi && !(c<n-1) --> c<=n-1 && c-1 spazi stampati && c>=n-1 -->
        						        // --> c=n-1 && n-2 spazi stampati
        }						        //POST spazi tronco: stampa n-2 spazi
        cout << "*"<< endl;
    } 

    
    
    cout << "end" << endl;
}

//POST: Il programma stampa n-1 righe con n-i spazi per riga e 2i-1 asterischi per riga (i indice di riga) e il tronco 
