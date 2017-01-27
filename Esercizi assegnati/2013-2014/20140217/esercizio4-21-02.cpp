#include<iostream>
#include<fstream>
using namespace std;
void distribuisci_ceci(int B[][7], int player, int inizio, int ceci);

void inizializza(int B[][7], ifstream & INP)
{
 for(int j=0;j<2;j++)
  {
  for(int i=0; i<7;i++)
    {
    
    INP>>B[j][i];
    cout<<B[j][i]<<' ';
    }
   
  }
}
void stampaO(int B[][7], ofstream & OUT)
{
  cout<<"            player 0"<<endl;
  for(int i=6; i>=0; i--)
   {cout<<" | "<< B[0][i]; OUT<<B[0][i]<<' ';}
  cout<<" |"<<endl<<"    ";
  if(B[0][6]>9)
    cout<<' ';
  for(int i=0; i<7; i++)
   {cout<<" | " <<B[1][i];OUT<<B[1][i]<<' ';}
  cout<<" |"<<endl;
  cout<<"            player 1"<<endl;
}
void stampa(int B[][7])
{
  cout<<"\n            player 0"<<endl;
  for(int i=6; i>=0; i--)
   {cout<<" | "<< B[0][i];}
  cout<<" |"<<endl<<"    ";
  if(B[0][6]>9)
    cout<<' ';
  for(int i=0; i<7; i++)
   {cout<<" | " <<B[1][i];}
  cout<<" |"<<endl;
  cout<<"            player 1"<<endl;
}

int other(int x)
{return (x+1)%2;}

struct coppia{int lato,buca; coppia(int a=0, int b=0){lato=a; buca=b;}};

coppia next(int player, int lato, int buca)
{
  if(buca<5) return coppia(lato,buca+1);
  if(buca==5) 
     if(lato==player) return coppia(lato,6);
      else
       return coppia(other(lato),0);
  if(buca==6) return coppia(other(lato),0);
}
int opposto(int x){return 5-x;}
 
bool semina(int B[][7], int player, int buca, int fagioli)
{
  int lato=player, b=buca, fag=fagioli, x;
  while(fag>0)
   {
    coppia a=next(player,lato,b);
    b=a.buca;
    lato=a.lato;
    
    B[lato][b]++;
    fag--;
   }
  if(b==6) return true;
  if(B[lato][b]==1)
     {stampa(B); cout<<"arraffa su buca "<<b<<" lato= "<<lato<<endl; cin>>x; 
      B[lato][b]=0; B[player][6]+=1+B[other(lato)][opposto(b)]; B[other(lato)][opposto(b)]=0;}
  return false;
}
int raccolta(int B[][7], int player)
{
  int fag=0;
  for(int i=0; i<6; i++)
   fag=fag+B[player][i];
  return fag;
}

void azzera(int B[][7], int player)
{
 for(int i=0; i<6; i++)
   B[player][i]=0;
}
main()
{
  ifstream INP("input");
  ofstream OUT("output");
  int B[2][7];
  inizializza(B,INP);
  stampa(B);
  int player, mossa, fagioli;
  cout<<"player iniziale e mossa ";
  cin>>player>>mossa;
  cout<<"prossimo player="<<player<<endl;
  bool fine=false;
  //questo ciclo gioca una sequenza di mosse che termina con -1 o con la vittoria di un giocatore. Inizia a giocare player. 
  //Le mosse si alternano a meno di ripetizioni.
  while(mossa !=-1 && !fine)
  {
        
       fagioli=B[player][mossa];
       B[player][mossa]=0;
       bool x = semina(B,player, mossa, fagioli);
       stampa(B);
       //stampaO(B,OUT);
       int fag1=raccolta(B,1);
       int fag0=raccolta(B,0);
       if(fag1==0 || fag0==0)
        { 
        
          if(fag0==0) 
            {B[1][6]+=fag1; azzera(B,1);}
          else
            {B[0][6]+=fag0; azzera(B,0);}
          stampa(B);
          //stampaO(B,OUT);
       
         if(B[0][6]>B[1][6])
         cout<<endl<<"ha vinto player 0"<<endl;
         else
          if(B[0][6]<B[1][6])
           cout<<endl<<"ha vinto player 1"<<endl;
            else
             cout<<"PARI"<<endl;
          fine=true;
        }
       else
       {
          if(!x)
             player=other(player);
          cout<<"prossimo player="<<player<<endl;
          cin>>mossa;
        }
      }
  //stampaO(B,OUT);
  INP.close();
  OUT.close();
   
}
/*
void distribuisci_ceci(int B[][7], int player, int inizio, int ceci)
{
  int ceci_rest=ceci, lato=player, fine;
  while(ceci_rest)
   {
    if(lato==player)
      {
        int x=7-inizio;
        if(ceci_rest<=x)
          {fine=inizio+ceci_rest; ceci_rest=0;}
        else
          {ceci_rest=ceci_rest-x; fine=7; lato=other(lato);}
        for(int i=inizio;i<fine;i++)
         B[player][i]++;

      }
    else // lato avversario, non si deve considerare la buca grande
      {
        int x=6;
        if(x>=ceci_rest)
          {fine=ceci_rest;ceci_rest=0;}
        else
           {ceci_rest=ceci_rest-x;fine=6; lato=player; inizio=0;}
        for(int i=0; i<fine; i++)
           B[other(player)][i]++;
      }

    }

}
*/