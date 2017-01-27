//Matteo Gazzato 594140  ESERCITAZIONE DEL 21/2/2013 SETTIMANA 5
/*
TEORIA
int & g(int ** x){int *p=*x+1; *p=**x+*p; return *(p-1);} 
main() {int X[]={1,2,3}, *q=X+1; g(&q)=X[1]; cout<<X[0]<<X[1]<<X[2]<<endl;}

*q=2 (poichè q punta ad X[1])
&q è l-value di q,con tipo int ** che concorda con il tipo richiesto dalla funzione g => OK =>x punta al puntatore q
p punta a *x+1 e quindi a q+1==&X[2] => *p=**x+*p == X[2]=X[1]+X[2]=5 
return *(p-1)== *q == X[1] che concorda con il tipo di ritorno della funzione =>OK
Quindi g(&q)==X[1]=X[1] quindi X[1] in questo caso non viene cambiato
Programma corretto,stampa 125 

*/
#include <iostream>
#include <fstream>

using namespace std;

void G(int X[], ifstream & INP, ofstream & OUT)
{
	bool riempito=false,trovato=false;
	int cont=0,k=0,a;
	
	while(!trovato)
	{//R_G
		INP>>a;
		if(a==-2)
			trovato=true;//fermati
		else
		{
			if(cont%10==0)
			{
				k=0;
				riempito=true;
			}
			X[k]=a;
			cont++;
			k++;	
		}
			
	}//fine while
	
	//caso (i): stampo i seq elementi di w
	if(!riempito)
	{
		for(int i=0;i<cont;i++)
			OUT<<X[i]<<" ";
	}
	else//caso (ii): stampo i seq=10 elementi di w2
	{
		for(int i=k;i<10;i++)//stampo prima i 10-k elementi "più vecchi" di w2   
			OUT<<X[i]<<" ";
		for(int i=0;i<k;i++)//stampo gli ultimi k-1 elementi di w2 
			OUT<<X[i]<<" ";
	}	
	
}//fine G

void SEL(int X[], int & dim, int k)
{
	int cont=0;
	while(cont!=dim)
	{//R_SEL
		if(X[cont]==k)
		{
			for(int i=cont;i<dim-1;i++)
				X[i]=X[i+1];//R2
			dim--;//POST2
		}
		else
			cont++;
//R2=(per ogni X[j],X[j+1]..X[i-1] si ha X[j]=X[j+1],
//con j∈[cont..i-1])			
//POST2=(per ogni X[cont],X[cont+1]..X[dim-2] si ha 
//X[cont]=X[cont+1],X[cont+1]=X[cont+2]..X[dim-2]=X[dim-1])
	}
}//fine SEL

int main()
{
	ifstream IN("input1");
	ofstream OUT("output1");
	
	int X[10];
	
	G(X,IN,OUT);

	IN.close();
	OUT.close();
	
	int dim=8,k=2;
	int A[8]={1,4,1,3,4,1,6,2};
	
	cout<<"Array A originale con "<<dim<<" elementi: ";
	for(int i=0;i<dim;i++)
		cout<<A[i]<<" ";
	cout<<endl;
	
	SEL(A,dim,k);
	
	cout<<"Array A modificato con "<<dim<<" elementi: ";
	for(int i=0;i<dim;i++)
		cout<<A[i]<<" ";
	cout<<endl;
	
}

/*
PRE_G=(X ha 10 posizioni) && (vale caso (i) o caso (ii)), specificati
di seguito:
caso (i)= (input1 contiene w -2,con w = seq. di non più di 10 valori)
caso (ii)=(input1 contiene w1 w2 -2, con w2 = seq. di 10 int e 
w1= seq. non vuota di interi)

R_G=((!trovato && !riempito=>sono stati letti cont-1 interi da INP e 
sono stati messi nelle prime cont-1 posizioni di X) && 
(!trovato && riempito=>X contiene gli ultimi 10 valori letti da INP 
&& cont-1>=10) && (trovato && !riempito=>sono stati letti cont-1 
interi da INP e sono stati messi nelle prime cont-1 posizioni di X 
&& l'ultimo valore letto è -2 (caso(i))) && 
(trovato && riempito=>X contiene gli ultimi 10 valori letti da INP 
&& cont-1>=10 && l'ultimo valore letto è -2 (caso(ii))))

POST_G=(nel caso (i) output1 contiene w) &&(nel caso (ii) output1 
contiene w2 && trovato)

CORRETTEZZA (PRE_G,R_G,POST_G):

invarianza: se fino ad ora ho letto cont-1 valori e cont-1<10 allora
ricado nel caso(i) && !trovato=>X contiene i primi cont-1 valori,
devo ancora leggere la sentinella -2=>vale R
Se cont-1>=10 sono nel caso(ii)=>riempito=>i precedenti cont-10 
elmenti sono gli ultimi 10 valori letti da INP ed il successivo 
cont elemento deve essere aggiunto ad X al posto dell'elemento 
cont-10=>X contiene ancora gli ultimi 10 valori letti da INP e non
ho ancora letto -2=>vale R nuovamente

caso di uscita:-nel caso(i) ho letto cont-1<10 elementi da INP e 
sono stati messi nelle prime cont-1 posizioni di X ed il cont-esimo
elemento letto è -2 =>viene stampato su output X che contiene 
correttamente w=>POST
-nel caso(ii) sono stati letti cont-1>=10 elementi da INP e X 
contiene gli ultimi 10 elementi dei cont-1 letti ed il cont-esimo 
elemento letto è -2=>viene stampato su output X che contiene 
correttamente w2=>POST 

PRE_SEL=(X ha dim elementi definiti e k è definito)&&(X=vX) &&
(vdim=dim) vX e vdim sta per vecchio a indicare i valori originali 
di X e dim)

R_SEL=(cont!=dim && in X[0]..X[cont-1] sono stati rimossi i vdim-dim
elementi uguali a k ed i rimanenti elementi sono nello stesso ordine 
relativo che avevano in vX && in X restano dim elementi)

POST_SEL=(X contiene esattamente tutti i valori di vX diversi da k e
nello stesso ordine relativo che avevano in vX) &&
(il numero di elementi che restano in X è dim<=vdim)

CORRETTEZZA (PRE_SEL,R_SEL,POST_SEL):

condizione iniziale: vdim=dim => X contiene i vdim-dim=0 elementi 
di vX diversi da k e nello stesso ordine relativo che avevano in vX 
=>vale R

invarianza: se l'elemento cont-esimo di X corrisponde a k=>da POST2
ottengo l'array X privo del cont-esimo elemento e tutti gli elementi 
compresi tra X[cont]..X[dim-1] sono nello stesso ordine relativo che
 avevano in vX && decremento dim=> X ora non contiene i vdim-dim 
elementi di vX uguali a k ed i rimanenti elementi sono nello stesso
 ordine relativo che avevano in vX && in X restano dim elementi 
&& dim!=cont =>vale R_SEL

caso di uscita: dim=cont && in X[0]..X[dim-1] sono stati rimossi i 
vdim-dim elementi uguali a k ed i rimanenti elementi sono nello 
stesso ordine relativo che avevano in vX && in X restano dim 
elementi,con dim<=vdim =>POST_SEL
*/

