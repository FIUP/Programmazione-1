#include <iostream>
using namespace std;
void cancella(int *, int *, int, int &);
bool G(int *, int &, int, int*, int);
//PRE: A è definito, top>=0, y è un intero
void F(int *A, int & top, int y){
	int quanti=0;
	const int p=top;
	int dove[p];
	if(G(A, quanti, y, dove, top)) 
	  cancella(dove, A, quanti, top);
}
//POST: top, tale che A[0..top-1] è ordinato, non contiene alcun y e contiene tutti
//gli elementi di vA[0..vtop-1] che sono diversi da y

//PRE: A è definito, top>=0, y è un intero
bool G(int *A, int &quanti, int y, int *dove, int top){
	bool trovato=false;
	for(int i=0; i < top&&A[i]<=y; i++)	//R: 0<=i<=top,  quanti è il numero di y in A[0..i-1], b in [0..quanti-1] t.c. dove[b] è uguale alla posizione dove è stato trovato y, trovato sse esiste almeno un a in[0..top-1] t.c. A[a] = y.
		if(A[i]==y)
		{	dove[quanti]=i;
			trovato=true;
			quanti++;
		}
	return trovato;
}
//POST: quanti è il numero di y in A[0..top-1], b in [0..quanti-1] t.c. dove[b] è uguale alla posizione dove è stato trovato y, trovato sse esiste almeno un a in[0..top-1] t.c. A[a] = y.
//PRE: dove[0..quanti-1] è definito, quanti >0, A è definito
void cancella(int *dove, int *A, int quanti, int &top){
	int a=0;
	for(int i=quanti-1;i>=0;i--){	//R1: (quanti-1)<=i<=-1, z=dove[i-1],0<=a<=quanti-1, top= vtop-a
		int z=dove[i];
		int a++;
		for(int j=z; j<top-1;j++)	//R2: z<=j<=top-1, per ogni a in [z..j-1] A[a]=A[a+1]
			A[j]=A[j+1];			//POST2: per ogni a in [z..top-1] A[a]=A[a+1]		
		top--;
	}//POST1: top=vtop-quanti
}
//POST: top, tale che A[0..top-1] è ordinato, non contiene alcun y e contiene tutti
//gli elementi di vA[0..vtop-1] che sono diversi da y
main()
{int top=10, y;
int A[10]={1,3,4,5,5,6,8,8,8,8};  //vA=10, vtop=10
cin >> y;
F(A, top, y);
for(int i=0; i<top; i++)
	cout << A[i] << " ";

}
