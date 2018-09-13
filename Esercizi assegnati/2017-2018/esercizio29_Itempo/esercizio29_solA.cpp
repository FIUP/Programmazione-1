//Soluzione di S.Righetto

#include<iostream>
using namespace std;

bool F(int*X,int dimX,int*P,int dimP,int& lim1,int lim2,int lim3){
    int h=0,cont=0;
    bool c=false;
    while(h<nX){
        for(int x=0; x<nP; x++){
            if(X[h+x]==P[x]){
                cont++;
            }
        }
        if( cont==nP && (h/(lim2*lim3))==((h+nP-1)/(lim2*lim3)) ){
            c=true;
            lim1=h/(lim2*lim3);
            h=nX;
        }
        cont=0;
        h++;
        if(h>(lim1*lim2*lim3)-1)
            h=nX;
    }
    return c;
}

int main()
{
  int X[400], n_ele, nP, P[20];
  cin>> n_ele;
  for(int i=0; i<n_ele; i++)
    cin >> X[i];
  int lim1,lim2,lim3;
  cin>> lim1>>lim2>>lim3;
  cin >> nP;
  for(int i=0; i<nP; i++)
    cin>>P[i];
  cout<<"start"<<endl;
  bool cond;
  cond=F(X,n_ele,P,nP,lim1,lim2,lim3);
  if(cond==true)
    cout<<"lo strato "<<lim1<<" di T contiene un match"<<endl;
    else
    cout<<"nessun match trovato"<<endl;
  cout<<"end"<<endl;
}

