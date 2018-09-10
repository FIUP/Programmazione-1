//Soluzione di S.Righetto

#include<iostream>
using namespace std;

    
void stampaS(int *X, int i, int lim2 , int lim3, int &conta,int n_ele){
    for(int j = 0; j<lim2 && conta<n_ele ; j++){
        cout << 'r' << j << ":";
        for(int k = 0; k<lim3 && conta<n_ele; k++)
        {
            cout<<X[conta] << ' ';
            conta++;
        }
    cout << endl; 
    }
}


main()
{
   int n_ele, lim1,lim2, lim3, X[400];
  cin>>n_ele;
  for(int i=0; i<n_ele; i=i+1)
   cin>>X[i];
  cin>>lim1>>lim2>>lim3;
  cout<<"start"<<endl;
  
  
  int conta = 0;
	for(int i = 0; i<lim1  && conta<n_ele; i++){
		cout <<endl <<"strato" << i << endl:
		stampaS(X, i, lim2, lim3, conta,n_ele);
	} 
  
  
  cout<<endl<<"end"<<endl;
}
