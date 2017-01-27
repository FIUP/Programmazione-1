//Matteo Gazzato 594140  ESERCITAZIONE DEL 24/1/2013 SETTIMANA 2
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int dim,x,y,A[100];
	ifstream IN("input2");
	ofstream OUT("output2");
	
	if(IN)
	{
		IN>>dim;
			for(int k=0;k<dim;k++)
				IN>>A[k];
		IN>>x;
		IN>>y;
		
		IN.close();
	}
	else
		cout<<"Errore,impossibile aprire il file di input!"<<endl;
		
	int ini=0,fin=0,max=0,i1=0,im,i2=1;
//uso i1 e i2 per il confronto degli elementi dell'array
	
	while(i2<dim)//R1
	{
		if(A[i1]<=A[i2])
		{
			im=i1+1;
			i2++;
			int a=1;
			bool ok=true;
			while(ok && i2<dim)//R2
			{
				if(A[im]<=A[i2])
					{im++;i2++;a++;}
				else
					ok=false;
			}
			
			if(a>max)
//ho trovato una sottoseq di lunghezza almeno 2,vedo se è massima
			{ini=i1;fin=im;max=a;}
			i1=i2;i2++;
		}
		else
		{i1++;i2++;}
	}
	
	OUT<<ini<<" "<<fin;	
	OUT.close();
}//fine main
	
/*
PRE=(Il file input2.txt contiene in sequenza,con uno spazio tra un 
valore e l'altro,i seguenti valori:
dim,tale che 1<=dim<=100;dim interi, che vengono inseriti in 
A[0],A[1]..A[dim-1].)

R1=(0<=i1<i2<dim && max è la lunghezza della massima sottosequenza 
trovata in A[0..i2-1] && ini e fin sono gli indici di inizio e di 
fine della sottosequenza crescente massima trovata in A[0..i2-1])

R2=((i1 è l'inizio di una sottosequenza crescente,con 0<=i1<i2 && 
(ok=>per ogni A[i1],A[i1+1]..A[im-1] si ha A[i1]<A[i1+1]<..<A[im-1],
con i1<im<=i2-1 && a è la lunghezza di tale sottosequenza) && 
(!ok=>A[im]>A[i2] && a è la lunghezza della sottosequenza 
crescente con inizio in A[i1] e fine in A[i2-1]) && i2<dim)

POST2=((!ok && i2<dim =>i1 è l'inizio di una sottosequenza crescente,
0<=i1<i2 && per ogni A[i1],A[i1+1]..A[i2-1] si ha 
A[i1]<A[i1+1]<..<A[i2-1] && a è la lunghezza di tale sottosequenza)&& 
(ok && i2=dim=>i1 è l'inizio di una sottosequenza crescente,
0<=i1<i2 && per ogni A[i1],A[i1+1]..A[dim-1] si ha
A[i1]<A[i1+1]<..<A[dim-1] && a è la lunghezza di tale sottosequenza))

POST1=(Il file output2.txt contiene la coppia di indici,ini e fin,
che rappresentano rispettivamente l'indice di inizio e di fine 
della sottosequenza crescente massima trovata nell'array A)

CORRETTEZZA (R2,POST2):

invarianza:se A[im]<=A[i2] =>anche A[im] fa parte della sottosequenza
con inizio in A[i1] e tale che A[im-1]<A[im],incremento im,i2 ed a 
quindi ancora si ha A[i1]<A[i1+1]<..<A[im-1] ed a è la lunghezza di 
tale sottosequenza && ok && i2<dim => vale ancora R 

caso di uscita:-A[im]>A[i2] =>!ok && la sottosequenza crescente ha 
inizia in A[i1] ed ha lunghezza a =>POST2
-i2=dim => non ci sono più elementi di A da confrontare poichè sono 
arrivato alla fine dell'array,la sottosequenza inizia in A[i1], ha 
lunghezza a e finisce in A[dim-1] =>POST2

CORRETTEZZA (R1,POST1):

invarianza: i2<dim && se a è maggiore di max => max=a è la nuova 
lunghezza della massima sottosequenza trovata in A[0..i2-1] e ini e
fin vengono aggiornati ai nuovi indici di inizio e fine (i1 ed i2-1 
sono ottenuti da POST2) della nuova sottosequenza crescente massima 
trovata in A[0..i2-1] => vale ancora R1 

caso di uscita: i2=dim => max è ancora la lunghezza della massima 
sottosequenza trovata in A[0..dim-1] && ini e fin sono gli indici di
inizio e di fine della sottosequenza crescente massima trovata in 
A[0..dim-1] =>vale POST1
*/