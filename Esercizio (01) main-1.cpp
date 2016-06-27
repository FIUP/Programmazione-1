#include<iostream>
using namespace std;

//1 PRE=(cin contiene almeno 10 interi)
main()
{
 int i=0, somma=0,x;
 while(i<10)
 {
     cin >> x;
     somma= somma+x;
     i++;
 }
 cout<<"somma="<<somma<<endl;
}
//POST=(letti 10 interi da cin e somma e' la loro somma)
