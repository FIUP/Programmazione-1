#include<iostream>
using namespace std;

struct nodo{char info; nodo* left; nodo* right; nodo(char, nodo*, nodo*);};
nodo::nodo(char a='0', nodo* b=0, nodo* c=0) {info=a; left=b; right=c;}
	
struct nodoP{nodo* info; nodoP* next; nodoP(nodo*, nodoP*);};
nodoP::nodoP(nodo* a, nodoP* b) {info=a; next=b;}

// PRE=(R è un valore nodo* valido, dim_P>0 e P[0..dim_P-1] è definito)
nodoP* F(nodo* R, char *P, int dim_P){
	nodoP * K = 0;
	if (!R)
		return 0;
	if (R->info == P[0]){
		if (dim_P <= 1){
			return new nodoP(R, 0);
		}
		P = P+1;
		dim_P--;
	}
	K = F(R->left, P, dim_P);
	if(!K)
		K = F(R->right, P, dim_P);
	if (K && R->info == P[-1])
		K = new nodoP(R, K);
	return K;		
}
/* 
POST=(F restituisce K !=0 => esiste un match (contiguo o no) di P in R e la lista K è 
un testimone di un tale match) &&( F restituisce K=0 => non esiste alcun match (né contiguo né non contiguo) 
di P in R) &&(F non costruisce alcun nodo nodoP oltre quelli in K)

 --- DIMOSTRAZIONE PER INDUZIONE: ---

 Caso base: 
	*R == 0: 
		Non esiste alcun match (ne' contiguo ne' non contiguo) di P in R o sono arrivato ad una foglia e devo tornare indietro visto
		che non c'e' stato alcun match di P nel percorso finora controllato. Nel caso di nessun match, ritorna zero, vale la POST.
	*R->info == P[0] && dim_P <= 1:
		Abbiamo trovato l'ultimo carattere del match, dobbiamo quindi costruire la lista K tornando in dietro. Viene quindi creato l'ultimo nodo
		della lista collegandolo a zero e dandogli campo informativo R (ovvero il nodo che stiamo processando). Se e' il primo e l'ultimo,
		ritorniamo la lista K di un solo nodo col nodo corretto, vale la POST.
			
 Passo induttivo:
 	*R->info == P[0] && dim_P > 1:
		Abbiamo trovato che un carattere del pattern matcha il carattere del campo informativo del nodo che stiamo esaminando. Viene quindi
		incrementato il puntatore dell'array P e diminuito dim_P.
	*!K:
		Nel ramo a sinistra non abbiamo trovato nulla, proviamo quindi col ramo a destra. Non avrebbe senso cercare comunque nel ramo a destra
		perche' una volta trovato un match, qualunque esso sia, la funzione puo' "chiudere" e ritornare semplicemente il risultato.
	*(K && R->info == P[-1]):
		Se K esiste, vuol dire che almeno l'ultimo elemento della lista K e' stato caricato, accodiamo quindi il nodo che stiamo processando
		se il suo campo informativo e' uguale a P[-1] (-1 perche' sopra abbiamo dovuto incrementare P di un'unita').
	In entrambe le invocazioni ricorsive vale la PRE (dim_P e' comunque sempre > 0 e P e' correttamente definito) e arriviamo alla fine a
	ottenere la lista K correttamente compilato come richiesto dalla POST.
*/

// PRE=(R è un valore nodo* valido, dim_P>0 e P[0..dim_P-1] è definito)
int miniSearch(nodo*R, char*P, int dim_P){
	int tot = 0;
	if (!R){
		return 0;
	}
	if (R->info == P[0]){
		if (!(dim_P-1)){
			return 1;
		}
		tot = miniSearch(R->left, P+1, dim_P-1);
		tot += miniSearch(R->right, P+1, dim_P-1);
	}
	return tot;
}
/* 
 --- DIMOSTRAZIONE PER INDUZIONE: ---

 Caso base: 
	*R == 0: 
		Non esiste alcun match contiguo di P in R o sono arrivato ad una foglia e devo tornare indietro visto
		che non c'e' stato alcun match di P nel percorso finora controllato. Nel caso di nessun match, ritorna zero, vale la POST.			
 Passo induttivo:	
 	*R->info == P[0]:
		Se si trova un match del primo carattere del pattern col carattere del campo informativo del nodo R, viene invocata ricorsivamente
		la funzione finche' o non si trova un carattere diverso dal pattern o finche' non finisce il pattern, salvando il numero di occorrenze
		nella variabile locale tot che viene quindi ritornata, come richiesto dalla POST.

POST = (G restituisce ris >0 => esiste un numero ris di match contigui, anche sovrapposti, 
di P in R) && (F restituisce ris = 0 => non esiste alcun match continuo)
*/
	
// PRE=(R è un valore nodo* valido, dim_P>0 e P[0..dim_P-1] è definito)
int G(nodo*R, char*P, int dim_P){
	if (!R)
		return 0;
	int ris = 0, ricerca = 0;
	ris = G(R->left, P, dim_P);
	ris += G(R->right, P, dim_P);
	if (R->info == P[0]){
		ricerca = miniSearch(R, P, dim_P);
		ris += ricerca;
	}
	return ris;
}
/* 
 --- DIMOSTRAZIONE PER INDUZIONE: ---

 Caso base: 
	*R == 0: 
		Non esiste alcun match contiguo di P in R o sono arrivato ad una foglia e devo tornare indietro visto
		che non c'e' stato alcun match di P nel percorso finora controllato. Nel caso di nessun match, ritorna zero, vale la POST.			
 Passo induttivo:
	Viene invocata la funzione ricorsivamente prima nel ramo a sinistra e poi nel ramo a destra per arrivare al fondo di entrambi
	i rami per lavorare ricorsivamente. Vale la PRE visto che R->left e R->right sono nodi validi e P e dim_P non cambiano rispetto
	a quelli dati (che sappiamo essere validi grazie alla PRE di G). Quindi, per ragionamento induttivo, vale la POST.
	
 	*R->info == P[0]:
		Se si trova un match del primo carattere del pattern col carattere del campo informativo del nodo R, viene chiamata una funzione
		ricorsiva di supporto, miniSearch, per vedere quante occorrenze di P vengono trovate a partire dal nodo che stiamo processando
		finche' ci sono corrispondenze.
		
	Vengono quindi sommati i risultati della ricerca al risultato gia' trovato e viene ritornato il valore giusto, come richiesto dalla POST.

POST = (G restituisce ris >0 => esiste un numero ris di match contigui, anche sovrapposti, 
di P in R) && (F restituisce ris = 0 => non esiste alcun match continuo)
*/

int main(){
} 
