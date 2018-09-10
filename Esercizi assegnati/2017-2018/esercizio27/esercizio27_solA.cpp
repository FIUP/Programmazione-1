//Soluzione di S.Righetto

#include<iostream>
using namespace std;

int sott(int*A, int i,int l,int dimA){
    if(A[i]<A[i+1] && (i+1)<dimA) {
        l++;
        sott(A,i+1,l,dimA);
        }
    else return l; 
    }

void F(int *A, int dimA, int i,  int &iniz, int &lung){
    int l=1, in=0;
    if(i<dimA){

       l=sott(A,i,l,dimA);
        if((l)>lung){
            lung=l;
            iniz=i;
            }
    F(A, dimA, i+1, iniz, lung);    
    }
    
}

main()
{
  int dimA, A[100];
  cin>> dimA;
  for(int i=0; i<dimA; i++)
    cin>>A[i];
  int inizio=0, lunghezza=0;
  F(A,dimA,0,inizio,lunghezza);
  cout<<"start"<<endl;
  cout<<"la sottoseq crescente piu' lunga inizia in "<< inizio<<" ed ha lunghezza "<<lunghezza<<endl;
  cout<<"end"<<endl;
}
