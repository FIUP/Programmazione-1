/*dati x = C[i][k] e y = C[z][j] devo confrontare x con y*/
for(int i=0; i<6; i++)							//si posiziona nella riga di x
	for(int j=0; j<5; j++){						//si posiziona nella colonna di y
		book OK = true;
		for(int k=0; k<5 && OK;k++){			//posizione di x all'interno della riga i
			bool trovato = false;
			for(int z=0; z<6 && !trovato; z++)	// posizione di y nella colonna j
				if(C[i][k] == C[z][j])
					trovato = true;
				if(!trovato)
					OK=false;
		}
		B[i][j]=OK;
	}
		