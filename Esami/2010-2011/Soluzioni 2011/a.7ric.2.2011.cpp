#include<iostream>
using namespace std;

void stampa(int inizio,int*M,int lim)
{ if(inizio<lim)
	{cout<<M[inizio]<<" ";
	 stampa(inizio+1,M,lim);
	}

}


void Gric(int k,int *M,int index, int count)
{int x;
 cin>>x;
  if(x!=-2)
	{ if(index==k)
			index=0;
	  M[index]=x;
      Gric(k, M,index+1,count+1); 
	}
  else
	{if(count>k)
		stampa(index,M,k);
	 stampa(0,M,index);
	}
}

main()
{
	 int *M=new int[6];
	Gric(6, M, 0, 0);


}
