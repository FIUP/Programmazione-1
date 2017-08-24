// soluzione di B.Cosentino
#include<iostream>
using namespace std;

// PRE = (L va visto come L[dim][dim], definita, 0<=i<=dim-1 e j in -1...dim)
bool trova_lab(int L[], int dim, int i, int j){
    
    if (*(L+i*dim+j)==0 || j<0 || j>=dim)
        return false;
    
    // L[i][j]==1 & 0<=i<=dim-1 & 0<=j<dim
        
    if (i==dim-1)
        return true;
    
    // L[i][j]==1 & 0<=i<dim-1 & 0<=j<dim
    
    // PRE_ric1 = (L va visto come L[dim][dim], definito, i+1<=dim-1 e j-1 in -1...dim-2)
    // PRE_ric2 = (L va visto come L[dim][dim], definito, i+1<=dim-1 e j in 0...dim-1)
    // PRE_ric3 = (L va visto come L[dim][dim], definita, i+1<=dim-1 e j+1 in 1...dim)
    return (trova_lab(L,dim,i+1,j-1) || trova_lab(L,dim,i+1,j) || trova_lab(L,dim,i+1,j+1));
    // POST_ric1 = (restituisce true sse esiste un cammino bianco dalla casella (i+1,j-1) alla riga dim-1)
    // POST_ric2 = (restituisce true sse esiste un cammino bianco dalla casella (i+1,j) alla riga dim-1)
    // POST_ric3 = (restituisce true sse esiste un cammino bianco dalla casella (i+1,j+1) alla riga dim-1)
}
// POST=(restituisce true sse esiste un cammino bianco dalla casella (i,j) alla riga n-1)

/****************************************************
DIMOSTRAZIONE

Casi base:
    1) Se L[i][j] == 0 oppure sono uscito dai bordi laterali dell'array (j<0 || j>=dim) allora non e' possibile trovare un cammino -> 
        -> restituisco false -> POST valida
    
    2) Se non sono nel primo caso allora so che L[i][j]==1 & 0<=i<=dim-1 & 0<=j<dim, ovvero mi trovo dentro l'array L e L[i][j]==1.
        Se i==dim-1, allora L[i][j] appartiene all'ultima riga dell'array e, quindi, esiste un cammino dalla riga i all'ultima ->
        -> restituisco true -> POST valida

Caso induttivo:
    
    Se mi trovo nel caso induttivo so che L[i][j]==1 & 0<=i<dim-1 & 0<=j<dim
    Quindi, cerco l'array nelle tre posizioni adiacenti della riga i+1, ovvero le posizioni j-1, j, j+1.
    
    0<=i<dim-1 -> 1<=i+1<dim -> 0<=i+1<=dim-1
    
    0<=j<dim -> 0<=j<=dim-1 ->  1) -1<=j-1<=dim-2
                                2) 0<=j<=dim-1
                                3) 1<=j+1<=dim

    Quindi, valgono:
        1) 0<=i+1<=dim-1 & -1<=j-1<=dim-2 -> PRE_ric1
        2) 0<=i+1<=dim-1 & 0<=j<=dim-1 -> PRE_ric2
        3) 0<=i+1<=dim-1 & 1<=j+1<=dim -> PRE_ric3
        
    Quindi, dato che le tre PRE_ric sono vere allora sono vere anche le POST_ric -> 
    -> trova_lab(L,dim,i+1,j-1) || trova_lab(L,dim,i+1,j) || trova_lab(L,dim,i+1,j+1) e' uguale a true sse esiste un labirinto a partire da una delle celle (i+1,j+1), (i+1,j) oppure (i+1,j+1)
    Inoltre, so che L[i,j] == 1. Per cui esiste un cammino a partire dalla cella (i,j) sse esiste un cammino a partire dalle suddette celle ->
    -> POST valida
    
****************************************************/

// PRE = L[dim][dim] e' un array con elementi interi uguali a 0 o 1 & dim >= 0 intero
bool trova(int L[], int dim){
    
    bool trovato=false;
    
    // PRE_for = PRE & trovato=false & i=0
    for (int i=0; i<dim && !trovato; i+=1)
    // R_for = (0<=i<=dim) & (trovato==true sse esiste in L[0][0...i-1] un elemento uguale a 1 da cui parte un cammino fino all'ultima riga dell'array L[dim][dim])
        trovato = (*(L+i)==1) && trova_lab(L,dim,0,i);
    //POST_for = trovato==true sse esiste un elemento della riga 0 dell'array uguale a 1 da cui parte un cammino dalla prima all'ultima riga di L[dim][dim]
    
    return trovato;
}
// POST = (restituisce true sse esiste un cammino dalla prima all’ultima riga di L[dim][dim])


/****************************************************
DIMOSTRAZIONE

PRE <bool trovato=false> PRE_for :  L[dim][dim] e' un array con elementi interi uguali a 0 o 1 & dim >= 0 intero
                                    eseguo bool trovato=false 
                                    Quindi, PRE & trovato=false e' valida. Prima del ciclo for avro' i=0 -> PRE_for
    
PRE_for -> R_for : PRE & trovato=false & i=0 -> (0<=i<=dim) & (trovato==true sse L[0][0...-1] un elemento uguale a 1 da cui parte un cammino fino all'ultima riga dell'array L[dim][dim]) ->
                    -> R_for valida

R_for & B <C> R_for : (0<=i<=dim) & (trovato==true sse esiste in L[0][0...i-1] un elemento uguale a 1 da cui parte un cammino fino all'ultima riga dell'array L[dim][dim]) & 
                    & (i<dim) & (trovato==false) -> 
                    -> (0<=i<dim) & (non esiste in L[0][0...i-1] un elemento uguale a 1 da cui parte un cammino fino all'ultima riga dell'array L[dim][dim])
                    <C>
                    2 casi:
                        1) se L[0][i]!=1 allora non esiste un cammino a partire da lui e pongo trovato=false -> 
                            -> (non esiste in L[0][0...i] un elemento uguale a 1 da cui parte un cammino fino all'ultima riga dell'array L[dim][dim])
                    
                        2) se L[0][i]==1 allora bisogna controllare se da lui parte un cammino.
                            trova_lab(L,dim,0,i)==true sse esiste un cammino dalla casella (0,i) alla riga n-1.
                            trovato = (*(L+i)==1) && trova_lab(L,dim,0,i) = trova_lab(L,dim,0,i)
                            Se trova_lab(L,dim,0,i) == false , allora non esiste un cammino a partire da L[0][i]
                            Se trova_lab(L,dim,0,i) == true , allora esiste un cammino e parte da L[0][i]
                            Quindi, trovato == true sse L[0][i]==1 e esiste un cammino a partire da lui -> 
                            -> trovato == true sse esiste in L[0][0...i] un elemento uguale a 1 da cui parte un cammino fino all'ultima riga dell'array L[dim][dim])
                    
                    Infine, i viene incrementato e avro' 0<=i<=dim & 
                    & trovato == true sse esiste in L[0][0...i-1] un elemento uguale a 1 da cui parte un cammino fino all'ultima riga dell'array L[dim][dim]) -> R_for valida
                    
R_for & !B -> POST_for : (0<=i<=dim) & (trovato==true sse esiste in L[0][0...i-1] un elemento uguale a 1 da cui parte un cammino fino all'ultima riga dell'array L[dim][dim]) & 
                        & (i>=dim || trovato==true) ->
                        -> 2 casi:
                            1) (0<=i<=dim) & (trovato==true sse esiste in L[0][0...i-1] un elemento uguale a 1 da cui parte un cammino fino all'ultima riga dell'array L[dim][dim]) & 
                            & (i>=dim) ->
                            -> (i=dim) & (trovato==true sse esiste in L[0][0...dim-1] un elemento uguale a 1 da cui parte un cammino fino all'ultima riga dell'array L[dim][dim]) ->
                            -> POST_for valida
                            2) (0<=i<=dim) & (trovato==true sse esiste in L[0][0...i-1] un elemento uguale a 1 da cui parte un cammino fino all'ultima riga dell'array L[dim][dim]) & 
                            & (trovato==true) -> esiste in L[0][0...i-1] un elemento uguale a 1 da cui parte un cammino fino all'ultima riga dell'array L[dim][dim] ->
                            -> esiste in L[0][0...dim-1] un elemento uguale a 1 da cui parte un cammino fino all'ultima riga dell'array L[dim][dim] & trovato==true ->
                            -> POST_for valida

POST_for <return trovato> POST : ovvia

****************************************************/
main()
{
  int n;
  cin>>n;
  int L[n*n];
  for(int i=0; i<n*n; i++)
          cin>>L[i];
  bool x=trova(L, n);
  if(x)
    cout<<"il cammino esiste"<<endl;
  else
    cout<<"il cammino non esiste"<<endl;

}
