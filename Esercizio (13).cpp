#include<iostream>
using namespace std;

main()
{
  int A[6][8];
  bool B[6][8];

  for(int i=0;i<6;i=i+1)    //R1=(0<=i<=6) &&(lette le prime 0..i-1 righe)
     for(int j=0; j<8; j=j+1)   //R2=(0<=j<=8)&&(letti i primi 0..j-1 elementi della riga i)
       cin>>A[i][j];

       // il punto (3) del testo
       for(int i=0; i<6; i=i+1)
         for(int j=0; j<8; j=j+1) // scorriamo ciascun elemento di B
         {
              //i e j individuano un elemento di B e quindi in questo corpo devo scrivere istruzioni che calcolino se devo inserire true o false
         bool ok=true;
          for(int z=0;z<8 && ok; z=z+1)
          {
             ok=false;
             //A[i][z] e' il prossimo elemento per cui verificare se e' presente nella colonna j
             for(int k=0;k<6 && !ok; k++)
             {
              if(A[i][z]==A[k][j])
                  ok=true;
             }
              //trovato sse A[i][z] e' stato trovato nella colonna j
          }
         //POST=(ok sse A[i] e' nella colonna j)

        if(ok)
          B[i][j]=true;
             else
               B[i][j]=false;
         }

    for(int i=0;i<6;i=i+1)//R1=(0<=i<=6) &&(lette le prime 0..i-1 righe)
     {
     for(int j=0; j<8; j=j+1)   //R2=(0<=j<=8)&&(letti i primi 0..j-1 elementi della riga i)
       {
           cout<<B[i][j] << " ";
       }
       cout << endl;
     }
}
