//Soluzione di S.Righetto

#include<iostream>
using namespace std;
main()
{
    cout<<"start"<<endl;
    int M[6][6];
    for(int i=0; i<6; i++)
        for(int j=0; j<6; j++)
        cin>>M[i][j];
        //resto da fare
    
    int cons=0,sum=0;
    bool b=true;
    for(int i=0; i<6; i++)   //diagonale 
        cons += M[i][i];
    for(int i=0; i<6 && b; i++){
        for(int j=0; j<6; j++)    
        sum += M[j][i];
		if(sum!=cons)
		    b=false;
		sum=0;    
    }
    for(int i=0; i<6 && b; i++){
        for(int j=0; j<6; j++)    
        sum+= M[i][j];
		if(sum!=cons)
		    b=false;
		sum=0;    
    }
    for(int i=0; i<6; i++) //diagonale
        sum+= M[i][5-i];
    if(sum!=cons)
        b=false;
    sum=0; 
    if(b) cout<< cons;
    else cout << "Non e' un quadrato magico";
    cout <<endl << "end";
}
