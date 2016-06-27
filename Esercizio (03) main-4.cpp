#include<iostream>
using namespace std;
main()
{
int sommap=0,somman=0,x;
bool test=true;
while(test)
 {
     cin >> x;
     if(x<0)
     {
         somman++;
     }
     if(x>0){
         sommap++;
     }
     if(x==0)
     {
        test=false;
     }
 }
 cout<<"pos="<<sommap<<endl;
 cout<<"neg="<<somman<<endl;
}
