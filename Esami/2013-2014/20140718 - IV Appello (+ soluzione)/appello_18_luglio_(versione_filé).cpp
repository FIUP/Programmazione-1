#include<iostream>
#include<fstream>
using namespace std;

// ********************ITERATIVA***************

void allunga(int* & X, int & dim)
{
    int* K=new int[dim+20];
    for(int i=0; i<dim; i++)
    {
        K[i]=X[i];
    }
    delete [] X;
    X=K;
    dim=dim+20;
}

int conta_l(int* C, int i)
{
    int cont=0;
    while(C[i]!=-1)
    {
        cont++;
        i++;
    }
    return cont;
}

int * IC(int* C, int & lim)
{
    int* X=new int [20];
    int dim=20, pos_x=0, pos_c=0;
    while(C[pos_c]!=-2)
    {
        if(lim*2>=dim)
        {
            allunga(X, dim);
        }
        int lung=conta_l(C, pos_c);
        X[pos_x]=pos_c;
        pos_x++;
        X[pos_x]=lung;
        pos_x++;
        pos_c=pos_c+lung+1;
        lim++;
    }
    return X;
}

// ******************************RICORSIVA***************


bool confronta(int* C, int* X, int l, int c, int d)// l è sempre la sequenza più lunga, c sempre quella più corta
{
    if(d==X[2*c+1])
      return true;
    if(C[X[2*l]+d]!=C[X[2*c]+d])
       return false;
    return confronta(C, X, l, c, d+1);
}

void M1(int* C, int* X, int j, int y, int lim, int* Z)
{
    int d=0;
    if(y<lim)
    {
        if(X[j*2+1]>X[y*2+1])//solo il caso in cui y è contenuta in j
        {
            if(confronta(C, X, j, y, d))
                {
                    Z[j]++;
                }
        }
        else if(X[j*2+1]==X[y*2+1])//solo il caso in cui j include y e viceversa
        {
            if(confronta(C, X, j, y, d))
            {
                Z[j]++;
                Z[y]++;
            }
        }
        else
        {
            if(confronta(C, X, y, j, d))//controllo solo se y può includere j
            {
                Z[y]++;
            }
        }
        M1(C, X, j, y+1, lim, Z);
    }
}

void M(int*C, int*X, int lim, int j, int *Z)
{
    if(j>=lim-1)
        return;
    M1(C, X, j, j+1, lim, Z);//j è la prima sequenza, j+1 e la sequenza che sta sempre a destra di quella esaminata
    M(C, X, lim, j+1, Z);
}

main()
{
  try{
  ifstream INP("input");
  ofstream OUT("output");
  if(!INP) throw(0);
  if(!OUT) throw(1);
  int C[200];
  int x=0, lim=0;
  for(int i=0; x!=-2; i++)
   {INP>>x; C[i]=x;}

  int* X=IC(C,lim);
  for(int i=0; i<lim; i++)
  OUT<<X[i*2]<<' '<<X[i*2+1]<<endl;

  int *Z=new int[lim];
  for(int i=0; i<lim; i++)
   Z[i]=0;
  M(C,X,lim,0,Z);
  for(int i=0; i<lim; i++)
   OUT<<Z[i]<<' ';

  OUT<<endl;

 }
 catch(int x)
{
   switch(x)
  {
   case 0: cout<<"problemi con input"<<endl; break;
   case 1: cout<<"problemi con output"<<endl; break;
  }
}
}