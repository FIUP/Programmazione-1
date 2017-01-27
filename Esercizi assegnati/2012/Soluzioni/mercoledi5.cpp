//PRE: T ha almeno dim_P elementi, P[0 .. dim_P-1] definito
bool match(char *T, char *P, int dim_P){
	bool ok=true;
	for(int i=0; ok && i<dim_P; i++) // R: 0<=i<=dim_P && ok sse T[a]=P[a] con a in [0 .. i-1]
		if(P[i]!=T[i])
			ok=false;
	return ok;
}
//POST: per ogni a in [0 .. dim_P-1] restituisce ok t.c. ok sse T[a]=P[a]

//PRE: T[0..lim-1] definita, lim>0, P[0..dim_P-1] definita e dim_P>0
bool matchR(char*T, int lim, char*P, int dim_P){
	bool si=false;
	for(int i=0; !si && i<lim-dimP+1; i++) //R:0<=i<=lim-dimP+1, si sse esiste a in[0..i-1] 
		if(match(T+i,P,dim_P))				// t.c. T[a..a+dim_P-1]=P[0..dim_P-1]
			si=true;
	return si;
}
//POST: restituisce si t.c. si sse esiste un a in[0..lim-1] a partire dal quale T[a..a+dim_P-1 =P[0..dim_P-1]

//PRE: T[0..righe-1] [20] è definito, righe>=0, P[0..dim_P-1] è definito con dim_P>0
int matchS(char T[][20], int righe, char*P, int dim_P){
	int conta=0;
	for(int i=0; i<righe; i++)
		if(matchR(*(T+i), 20, P, dim_P)) //R: conta = n. righe in T[0..i-1] in cui c’è match con P
			conta++;
	return conta;
}
//POST: restituisce conta=n.righe in T[0..righe-1] che contengono un match con P[0..dim_P-1]

//PRE: T ha solo i primi n_ele elementi definiti, n_ele>0, char P[dim_P] è definito
int F(char T[][10][20], char*P, int dim_P, int n_ele){
	int nsp=n_ele/200, neu=n_ele%200, best=-1, indice=-1;
	for(int i=0; i<nsp; i++){ //R: i=0=>best=indice=-1 && i>0=>T[indice] strato migliore tra strati 0..i-1
		int x=matchS(T[i], 10, P, dim_P);
		if(x> best){
			best=x; indice=i;
		}
	}
	int nr=neu/20, ne=neu%20;
	int x= matchS(T[nsp],nr, P, dim_P)+(matchR(T[nsp][nr], ne, P, dim_P) ? 1 : 0);
	if(x>best)
		indice=nsp;
	return indice;
}
//POST: F restituisce un indice I t.c. lo strato T[I] ha un numero di righe in cui esiste un match con 
//		P maggiore o uguale a quello degli altri strati di T considerando solo gli elementi definiti
main(){}
/*F. match: 
CONDIZIONE D'ENTRATA: i=0 => T[0..-1] e P[0..-1] sono insiemi vuoti quindi ok rimane true

INVARIANZA: gli elementi fino a T[i-2] sono uguali a P[i-2] poichè se così non fosse il ciclo sarebbe 
			terminato precedentemente se ok è false il ciclo termina poichè l'elemento T[i-1] è
			diverso da P[i-1], se ok è true significa che anche l'elemento i-1 è uguale

CONDIZIONE D'USCITA: ok=false allora è stato trovato un elemento che non coincide e difatti restituisce 
					 falso, altrimenti se si esce per i=dim_P, significa che l'array è stato controllato 
					 completamente e ogni elemento coincide, e restituisce ok che è uguale a true
						
F. matchR: 
CONDIZIONE D'ENTRATA: i=0=> a in[0..-1] che è un insieme vuoto quindi non ho elementi da controllare

INVARIANZA: partendo dagli elementi fino a i-2 non esiste un match poichè altrimenti il ciclo 
			sarebbe terminato precedentemente e se si =false a partire da i-1 non è stato trovato match 
			quindi si continua a cercare negli elementi successivi, se si=true significa che c'è match 
			a partire da i-1 e il ciclo termina restituendo true

CONDIZIONE D'USCITA: se si=true allora si è usciti poichè è stato trovato un match, altrimenti se si 
					esce per i=lim-dimP+1 significa che non è stato trovato alcun match nell'array ed è 
					inutile incrementare i poichè l'intervallo rimanente è troppo piccolo per 
					contenere un match

F. matchS: 
CONDIZIONE D'ENTRATA: i=0 => in T[0 .. -1] non ci sono righe quindi conta rimane uguale a 0

INVARIANZA: conta contiene il numero di match nelle righe controllate fino ad T[i-2] dopo 
					  l'iterazione se c'è match conta viene  aumentato altrimenti resta uguale

CONDIZIONE D'USCITA: i=righe, quindi sono state analizzate tutte le righe e quindi conta 
					 contiene il numero di righe che hanno match

F. F: 
CONDIZIONE D'ENTRATA: i=0 significa che non sono ancora stati analizzati strati quindi indice =-1

INVARIANZA: best prima dell'iterazione contiene il massimo numero di match trovati in uno strato 
			fino ad i-2, e indice contiene l'indice di quello strato, se il numero di match trovati 
			nello strato i-1 è maggiore di best, allora indice diventa i-1 e best diventa il numero 
			di match in i-1

CONDIZIONE D'USCITA: i=nsp quindi abbiamo controllato tutti gli strati pieni e indice sarà l'indice 
					 allo strato a cui appartiene best 
*/
