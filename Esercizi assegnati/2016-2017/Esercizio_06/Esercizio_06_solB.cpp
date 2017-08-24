#include<iostream>

using namespace std;

int main() {
    int x,n=0;
    int vitG1=0;
    int vitG2=0;
    char g1,g2;
    cin>>n;
    
    while (x<n){
        cin>>g1>>g2;
        if ((g1=='f' && g2=='c') || (g1=='s' && g2=='f') || (g1=='c' && g2=='s'))
          vitG1++;
        else if (g1!=g2)
          vitG2++;
        x++;
        
    }
    
    if (vitG1==vitG2)
        cout<<"pareggio"<<endl;
    else if (vitG1>vitG2)
        cout<<"Vince il Giocatore 1"<<endl;
    else cout<<"Vince il Giocatore 2"<<endl;
    
  
    
    cout << "end" << endl;
}