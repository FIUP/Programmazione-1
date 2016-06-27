#include<iostream>
using namespace std;
main()
{
int somma=0,x;
bool test=true;
while(test)
 {
     cin >> x;
     somma= somma+x;
     if(x==0)
     {
        test=false;
     }
 }
 cout<<"somma="<<somma<<endl;
}
