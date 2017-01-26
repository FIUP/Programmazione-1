#include<iostream>
using namespace std;

bool fin(int *x, int i, int *P, int dimP){													//controlliamo effettivamente il match
	if(dimP){																				//se c'è ancora pattern
		if(x[i] != P[0])																	//se l'elemento considerato non coincide con il primo elemento del pattern
			return false;																	//ci fermiamo
		else 																				//altrimenti
			return fin(x, i+1, P+1, dimP-1);												//invochiamo fin, cambiando l'indice di x, quello di P e la dimensione del pattern
	}																						//ora cercheremo un pattern più piccolo finché non lo avremo consumato tutto	
	return true;																			//se lo consumiamo tutto l'abbiamo trovato
}

int match(int* x, int* P, int dim, int dimP, int i, int matchRiga){		                //conta i match
	if(i<dim-dimP+1){																		//se i è una posizione utile
		if(fin(x,i,P,dimP)){																//se c'è match 
			matchRiga++;																	//incrementiamo il contatore che tiene traccia di quanti sono
		}
		int salta = match(x,P,dim,dimP,i+1,matchRiga);											    //i match possono essere sovrapposti, dunque invochiamo di nuovo
	}else{ 																					//quando usciamo dalle posizioni valide
		cout<<matchRiga<<" match trovati"<<endl;
		return matchRiga;
	}
}
/* n_el/lim2 = righe piene && n_el%lim2 = el ultima riga */
void F(int* X, int lim1, int lim2, int* P, int dimP, int riga, int n_el, int& rb, int& bm){
    if(riga<(n_el/lim2)){                                               //Finchè ci sono righe piene
        cout<<"riga n."<<riga<<" ";                                     //Dimmi che riga è
        int bmTemp = match(&X[lim2*riga], P, lim2, dimP, 0, 0);         //Trova match per riga
        if(bmTemp>bm){                                                  //Se match trovati supera bestmatch
            rb = riga;                                                  //Rigabest diventa riga
            bm = bmTemp;                                                //Bestmatch diventa match trovati
        }
        F(X,lim1,lim2,P,dimP,riga+1,n_el,rb,bm);                        //Passa alla prossima riga
    }else if((n_el%lim2)!=0){                                           //Se ci sono elementi all'ultima riga non piena
        cout<<"riga n."<<riga<<" ";                                     //Dimmi che riga è
        int bmTemp = match(&X[lim2*riga], P, n_el%lim2, dimP, 0, 0);    //Trova match solo per gli elementi definiti
        if(bmTemp>bm){                                                  //Se match trovati supera bestmatch
            rb = riga;                                                  //Rigabest diventa riga
            bm = bmTemp;                                                //Bestmatch diventa match trovati
        }
    }
}

void F1(int* X, int lim1, int lim2, int* P, int dimP, int colonna, int n_el, int& cb, int& bm){
    
    if(colonna<lim2 && colonna<n_el%lim2){                                     //colonne con ultima riga di X non completa
        int dimTemp = (n_el/lim2)+1;
        int Temp[dimTemp];
        for(int i=0; i<dimTemp; i++){
            Temp[i]=X[(lim2*i)+colonna];
        }
        cout<<"colonna n."<<colonna<<" ";                               //Dimmi che colonna è
            int bmTemp = match(&Temp[0], P, dimTemp, dimP, 0, 0);              //Trova match per Temp
            if(bmTemp>bm){                                                  //Se match trovati supera bestmatch
                cb = colonna;                                               //Colonnabest diventa colonna
                bm = bmTemp;                                                //Bestmatch diventa match trovati
            }
        F1(X,lim1,lim2,P,dimP,colonna+1,n_el,cb,bm);                        //Passa alla prossima riga
    }else if(colonna<lim2){
        int dimTemp = n_el/lim2;
        int Temp[dimTemp];
        for(int i=0; i<dimTemp; i++){
            Temp[i]=X[(lim2*i)+colonna];
        }
        cout<<"colonna n."<<colonna<<" ";                               //Dimmi che colonna è
            int bmTemp = match(&Temp[0], P, dimTemp, dimP, 0, 0);              //Trova match per Temp
            if(bmTemp>bm){                                                  //Se match trovati supera bestmatch
                cb = colonna;                                               //Colonnabest diventa colonna
                bm = bmTemp;                                                //Bestmatch diventa match trovati
            }
        F1(X,lim1,lim2,P,dimP,colonna+1,n_el,cb,bm);                        //Passa alla prossima riga
    }
}

main(){
    int X[200]={}, n_el, P[20], dimP;
    
    cin>>n_el;
    for(int i=0; i<n_el;i++)
        cin>>X[i];
    
    cin>>dimP;
    for(int i=0; i<dimP;i++)
        cin>>P[i];
    
    int lim1, lim2;
    cin>>lim1>>lim2;
    
    int rb=-1, bm=-1, cb=-1;
    
    F(X,lim1,lim2,P,dimP,0,n_el,rb,bm); // da fare che usa match dell'esercizio 1
    cout<<"migliore riga="<< rb <<" con "<<bm<< " match"<<endl;
    
    bm=-1; //azzero bm
    
    F1(X,lim1,lim2,P,dimP,0,n_el,cb,bm); // e' posibile cambiare il prototipo, ma cosi' va
    cout<<"migliore colonna="<< cb <<" con "<<bm<< " match"<<endl;
   
    cout<<"end"<<endl;
}
