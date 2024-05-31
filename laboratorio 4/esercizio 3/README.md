Esercizio 3. (Esercizio da consegnare per il bonus-laboratorio)

Competenze: manipolazioni di matrici di numeri, costrutti iterativi

Categoria: problemi su matrici di numeri (Dal problema al programma: 4.1 e 4.2)

**Iterazione su matrici**

Un file di testo contiene una matrice di interi con il seguente formato:

- la prima riga del file specifica le dimensioni della matrice (numero di righe nr e numero di colonne nc). Si assuma che entrambi i valori siano comunque al più pari a 20• ciascuna delle nr righe successive contiene gli nc valori corrispondenti a una riga della matrice, separati da uno o più spazi.

Si scriva un programma C che:

- legga tale matrice dal file di ingresso, il cui nome (massimo 20 caratteri) sia letto da tastiera
- chieda ripetutamente all’utente un valore dim compreso tra 1 e il minimo tra nr e nc e stampi tutte le sottomatrici quadrate di tale dimensione contenute nella matrice
- termini l’iterazione se l’utente inserisce un valore non coerente con le dimensioni della matrice
- determini e stampi al termine la sottomatrice quadrata, tra quelle precedentemente individuate, la somma dei cui elementi è massima.

Se ad esempio il file contenesse la seguente matrice di 3 righe per 4 colonne

3 4

1 2 3 4

5 6 7 8

9 0 1 1

e dim valesse 2, occorrerebbe visualizzare:

Le sottomatrici quadrate di dimensione 2 sono:

1 2

5 6

2 3

6 7

3 4

7 8

5 6

9 0

6 7

0 1

7 8

1 1

La sottomatrice con somma degli elementi massima (22) e’:

3 4

7 8
