#include<iostream>
#include<fstream>
#include<climits>

using namespace std;

//PRE_stampa_cammino=(path punta ad una pozione di memoria [0..lim2-1] contenente lim2 indici delle posizioni del cammino nell'array)
void stampa(int* path, int dim_path, ofstream & OUT){

	if(!dim_path)
		return;
	stampa(path-1, dim_path-1, OUT);
	OUT<<*path<<" ";		

}//POST_stampa_cammino=(stampa su "output" gli indici del cammino)


//PRE=()
bool cammino(bool* M, int lim2, int lim3, int* path, int percorso, const int dim_path, ofstream & OUT){

	if(percorso==-1 || percorso==lim3)
		return false;

	if(lim2==1){
		if(*M){
			*path=percorso;
			stampa(path, dim_path, OUT);
			OUT<<endl;
			return true;
		} else return false;
	} else {
			if(*M){
				*path=percorso;
				return(cammino(M+lim3-1, lim2-1, lim3, path+1, percorso-1, dim_path, OUT)|
								cammino(M+lim3, lim2-1, lim3, path+1, percorso, dim_path, OUT)|
								cammino(M+lim3+1, lim2-1, lim3, path+1, percorso+1, dim_path, OUT));	
			} else return false;
	}
}//POST=()


//PRE=(M ha lim2*lim3 valori bool definiti, lim2 e lim3 >0, path ha lim2 elementi, e ....)
bool find_paths(bool* M, int lim2, int lim3, int* path, int percorso, const int dim_path, ofstream & OUT){

	if(percorso<lim3){
		if(cammino(M, lim2, lim3, path, percorso, dim_path, OUT)){
			return 1|find_paths(M+1, lim2, lim3, path, percorso+1, dim_path, OUT);
		}
		else {
			return find_paths(M+1, lim2, lim3, path, percorso+1, dim_path, OUT);
		}
	} else return false;

}//POST =(se restituisce true c'è almeno un cammino in M che porta dalla prima all'ultima riga e "output" contiene tutti i cammini di questo tipo di M, se non c'è alcun cammino allora "output" resta vuoto o... qualcosa di simile)



main(){
  ifstream INP("input"); 
  ofstream OUT("output");

	if(INP && OUT){
		int lim2, lim3;
		INP>>lim2>>lim3;
		bool* M=new bool[lim2*lim3];
		int* path=new int[lim2];
		for(int i=0; i<lim2*lim3; i++)
			INP>>M[i];
		
		int percorso=0;
		bool x=find_paths(M, lim2, lim3, path, percorso, lim2, OUT);
		if(!x)
			OUT<<"nessun cammino"<<endl;

		INP.close();
		OUT.close();
	} else cout<<"problemi con i file";
}
