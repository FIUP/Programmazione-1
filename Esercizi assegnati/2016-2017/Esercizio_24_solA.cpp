// soluzione di B.Cosentino
#include<iostream>
using namespace std;

main() {
  
  int A[3][4][5];
  for(int i=0; i<3; i=i+1)
    for(int j=0; j<4; j=j+1)
      for(int k=0; k<5; k=k+1)
       cin >> A[i][j][k];
  
  cout<<"start"<<endl;
  char c;
  int f;
  cin >> c >> f;
  if(c=='H'){
    // PRE1 = (0<=f<=3) & (i=0)
	for (int i=0; i<3; i=i+1){
	// R1 = (0<=i<=3) & (ho stampato gli strati da 0 a i-1 della H-fetta f)
	    // PRE2 = (0<=f<=3) & (i fissato) & (j=0)
      	for (int j=0; j<5; j=j+1)
      	// R2= (0<=j<=5) & (ho stampato gli elementi dello strato i della H-fetta f da 0 a j-1)
      		cout << A[i][f][j] << " ";
      	// POST2 = (ho stampato tutti gli elementi dello strato i della H-fetta f)
      	cout << endl;
    }
    // POST1 = (ho stampato tutti gli strati della H-fetta f)
  } else {
	for (int i=0; i<3; i=i+1){
	// R3 = (0<=i<=3) & (ho stampato gli strati da 0 a i-1 della V-fetta f)
		for (int j=0; j<4 ; j=j+1)
		// R4 = (0<=j<=4) & (ho stampato gli elementi dello strato i della V-fetta f da 0 a j-1)
			cout << A[i][j][f] << " ";
		// POST4 = (ho stampato tutti gli elementi dello strato i della V-fetta f)
		cout << endl;
	}
	// POST3 = (ho stampato tutti gli strati della V-fetta f)
  }
  cout<<"end"<<endl;
}



// PRE1 -> R1 : (0<=f<=3) & (i=0) -> (ho stampato gli strati da 0 a -1 della H-fetta f) -> R1 valida

// R1 & condperm -> R1 : (0<=i<=3) & (ho stampato gli strati da 0 a i-1 della H-fetta f) & (i<3) -> (ho stampato gli strati da 0 a i-1 della H-fetta f) & (i<3)
//                      <C>
//                      Alla fine del ciclo for_2 vale POST2. Quindi, sono stati stampati tutti gli elementi dello strato i della H-fetta f.
//                      Quindi, vale (ho stampato gli strati da 0 a i della H-fetta f).
//                      Infine viene incrementato i -> R1 valida

// R1 & !condperm -> POST1 : (0<=i<=3) & (ho stampato gli strati da 0 a i-1 della H-fetta f) & (i>=3) -> (i=3) & (ho stampato gli strati da 0 a 2 della H-fetta f) ->
//                          -> (ho stampato tutti gli strati della H-fetta f) = POST1

// PRE2 -> R2 : (0<=f<=3) & (i fissato) & (j=0) -> (ho stampato gli elementi dello strato i della H-fetta f da 0 a -1) -> R2 valida

// R2 & condperm -> R2 : (0<=j<=5) & (ho stampato gli elementi dello strato i della H-fetta f da 0 a j-1) & (j<5) ->
//                      -> (ho stampato gli elementi dello strato i della H-fetta f da 0 a j-1) & (j<5).
//                      <C>
//                      Stampo l'elemento j dello strato i della H-fetta f.
//                      Quindi, vale (ho stampato gli elementi dello strato i della H-fetta f da 0 a j).
//                      Infine, viene incrementato j -> R2.

// R2 & !condperm -> POST2 : (0<=j<=5) & (ho stampato gli elementi dello strato i della H-fetta f da 0 a j-1) & (j>=5) ->
//                          -> (j=5) & (ho stampato gli elementi dello strato i della H-fetta f da 0 a 4) -> 
//                          -> (ho stampato tutti gli elementi dello strato i della H-fetta f) = POST2

// PRE3 -> R3 : (0<=f<=3) & (i=0) -> (ho stampato gli strati da 0 a -1 della V-fetta f) -> R1 valida

// R3 & condperm -> R3 : (0<=i<=3) & (ho stampato gli strati da 0 a i-1 della V-fetta f) & (i<3) -> (ho stampato gli strati da 0 a i-1 della V-fetta f) & (i<3)
//                      <C>
//                      Alla fine del ciclo for_4 vale POST4. Quindi, sono stati stampati tutti gli elementi dello strato i della V-fetta f.
//                      Quindi, vale (ho stampato gli strati da 0 a i della V-fetta f).
//                      Infine viene incrementato i -> R3 valida

// R3 & !condperm -> POST3 : (0<=i<=3) & (ho stampato gli strati da 0 a i-1 della V-fetta f) & (i>=3) -> (i=3) & (ho stampato gli strati da 0 a 2 della V-fetta f) ->
//                          -> (ho stampato tutti gli strati della V-fetta f) = POST3

// PRE4 -> R4 : (0<=f<=3) & (i fissato) & (j=0) -> (ho stampato gli elementi dello strato i della V-fetta f da 0 a -1) -> R4 valida

// R4 & condperm -> R4 : (0<=j<=5) & (ho stampato gli elementi dello strato i della V-fetta f da 0 a j-1) & (j<5) ->
//                      -> (ho stampato gli elementi dello strato i della V-fetta f da 0 a j-1) & (j<5).
//                      <C>
//                      Stampo l'elemento j dello strato i della V-fetta f.
//                      Quindi, vale (ho stampato gli elementi dello strato i della V-fetta f da 0 a j).
//                      Infine, viene incrementato j -> R4.

// R4 & !condperm -> POST4 : (0<=j<=5) & (ho stampato gli elementi dello strato i della V-fetta f da 0 a j-1) & (j>=5) ->
//                          -> (j=5) & (ho stampato gli elementi dello strato i della V-fetta f da 0 a 4) -> 
//                          -> (ho stampato tutti gli elementi dello strato i della V-fetta f) = POST4
