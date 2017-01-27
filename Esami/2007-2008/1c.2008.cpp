//PRE: A array monodimensionale definito, P definito di dim_P elementi
bool match(char*A,char*P,int dim_P)
{bool trovato=true;
 for(int i=1;i<dim_P && trovato;i++)//R: trovato sse per ogni a in[1..i-1] P[a]=A[a], 1<=i<=dim_P
	if(P[i]!=A[i])
	 trovato=false;
return trovato;
}
//POST: trovato sse per ogni a in[1..dim_P-1] P[a]=A[a]
//PRE: A[dim] definito, P[dim_P] definito colon definito
int F(char *A, int dim, int colon, char*P, int dim_P)
{int RP=dim/colon, EU=dim%colon, max=-1,indice=-1;
 for(int i=0;i<RP;i++)//R1: 0<=i<=RP,  indice=c con c in[0..i-1] t.c. A[c][] è la riga con maggior numero di match, 
	{ int conta=0;		// max è il numero di match della riga A[c][]
	for(int j=0;j<colon-dim_P+1;j++)//R2: 0<=j<=(colon-dim_P+1), conta è il num di match in A[i][0...j-1]
		if(P[0]==*(A+i*colon+j))
			if(match(A+i*colon+j,P,dim_P))
				{conta++;
				j=j+dim_P-1;
				}
	//POST2: conta è il num di match in A[i][0...colon-1]
	 if(conta>max)
		{
		max=conta;
		indice=i;
		}
	}//POST1: indice=c con c in[0..RP-1] t.c. A[c][] è la riga con maggior numero di match, max è il numero di match della riga A[c][]
for(int i=0;i<EU-dim_P+1;i++)//R3: 0<=i<=EU-dim_P+1, conta è il num di match in A[RP][0...i-1]
 {int conta=0;
   if(*(A+RP*colon+i)==P[0])
	if(match(A+RP*colon+i,P,dim_P))
				{conta++;
				i=i+dim_P-1;
				}
	 if(conta>max)
		indice=RP;
 }//POST3:conta è il num di match in A[RP][0...EU-1], indice=RP sse conta > max. 
//POST: indice=b con b in[0..RP] && A[b][] indice di riga con massimo numero di match
return indice;
}

main()
{}

/* PROVA DI CORRETTEZZA del ciclo in match
CONDIZIONE INIZIALE: i=1 => a in [1..0] quindi non ci sono elementi da considerare e trovato resta uguale a true

INVARIANZA: se trovato è true, allora gli elementi da P[1..i-1] e gli elementi A[1..i-1] sono uguali, in caso uno degli elementi fosse
stato diverso trovato sarebbe diventato false e il ciclo sarebbe terminato precedentemente.
se trovato è false allora l'elemento P[i-1] non coincide con l'elemento A[i-1] e gli elementi [0..i-2] coincidono, in caso uno di questi elementi
fosse stato diverso  trovato sarebbe diventato false precedentemente e il ciclo sarebbe terminato.

CONDIZIONE DI USCITA: se il ciclo termina per i=dim_P => trovato è rimasto true e quindi gli elementi coincidono, se termina poichè trovato è diventato false allora non c'è match. se si esce per entrambi significa che l'ultimo elemento non coincide e difatti trovato è false
*/
