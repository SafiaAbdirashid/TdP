Esercizio 2. (Esercizio da consegnare per il bonus-laboratorio)

Competenze: manipolazioni di vettori di numeri, costrutti iterativi

Categoria: problemi su sequenze ordinate di numeri (Dal problema al programma: 4.2)

**Rotazione di vettori**

Si scriva una funzione C in grado di permettere all'utente di far ruotare verso destra o verso sinistra i contenuti di un vettore di N interi, di un numero a scelta di posizioni P. Il vettore è da intendersi come circolare, nel senso che l’elemento a destra della cella di indice N-1 è la cella di indice 0 e l’elemento a sinistra della cella di indice 0 è la cella di indice N-1. La figura seguente illustra una rotazione a destra di 3 posizioni:

La funzione abbia il seguente prototipo:

void ruota(int v[maxN], int N, int P, int dir);

Il main:

1. acquisisca da tastiera N (N  maxN con maxN pari a 30)

2. acquisisca da tastiera il vettore V

3. effettui ripetutamente delle rotazioni, acquisendo ciascuna volta P (P < N, P=0 per terminare) e la

direzione (dir =-1 per rotazione a destra, dir = 1 per rotazione a sinistra) e stampi il vettore risultante.
