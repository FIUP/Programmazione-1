//Soluzione di S.Righetto

#include<iostream>
using namespace std;

//PRE=(n>0 e A[0..(n-1)*step] è definito)
int colonna(int *A,int n, int step){	
	int somma=0;
	for(int i=0; i+step<n; i=i+8){
	 	somma= somma+ A[i];
	 }
	 return somma;
} 
//POST=(restituisce il valore di A[0]+A[step]+A[2*step]+A[3*step]+...+A[(n-1)*step])


//PRE=(cin contiene n_ele, 0<n_ele<=400, seguito da n_ele interi qualsiasi)
main(){
	int A[10][5][8], *p=A[0][0];
	int n_ele,bv,bf, s; 
	cin>>n_ele; 
	for(int i=0; i<n_ele; i=i+1)
    cin>>p[i];
	cout<<"start"<<endl;
	bv=colonna(p,n_ele,0);
	bf=0;
	for(int k=1; k<8; k++){
	    s= colonna(p+k,n_ele,k);
		if(s>=bv) {
		    //cout << s <<'>' << bv << endl << k <<endl;
		    bv=s;
		    bf=k;
		    }
		
	}
	cout<<"V-fetta massima="<<bf<<" con somma="<<bv<<endl;
	cout<<"end"<<endl;
}
//POST=(stampa l'indice della V-fetta a somma massima seguito dalla sua somma e in caso di parità, stampa l'indice massimo)



