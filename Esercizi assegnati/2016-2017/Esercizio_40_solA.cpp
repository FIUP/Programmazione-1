// soluzione di B.Cosentino
#include<iostream>
using namespace std;

void IP(char P[], int dimP, int I[], int &num){
	
	int start=0;  // variabile per l'inizio della sottosequenza

	for (int i=0; i<dimP; i=i+1){  // finche' non finisco il pattern
		
		if (P[i]=='*'){  // se trovo la fine di una sottopattern
			
			I[2*num]=start;   // scrivo nella corrispondente posizione di I il punto di inizio
			
			I[2*num+1]=i-start;  // scrivo nella corrispondente posizione di I la lunghezza della sottosequenza
			  
			if (i-start>0)
                num+=1;  // incremento il contatore delle sottosequenze
            
            start=i+1;  // imposto il punto di inizio della prossima sequenza
		}
	}

	I[2*num]=start;
	I[2*num+1]=dimP-start;
	if (P[dimP-1]!='*')    
	    num+=1;
}

bool pattern(char T[], int dimT, char SP[], int dimSP){
	
	bool trovato=true;
	
	for (int i=0; i<dimSP && trovato; i=i+1){
		trovato=trovato && (T[i]==SP[i]);
	}
	return trovato;
}


bool match(char* T, int dimT, char* P, int dimP, int* X, int &num){

	int I[100];
	int k=0;
	int salto=1;
	IP(P, dimP, I, num);
	
	for (int i=0; i<dimT && k<num; i=i+1){
		
		if (pattern(T+i, dimT-i, P+I[2*k], I[2*k+1])){
			
			X[2*k]=salto-1;
			X[2*k+1]=I[2*k+1];
			salto=0;
			i+=I[2*k+1]-1; // incremento della lunghezza del sottopattern -1
		    k+=1; // incremento l'indice dei sottopattern
		}
		
		salto+=1;
	}
	return k==num;
}

void stampaSP(char SP[], int dimSP){
    
    for (int i=0; i<dimSP; i++){
        cout << SP[i];
        
    }
}

void stampa(char*P, int dimP, int*X, int num){
    int I[100];
    num=0; 
	IP(P, dimP, I, num);
	
    for (int i=0; i<num; i++){
        
        if (X[2*i]>0){
            cout << endl << "dopo "<<X[2*i]<<" elementi"<<endl<<"troviamo ";
            stampaSP(P+I[2*i],X[2*i+1]);
        } else {
            stampaSP(P+I[2*i],X[2*i+1]);
        }
    }
    cout << endl;
}



main(){

	char T[400], P[50];
	char c;
	int i=0;
	cin >> c;
	
	while (c != '.')
		{P[i]=c; i++; cin>>c;}
	
	int dimP=i;
	i=0;
	cin >> c;
	
	while (c != '.')
		{T[i]=c; i++; cin>>c;}
	
	cout<<"start"<<endl;
	
	int dimT=i;
	int X[100];

	int num=0;
	bool m=match(T,dimT,P,dimP,X,num); // da fare

	if(!m)
	cout<<"nessun match"<<endl;
	else{
		for(int i=0; i<num; i=i+1)
		    cout<<X[2*i]<<' '<<X[2*i+1]<<endl;
		stampa(P,dimP,X,num);  // da fare
	}
	cout<<"end"<<endl;
}
