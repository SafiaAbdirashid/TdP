Esercizio 1. (Esercizio da consegnare per il bonus-laboratorio)

Competenze: lettura/scrittura di file, manipolazioni di matrici; puntatori e passaggio di parametri per

riferimento

Categoria: problemi di verifica e selezione (Dal problema al programma: 4.5) – Problemi complessi

(Dal problema al programma: 5)

Individuazione di regioni

Si riveda l’esercizio 1 del Lab07 apportandovi le seguenti modifiche:

- supponendo di avere dichiarato una matrice di interi M e di aver definito MAXR come 50, si acquisisca la matrice mediante una funzione (leggiMatrice) che ne ritorna il numero di righe e di colonne effettivamente usati, come parametri “by reference” (o meglio, “by pointer”, cioè con puntatori by value). La funzione deve poter essere chiamata con un’istruzione del tipo: leggiMatrice(M,MAXR,&nr,&nc);
- per effettuare il riconoscimento delle regioni si utilizzi una funzione riconosciRegione che, data una casella della matrice, determini se si tratti o meno di estremo superiore sinistro di una regione, ritornandone “by reference” (come per la precedente) le dimensioni del rettangolo, e avente come valore di ritorno un intero booleano (vero: rettangolo trovato, falso: rettangolo non trovato).

La funzione deve poter essere chiamata come segue:

if (riconosciRegione(M,nr,nc,r,c,&b,&h)) {

// stampa messaggio per rettangolo con

// estremo in (r,c), base b e altezza h

. . .

}
