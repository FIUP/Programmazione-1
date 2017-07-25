/* Data una matrice char[][5], vogliamo una funzione che determini se essa contiene due righe tali che tutti gli elementi dell'una sono anche nell'altra e
   viceversa. In caso la risposta sia positiva, la funzione deve anche restituire al chiamante gli indici delle due righe in questione. Altrimenti deve
   restituire dei valori che avremo scelto in modo da mostrare che non e' stata trovata alcuna soluzione. */

bool due_righe (char C[][5], int limite_1, int &x, int &y)
{
  // PRE
  bool fine=false;
  for (int i=0; i<limite_1-1 && !fine; i++;) {     // R1
    bool trovato=false;
    for (int j=i+1; j<limite_1 && !trovato; j++;) {     // R2

      bool C[5];
      for (int a=0; a<5; a++) C[a]=true;

      bool mutuo=true;
      for (k=0; k<5 && mutuo; k++) {     // R3
	bool corrisponde=false;
	for (h=0; h<5 && !corrisponde; h++)     //R4
	  if (C[h] && A[i][k]==A[j][h]) {
	    corrisponde=true;
	    C[h]=false;
	  }
	// POST4
	if (!corrisponde) mutuo=false;
      }
      // POST3
      if (mutuo) trovato=true;
    }
    // POST2
    if (trovato) fine=true;
  }
  // POST1
  if (fine) {
    x=i;
    y=j;
    return fine;
  }
  else
    return fine;
  // POST
}

/*  PRE = (C e' una matrice di caratteri di dimensioni limite_1 * 5)
   POST = (x e y rappresentano due righe con gli stessi elementi, e la funzione restituisce il valore true se e solo se esistono queste due righe, altrimenti
          restituisce false)
  POST2 = (trovato<=>la riga j contiene gli stessi elementi della riga i)
  POST1 = (fine<=>la riga i e' m-contenuta nella riga j, e viceversa)
  POST4 = (corrisponde<=>l'elemento k-esimo di i e' l'elemento h-esimo di j)&&(nessun altro elemento di i puo' essere l'elemento h-esimo di j) 
  POST3 = (mutuo<=>la riga i e' m-contenuta nella riga j, e viceversa)
