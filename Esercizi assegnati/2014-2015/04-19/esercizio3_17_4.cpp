/*Integrazione sei crediti
condiviso sul gruppo facebook FIUP, non sviluppato da me, quindi non commentato*/
#include<iostream>
#include<fstream>
using namespace std;

int calcola_dist(int vfetta,int A,int righe,int colonne,int elementi){
	int tasello=0,posParziale=0,posFinale;
	for(int i=0;i<righe && tasello<=A && vfetta<colonne;i++){
        for(int s=0; s<(elementi/(righe*colonne))+1 && tasello<=A && vfetta<colonne;s++ ){
            posParziale=s*(righe*colonne)+(i*colonne)+vfetta;
            if(posParziale<elementi){
                posFinale=s*(righe*colonne)+(i*colonne)+vfetta;
                tasello++;
            }
        }
    }
 
    if(tasello<=A) 
		return -1;
    else
        return posFinale;
}

main(){
ifstream IN("input");
ofstream OUT("output");
if(IN && OUT){ 
	int X[400],P[50], n_el, dimP, lim1,lim2,lim3;
	for(int i=0; i<400;i++)
		X[i]=-1;
	IN>>lim1>>lim2>>lim3;
	IN>>n_el;
	for(int i=0; i<n_el; i++)
		IN >> X[i];
	if(n_el>lim1*lim2*lim3)
		n_el=lim1*lim2*lim3;
	for(int q=0; q<3; q++){//legge le tre quadruple
		int f, e[3];
		IN>>f>>e[0]>>e[1]>>e[2];

		for(int j=0;j<3;j++){
			int d=calcola_dist(f,e[j],lim2,lim3,n_el); // questa e' da fare (restituisce -1 a indicare che l'elemento e[j] non c'e' nella V-fetta f)
			if(d==-1)
				OUT<<e[j]<<" elemento inesistente della V-fetta "<<f<<' '; 
			else
				OUT<<d<<' ';
		}
		OUT<<endl;
    }

	IN.close(); OUT.close(); 
}
	else
		cout<<"errore con i files";
}
