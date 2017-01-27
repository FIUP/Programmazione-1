//Inizio_cam

int prox(int* C, int a)
{
  while(C[a]!=-1)
    {
      a++;
    }
  return a+1;
}

int inizio(int* C, int i)
{
  int cont=0, index=0;
  bool exit=false;
  while(cont<i && !exit)
    {
      index=prox(C, index);
      if(C[index==-2])
	{
	  exit=true;
	}
      else
	cont++;
    }
  if(exit)
    {
      return -2;
    }
  else
    return index;
}

//Ricorsiva

void add_ric(int* C, nodo* &r, ifstream &INP, ofstream &OUT)
{
  if(C[0]==-1)
    {
      if(!r)
	{
	  r=new nodo();
	  INP>>r->info;
	}
      else
	{
	  int x;
	  INP>>x;
	  OUT<<"troppo corto"<<...;
	}
    }
  else
    if(r)
      {
	if(C[0]==0)
	  {
	    add_ric(C+1, r->left, INP, OUT);
	  }
	else
	  {
	    add_ric(C+1, r->right, INP, OUT);
	  }
      }
    else
      {
	int x;
	INP>>x;
	OUT<<"troppo lungo"<<...;
      }
}


//Iterativa

void add_iter(int* C, nodo* &r, ifstream &INP, ofstream &OUT)
{
  if(!r)
    {
      if(C[0]==-1)
	{
	  r=new nodo();
	  INP>>r->info;
	}
      else
	{
	  int x;
	  INP>>x;
	  OUT<<"troppo lungo"<<....;
	}
    }
  else
    {
      nodo* avanti=r, indietro=r;
      int i=0, v=0;
      bool lungo=false;
      while(C[i]!=-1 && !lungo)
	{
	  if(avanti)
	    {
	      if(C[i]==0)
		{
		  indietro=avanti;
		  avanti=avanti->left;
		  v=0;
		}
	      else
		{
		  indietro=avanti;
		  avanti=avanti->right;
		  v=1;
		}
	    }
	  else
	    {
	      lungo=true;
	    }
	  i++;
	}
      if(lungo)
	{
	  int x;
	  INP>>x;
	  OUT<<"troppo lungo"<<...;
	}
      else
	{
	  if(avanti)
	    {
	      int x;
	      INP>>x;
	      OUT<<"troppo corto"<<...;
	    }
	  else
	    {
	      int x;
	      INP>>x;
	      if(!v)
		{
		  indietro->left=new nodo(x);
		}
	      else
		{
		  indietro->right=new nodo(x);
		}
	    }
	}
    }
}