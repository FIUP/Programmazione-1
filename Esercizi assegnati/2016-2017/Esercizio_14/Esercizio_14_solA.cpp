// soluzione di B.Cosentino
#include<iostream>
using namespace std;
int main()  {
    int A[100], n, x;
    cin >> n;
    for(int i=0; i<n; i=i+1)
        cin >> A[i];
    
    cin >>x;
    int resta=0;
    
    //PRE_for: A contiene n interi && nessun valore di A esaminato && resta=0
    for(int i=0; i<n; i=i+1){   //R_for
        if (A[i]!=x) {
            A[resta]=A[i]; 		// La variabile resta non solo mi dice la nuova dimensione di A, 
            resta=resta+1;		// ma anche l'indice della posizione in A dove inserire il termine A[i]!=x
        }
    }
    /*POST_for: (esaminato A[0..n-1]) && 
    && (la parte A[0..resta-1] contiene i valori della parte esaminata diversi da x nello stesso ordine relativo) 
    && (0<=resta<=n)
    */
    
    n=resta; //nuovo valore di n
    cout<<"n="<<n<<endl;
    
    for(int i=0; i<n; i=i+1)
        cout<< A[i]<<' ';
    
    cout<<endl<<"end"<<endl;
}

// R_for: (esaminato A[0..i-1]) &&
//        && (la parte A[0..resta-1] contiene i valori della parte esaminata diversi da x nello stesso ordine relativo) &&
//        &&(0<=resta<=i) && (0<=i<=n)

// PRE_for -> R_for: A contiene n interi && nessun valore di A esaminato && resta=0 ->
//				-> esaminato A[0...-1] && A[0...-1] contiene valori esaminati diversi da x nello stesso ordine relativo &&
//				&& resta=0 -> R valida

// R_for && condperm -> R_for: (esaminato A[0..i-1]) &&
//       					&& (la parte A[0..resta-1] contiene i valori della parte esaminata diversi da x nello stesso ordine relativo) &&
//        					&&(0<=resta<=i) && (0<=i<=n) && (i<n) ->
//							-> (esaminato A[0..i-1]) &&
//       					&& (la parte A[0..resta-1] contiene i valori della parte esaminata diversi da x nello stesso ordine relativo) &&
//        					&&(0<=resta<=i) && (0<=i<=n) && (i<=n-1) ->
//							-> (esaminato A[0..i-1]) &&
//       					&& (la parte A[0..resta-1] contiene i valori della parte esaminata diversi da x nello stesso ordine relativo) &&
//        					&&(0<=resta<=i) && (i<=n-1)
//                          <C>
//                          Se A[i]==x, allora non viene fatto niente.
//                          Se A[i]!=x, allora A[i] viene copiato in A[resta] e viene incrementato resta.
//                          (esaminato A[0..i]) &&
//                          && (la parte A[0..resta-1] contiene i valori della parte esaminata diversi da x nello stesso ordine relativo) &&
//                          &&(0<=resta<=i) && (0<=i<=n-1)
//                          Alla fine viene incrementato i -> 
//                          -> (esaminato A[0..i-1]) &&
//                          && (la parte A[0..resta-1] contiene i valori della parte esaminata diversi da x nello stesso ordine relativo) &&
//                          &&(0<=resta<=i) && (0<=i<=n) -> R_for valida

// R_for && !condperm -> POST_for: (esaminato A[0..i-1]) &&
//       					 && (la parte A[0..resta-1] contiene i valori della parte esaminata diversi da x nello stesso ordine relativo) &&
//        					 &&(0<=resta<=i) && !(i<n) ->
//						     -> (esaminato A[0..i-1]) &&
//       				     && (la parte A[0..resta-1] contiene i valori della parte esaminata diversi da x nello stesso ordine relativo) &&
//        					 &&(0<=resta<=i) && (0<=i<=n) && (i>=n) ->
//					   	     -> (esaminato A[0..i-1]) &&
//       					 && (la parte A[0..resta-1] contiene i valori della parte esaminata diversi da x nello stesso ordine relativo) &&
//        					 &&(0<=resta<=i) && (i=n) ->
//							 -> (esaminato A[0..n-1]) &&
//       					 && (la parte A[0..resta-1] contiene i valori della parte esaminata diversi da x nello stesso ordine relativo) &&
//        					 &&(0<=resta<=n) -> POST_for valida
