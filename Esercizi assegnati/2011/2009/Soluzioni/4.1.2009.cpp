
#per ottenere il file per AMPL, eliminare léstensione .txt a questo file

reset; # cancella eventuali dati già memorizzati
model Dieta.mod; # carica il modello
data Dieta.dat; # carica i dati
option solver cplex; # setta cplex come solutore
solve; # risolve il modello
display x; # visualizza il valore ottimo delle variabili x