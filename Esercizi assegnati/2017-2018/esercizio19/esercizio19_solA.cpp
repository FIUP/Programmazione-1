//Soluzione di S.Righetto

#include<iostream>
using namespace std;

main()
{
  cout<<"start"<<endl;
  int A[3][4][5], *p=A[0][0], n_ele;
  
  cin>>n_ele;
  for(int i=0; i<n_ele; i=i+1)
    cin>>p[i];
    
  char c;
  int f,sp=n_ele/20 ,righe=(n_ele%20)/5, elem=(n_ele%20)%5;
  cin >> c >> f;
  
    if(sp<3 && (f>righe && c=='H')){
        cout << "fetta richiesta vuota" << endl;}
    else {
  
    if(c=='H' && (f<=3) && (0<=f)){
         //stampa H fetta
         for(int i=0; i<sp; i++){
            for(int j=0; j<5 ; j++){
                cout<<A[i][f][j] << ' ';
                }
            cout << endl;
            }
        if(f <= (righe-1)){
            for(int k=0; k<5; k++)
                cout << A[sp][f][k] << ' ';
            }
        if(f>= righe){
            for(int k=0; k<elem; k++)
                cout << A[sp][f][k] << ' ';
            }
        }
        //stampa V fetta
        if(c=='V' &&(f<=4)&&(0<=f)){
               for(int i=0; i<sp; i++){
                    for(int j=0; j<4 ; j++){
                        cout<<A[i][j][f] << ' ';
                    }
                cout << endl;
                }
            if(sp<3){
                for(int k=0; k<righe; k++)
                    cout << A[sp][k][f] << ' ';
                if(f > elem){
                        cout << A[sp][righe][f] << ' ';
                }
            }
        }
    }
  cout<< endl<<"end"<<endl;
}

