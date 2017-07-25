/* Il programma deve leggere dei valori interi dal file "input" rispettando il
   seguente vincolo: deve leggere al piu' dieci valori, ma deve fermarsi qualora
   legga due 0 contigui. Il file "input" contiene almeno due interi. Inoltre la
   sentinella deve esserci obbligatoriamente se ci sono meno di dieci interi nel
   file "Input" da scrivere su "output". Per ogni lettura del valore v, il
   programma deve stampare su "output" v, solo a condizione che esso non
   appartenga alla sentinella (i due 0). In nessun caso il programma deve
   eseguire piu' di dieci letture. */

#include<fstream>
using namespace std;

main()
{
  ifstream input("input");
  ofstream output("output");
  int v, i=0;
  bool o=false, oo=false;
  
  // PRE
  while (i<10 && !oo) {     // R
    input >> v;
    i++;

    if (v==0)
      if (o) oo=true; else o=true;
    else {
      if (o) {
	output << 0 << ' ';
	o=false;
      }
      output << v << ' ';
    }
  }

  if (o && !oo) output << 0;
  // POST

  output.close();
  input.close();
}

/*  Nota: s=v1..vk e' la sequenza di interi contenuta in "input". Se k>=10 e
          v1..v10 non contiene due 0 contigui, allora prefix(s) indica v1..v10.
          Se v1..vk (con 2<=k<=10) contiene due zeri contigui (supponiamo essi
          siano v(j-1) e vj), allora prefix(s) indica v1..v(j-2).
          Se j=1 allora prefix(s) e' una sequenza vuota di valori.

    PRE = (Il file "input" contiene una sequenza v1..vk di interi)&&((k>=10)||
          ||((vk=v(k-1)=0)&&(k>=2))
   POST = (output=prefix(s))
      R = (0<=i<=10, con i che indica il numero di interi letti (v1..vi))&&
          &&((o && oo)=>(vi=v(i-1)=0)&&(output=v1..v(i-2)))&&((o && !oo)=>
          =>(vi=0)&&(output=v1..v(i-1)))&&((!o && !oo)=>(output=v1..vi))

   CORRETTEZZA:
   1) R e' verificata la prima volta?
      i=0 (per inizializzazione) => 0<=0<=10
      Non e' stato letto alcun carattere, ed infatti, essendo i=0, non ha senso
      parlare di v1..vi.
      Abbiamo che o=oo=false (per inizializzazione), e si dovrebbe dunque avere
      che output=v1..v0. Ma v1..v0 e' una sequenza vuota, ed infatti su output
      non e' stato scritto nulla.
   2) R && B (B=condizione di permanenza) <C> => R?
      R && B = (0<=i<10)&&(letti v1..vi interi da input)&&((o && !oo)=>(vi=0)&&
      &&(output=v1..v(i-1)))&&((!o && !oo)=>(output=v1..vi))
      Eseguiamo ora una volta il corpo <C> del ciclo.
      Viene letto l'(i+1)-esimo intero, e poi, giustamente, i viene incrementato.
      Quindi vale di nuovo che i rappresenta il numero di numeri letti da input.
      Ora il programma si divide in 3 casi, esaminiamoli.
      A) v(i+1)=0
         A.1) o=true
              Se o=true (e sappiamo che oo=false) per ipotesi abbiamo che v(i-1)=0.
              Viene eseguita l'istruzione oo=true. Qui il ciclo termina. R e'
              verificata nuovamente? Si. Si ha infatti che 0<=i+1<=10 e che sono
              stati letti i+1 caratteri (v1..v(i+1)).
              Inoltre eravamo partiti con l'ipotesi che o=true e che oo=false.
              Quindi, sempre per ipotesi, output=v1..v(i-1). Ora pero' i e'
              stato incremenato e oo e' diventato true. Nulla e' stato scritto
              su output. Quindi si ha che output=v1..v(i-2) (a causa
              dell'incremento di i). Ma e' esattamente quello che volevamo
              trovare. Infatti R afferma che (o && oo)=> (v(i)=v(i-1)=0)&&
              &&(output=v1..v(i-2))
         A.2) o=false
              Sappiamo che anche oo=false (per ipotesi). Sempre per ipotesi
              sappiamo che (o=oo=false)=>(output=v1..v(i-1)) (si ricordi che i e'
              stata incrementata). Viene eseguita l'istruzione i=true, e basta.
              R e' verificata? Si, infatti, a causa dell'incremento di i, si ha
              che e' verificata la condizione (o && !oo)=>((vi=0)&&(output=
              =v1..v(i-1))
      B) v(i+1)!=0
         Per ipotesi oo=false. Se o=true significa (sempre per ipotesi) che vi=0.
         Tuttavia v(i+1)!=0, quindi vi non apparteneva alla sentinella. Quindi si
         pone o=false. Inoltre si scrive su output (ricordiamo che, per ipotesi,
         output=v1..v(i-2), a causa dell'incremento di i) il valore v(i-1), che e'
         appunto 0 (lo si ha sempre per ipotesi, essendo stato che o=true).
         Quindi ora output=v1..v(i-1).
         Ma dopo il condizionale c'e' un ulteriore istruzione, che scrive su output
         l'intero vi. Quindi output=v1..vi.
         Effettivamente questo verifica R. Infatti R afferma (!o && !oo)=>output=
         =v1..vi
   3) R && !B => POST?
      Ci sono vari casi da discutere:
      A) i=10 && oo=false
         A.1) o=true
              R afferma che (o && !oo) => (output=v1..v9)&&(v10=0)
              Ma dopo il ciclo while c'e' un ulteriore condizione: se o=true e
              oo=false (ed effettivamente e' cosi') allora scrivi su output il
              valore 0 (che e' proprio v10). Abbiamo ottenuto POST
         A.2) o=false
              R afferma che (!o && !oo) => (output=v1..v10).
              Esattamente POST
      B) i<10 && oo=true
         o puo' essere solo true.
         R afferma che (o && oo)=>(output=v1..v(i-2))
         Come volevasi dimostrare.
      C) i=10 && oo=true
         Si ha che o=true. Caso identico al precedente. Abbiamo ottenuto POST */
