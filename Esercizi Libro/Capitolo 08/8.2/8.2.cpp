#include<climits>
int G(int *A, int limite1, int limite2, int limite3, int n_ele){
	int sommaM=INT_MIN, indice=0;
	
	for(int f=0; f<limite2 && f*limite3 < n_ele; f++){ 			//f = fetta; in realtà f indica le righe le fette sono indicate da 2 indici f e s
		int somma=0; bool fine_fetta = false;					//la fetta f contiene almeno un elemento definito, nella riga indicata da f 
		for(int s=0;s<limite1 && !fine_fetta;s++){ 				//s = strato
			int sommar = 0;										//somma degli elementi definiti della riga f dello strato s
			for(int c=0; c < limite3 && !fine_fetta; c++)		//c = colonna, indica l'elemento della riga f nello strato sb_type
				if(s*(limite2*limite3)+f*limite3+c < n_ele)
					sommar += A[s*(limite2*limite3)+f*limite3+c];
				else
					fine_fetta=true;
			somma +=sommar;								 
		}
		if(somma > sommaM){
			sommaM=somma;
			indice = f;
		}
	}
	return indice;
}

main(){
	//main vuoto
}