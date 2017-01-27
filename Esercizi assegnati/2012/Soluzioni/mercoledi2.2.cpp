//PRE:  B[5][10] definito, B=vB
main (){
	char B[5][10];
	int indice=-1; bool ok=false;

 	for(int i=0; !ok && i<10; i++){//R: 0<=i<=10, esaminate colonne 0..i-1, SI(B[][0..i-2])=false 
		int diff =0;				// ok sse ((SI(B[][i-1]) && indice=i-1), !ok=> indice=-1
	
		for(int j=0; j<5;j++){//R1: diff=differenza tra il numero di 'a' e 'b' in B[0..j-1][i]
			if(B[j][i]=='a')
				diff++;
			else if(B[j][i]=='b')
				diff--;
		}	
		if(!diff){
			ok=true;
			indice=i;
		}
	}
}
//POST: B=vB, SI(B[][0..9])=> indice è il minimo in 0..9 t.c. SI(B[][indice]) !SI(B[][0..9]) => indice=-1

/*
R: CONDIZIONE D'ENTRATA: i=0 quindi non sono state esaminate colonne, e indice =-1 poichè non è ancora 
						 stato trovata una colonna corretta
	
   INVARIANZA: le colonne 0..i-2 non contengono ugual numero di a e di b poichè altrimenti il ciclo 
	       	   sarebbe terminato precedentemente
			   se ok=true la colonna i-1 contiene ugual numero di a e b quindi indice è uguale a i-1
			   se ok=false significa che non è stata ancora trovata una colonna corretta e infatti 
			   indice è rimasto = -1.

   CONDIZIONE D'USCITA: se ok=true significa che la colonna i-1 ha ugual numero di a e b, e difatti 
						indice è diventato uguale a i-1
						se i=10 => tutte le colonne sono state controllate e indice=-1 poiche' non e'
						stato trovato alcuna colonna con differenza uguale a 0

R1: CONDIZIONE D'ENTRATA: j=0=> B [0..-1][i] e` un insieme vuoto quindi diff=0

    INVARIANZA: prima dell'iterazione diff e' la differenza tra il numero di 'a' meno il numero
				di 'b' trovate nella colonna i-esima fino all'elemento j-2
				se l'elemento j-1 sara' uguale ad 'a' diff verra' incrementato di uno, altrimenti
				se e' uguale a 'b' verra' decrementato, restera' invece invariato se e' diverso da 
				entrambi

    CONDIZIONE D'USCITA: j=10 => tutta la colonna i-esima e' stata controllata e diff conterra' la 
						 differenza tra il numero di 'a' e di 'b'
*/
