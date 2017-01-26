#include<iostream>
using namespace std;


struct M {int lung, inizioT, inizioP; M(int a=0, int b=-1, int c=-1){lung=a; inizioT=b; inizioP=c;}};

//PRE(T[iT...dimT-1] definito, dimT>=0, P[i...dimP-1] definito, dimP>=0, 0<=i<=dimP, 0<=iT)
int lung_match(int *T, int dimT, int*P, int dimP, int i, int iT)
{
  if(i==dimP)
    return 0;

  if(iT==dimT)
    return 0;

  if(T[iT]==P[i])
    return 1+lung_match(T, dimT, P, dimP, i+1, iT+1);

  return 0;
}
//PRE(restituisce la lunghezza del match di una porzione(contigua) di P in T[iT...dimT-1])

//PRE(T[iT...dimT-1] def, 0<=dimT, P[i...dimP-1] def, 0<=dimP, 0<=i<=dimP, 0<=iT<=dimT)
M match_T(int *T, int dimT, int *P, int dimP, int i, int iT)
{
  M var(0, -1, -1);

    if(i==dimP)
      return var;

    M max = match_T(T, dimT, P, dimP, i+1, iT);

    int lu = lung_match(T, dimT, P, dimP, i, iT);

    if(lu >= max.lung && lu)
    {
      max.lung=lu;
      max.inizioT=iT;
      max.inizioP=i;
    }
    return max;
}
//POST(restituisce un valore di tipo M)

//PRE=(dimP>0, dimT>=0, T[0..dimT-1] è definita, P[0..dimP-1] è definita, 0<=iT<=dimT)
M match(int*T, int dimT, int*P, int dimP, int iT)
{
  M var(0, -1, -1);

  if(iT==dimT)
    return var;

  M max = match(T, dimT, P, dimP, iT+1);

  M Tmax = match_T(T, dimT, P, dimP, 0, iT);

  if(max.lung<Tmax.lung)
    max=Tmax;
  else
    if(max.lung==Tmax.lung && Tmax.inizioT>max.inizioT)
      max=Tmax;

  return max;
}
//POST=(restituisce un valore di tipo M che rappresenta il massimo match di una porzione di P in T[i..dimT-1],
//in caso di match di lunghezza uguale va ritornato quello che inizia in T dopo gli altri; se non c'è alcun match
//allora la funzione restituisce M=[lung=0, inizioT=-1, inizioP=-1])

main(){
    int T[200]={}, P[20]={}, dimT, dimP;

    cin>>dimT;
    for(int i=0; i<dimT;i++)
        cin>>T[i];

    cin>>dimP;
    for(int i=0; i<dimP;i++)
        cin>>P[i];

    M x = match(T,dimT, P, dimP, 0);

    cout<<"[lung="<<x.lung<<" inizioP="<<x.inizioP<<" inizioT="<<x.inizioT<<']'<<endl;
    cout<<"end"<<endl;
}
