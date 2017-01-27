//PRE: 
main(){
	int C[5][10], B[5][10];

	for(int i=0; i<5; i++) //R1
		for(int j=0; j<10; j++){  //R2
			int n=0;
			for(int k=0; k<10; k++){ //R3
				bool ok=false;
				for(int z=0; !ok && z<5; z++)  //R4
					if( C[i][k]==C[z][j])
						ok=true;
				if(!ok)
					n++;
			}
			B[i][j]=n;
		}
}
//POST: per ogni a in[0..4], per ogni b in[0..9], B[a][b] contiene il numero di elementi di C[a] non 
//	   contenuti in C[][b]
/*
R4: 0<=z<=5, ok sse esiste almeno una a in[0..z-1] t.c C[i][ĸ]=C[a][j]
POST4: ok sse esiste almeno una a in[0..4] t.c C[i][ĸ]=C[a][j]

CONDIZIONE D'ENTRATA: z=0=> a in[0..-1] insieme vuoto quindi non ho elementi da controllare quindi 
					  ok=false

INVARIANZA: ok=true se C[i][k] è uguale a C[z-1][j] e tutti i C[0..z-2][j] diversi da C[i][j] poichè
			altrimenti il ciclo sarebbe terminato precedentemente

CONDIZIONE D'USCITA: ok=true, l'elemento C[i][k] è presente nella colonna C[][j] ed in 
					 				 particolare è uguale all'elemento C[z-1][j]
					  z=5, l'elemento C[i][k] è diverso da tutti gli elementi C[0..5][j] quindi non 
						   è presente nella colonna j-esima


R3: 0<=k<=10, 0<=n<=k, n è il numero di elementi di C[i][0..k-1] che non compaiono nella colonna C[][j] 
	fino all'elemento k-1
POST3: n è il numero di elementi di C[i][0..9] che non compaiono nella colonna C[][j]


R2: 0<=j<=10, per ogni a in[0..j-1], B[i][a] e' riempito correttamente
POST2: per ogni a in[0..9], B[i][a] e' riempito correttamente


R1: 0<=i<=5, per ogni a in[0..i-1], per ogni b in[0..9], B[a][b] contiene il numero di elementi di C[a] 
	non contenuti in C[][b]
POST1: per ogni a in[0..4], per ogni b in[0..9], B[a][b] contiene il numero di elementi di C[a] non 
	   contenuti in C[][b]


*/
