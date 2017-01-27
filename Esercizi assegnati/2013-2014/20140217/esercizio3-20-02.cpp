#include<iostream>
#include<fstream>
#include<climits>

using namespace std;



//PRE=(dimP>=0)
bool match_s_contiguo(int *T, int *P, int dimP){

cout<<" *** 3 *** "<<endl;

	// ---------- caso base 1 ----------
	if(dimP==0){
cout<<" *** 3.1 *** "<<endl;
		return 1; //c'è match completo e contiguo di P in T[indiceT-dimP-1..indiceT-1]
	}

	// ---------- caso ricorsivo ----------
	if(T[0]==P[0]){
cout<<" *** 3.2 *** "<<endl;
		return match_s_contiguo(T+1, P+1, dimP-1);
	}
	// ---------- caso base 2 ----------	
	else{
cout<<" *** 3.3 *** "<<endl;
		return 0; //non c'è match completo e contiguo
	}

}//POST=(restituisce 1 se c'è match completo e contiguo; 0 altrimenti)



//PRE=()
int cerca_match_s(int *T, int dimT, int *P, int dimP){

cout<<" *** 2 *** "<<"("<<dimT<<")"<<endl;

	// ---------- caso base ----------
	// prima o poi arriverò ad avere n<dimP
	if(dimT<dimP){ //non ci sono dimP elementi definiti per cercare il match
cout<<" *** 2.1 *** "<<endl;
		return 0;
	}

	// ---------- caso ricorsivo 1 ----------
	// cerco se c'è match contiguo
	if(match_s_contiguo(T, P, dimP)){
cout<<" *** 2.2 *** "<<endl;
		return 1+cerca_match_s(T+1, dimT-1, P+1, dimP-1);
	}
	// ---------- caso ricorsivo 2 ----------
	// parto a cercare dall'elemento successivo
	else{
cout<<" *** 2.3 *** "<<endl;
		return cerca_match_s(T+1, dimT-1, P, dimP);
	}

}//POST=(ritorna il numero di match contigui e completi)



//PRE=(T[0..n-1], n>0, è definito, P[0..dimP-1], dimP>0, è definito, e lim1, lim2 e lim3 sono >0)
void match_s(int*T, int n, int lim2, int lim3, int*P, int dimP, ofstream &OUT){

cout<<" *** 1 *** "<<"("<<n<<")"<<endl;

	// ---------- caso ricorsivo ----------
	if(n>=lim2*lim3){
cout<<" *** 1.1 *** "<<endl;
		OUT<<cerca_match_s(T, lim2*lim3, P, dimP)<<" ";
		match_s(T+(lim2*lim3), n-(lim2*lim3), lim2, lim3, P, dimP, OUT);
	}
	
	// ---------- caso base ----------
	else{
cout<<" *** 1.2 *** "<<endl;
		OUT<<cerca_match_s(T, n, P, dimP)<<" ";
  }

}//POST=(su "output", per ciascuno strato con qualche elemento definito, si deve scrivere il numero di match di P su quello strato; vanno considerati tutti i match anche sovrapposti tra loro)

/*

//PRE cerca_match_ns=()
int cerca_match_ns(){
	
	

}//POST=()



//PRE=(T[0..n-1], n>0, è definito, P[0..dimP-1], dimP>0, è definito, e lim1, lim2 e lim3 sono >0)
void match_ns(int*T, int n, int lim2, int lim3, int*P, int dimP, ofstream &OUT){

	

}//POST=(su "output", per ciascuno strato con qualche elemento definito, si deve scrivere il numero di match di P su quello strato; vanno considerati solo i match NON sovrapposti tra loro)

*/

main(){
	ifstream INP("input"); 
	ofstream OUT("output"); 

	if(INP && OUT){
		int n, lim1, lim2, lim3, T[200], P[20], dimP, n_occ, indice_c=-1;
		INP>>n;
		for(int i=0; i<100; i++)
			INP>>T[i];
		INP>>lim1>>lim2>>lim3>>dimP;
		for(int i=0; i<dimP;i++){
			INP>>P[i];
			cout<<P[i]<<endl;
		}
  
		match_s(T,n,lim2,lim3,P,dimP, OUT);
		//match_ns(T,n,lim2,lim3,P,dimP, OUT);

		INP.close();
		OUT.close();
	}else cout<<"problemi con i file";
}
