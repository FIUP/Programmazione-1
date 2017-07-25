/* Realizzare una funzione riorsiva int ins(char *A, int limite) che deve leggere da cin una sequenza di caratteri per inserirli (nello stesso ordine) nell'array A,
   con limite posizioni, fino a che l'array non sia pieno oppure fino a che non legga la sentinella ';'. La PRE e la POST a cui deve obbedire la funzione sono:
   - PRE = (cin contiene a1..ak';', k>=0, A ha limite>=0 posizioni)
   - POST = (se k>=limite allora A[0..limite-1]=a1..alimite e viene restituito limite, altrimenti A[0..k]=a1..ak';' e viene restituito k+1) */

int ins(char *A, int limite)
{
  if (limite<1) return 0;
  char c;
  cin >> c;
  if (c==';') {
    A[0]=c;
    return 1;
  }
  A[0]=c;
  return ins(A+1, limite-1);
}

/* CORRETTEZZA
   Caso base 1. Questo e' il caso in cui cin contenga piu' caratteri di quelli che puo' invece contenere l'array A. E' dunque il caso in cui k>=limite.
