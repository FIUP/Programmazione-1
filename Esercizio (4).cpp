#include<iostream>
using namespace std;
main()
{
int max, min,x,i=0;
bool test=true;
while(test)
 {
     cin >> x;
     if(x==0)
     {
        test=false;
     }
     if(i==0)
     {
         min=x;
         max=x;
     }
     if(x>max && x!=0)
     {
        max=x;
     }
     if(x<min && x!=0)
     {
         min=x;
     }

     i++;
 }
 if(i==1)
 {
    cout<<"non ci sono valori da leggere"<<endl;
 }else
 {
    cout<<"min="<<min<<" max="<<max<<endl;
 }
}
