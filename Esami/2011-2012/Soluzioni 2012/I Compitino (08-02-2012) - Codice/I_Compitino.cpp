//notazione: POST(k) = (0<=k<100) &&(POST con k al posto di 99)
main(){
	int C[100],int B[100];
	for(int i=0;i<100;i++)
		B[i]=-1;

	for(int i=0; i<100; i++){//R1
		if(B[i]==-1){
			B[i]=1;
			for(int j=i+1; j<100; j++)  //R2
				if(C[j]==C[i])
					B[j]=0;
		}	
	}
}		
/*
R1: 0<=i<=100 && POST(i-1) && (per ogni a in[i..99], B[a]=-1/0 && B[a]=-1 => C[a] non appartiene
	  a C[0..i-1] && (B[a]=0 => C[a] appartiene a C[0..i-1])
POST: B[0..99] contiene solo valori 1 o 0, per ogni valore v in C[0..99], esiste un solo b in[0..99],
	    tale che C[b]=v e B[b]= 1

CONDIZIONE D'ENTRATA: i=0 => POST(-1) quindi l'array B non è ancora stato modificato e di conseguenza 
					  contiene solo -1 perchè non ci possono essere elementi che appartengono a C[0..-1]

INVARIANZA: per ogni elemento di B, 
			se è uguale a 0 l'iterazione termina poichè gli elementi che hanno valore uguale a C[i-1] 
				sono già stati correttamente modificati
			se è uguale a -1, l'elemento B[i-1] viene modificato in 1 poichè è la prima volta che 
				troviamo questo elemento in C, altrimenti sarebbe già stato precedentemente modificato 
		   		in 0, poi tutti gli elementi tra i e 99 e il cui valore in C sia uguale a C[i-1], il
				loro B viene messo uguale a 0.

CONDIZIONE D'USCITA: i=100, quindi l'array è stato completamente percorso e per POST(i-1)=POST(99), 
					 la POST è soddisfatta
	

R2: per ogni a in[i+1..j-1] if C[a]=C[i] then B[a]=0 else B[a]=vB[a]
POST2: per ogni a in[i+1..99] if C[a]=C[i] then B[a]=0 else B[a]=vB[a]

CONDIZIONE D'ENTRATA: j=i+1=> in[i+1..i] non ci sono elementi da considerare quindi B non viene modificato
 
INVARIANZA: dopo ogni iterazione se C[j-1]=C[i], B[i-1]=0 e gli elementi di B tra i+1 e j-2 erano 
			stati analizzati nelle iterazioni precedenti
	
CONDIZIONE D'USCITA: se j=100 non ci sono più elementi da considerare, quindi tutti gli elementi 
					 di B da i+1 a j-1=99 sono stati correttamente modificati	
*/
