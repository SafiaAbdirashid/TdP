Esercizio 1. (Esercizio da consegnare per il bonus-laboratorio)

Competenze: manipolazioni di vettori di numeri, costrutti iterativi

Categoria: problemi su sequenze di numeri (Dal problema al programma: 4.2) con sotto-problemi di
verifica/selezione (3.4 e 4.5)

Sequenze numeriche in vettore

Sia V un vettore di N interi (con N30). Si scriva un programma in C che, una volta acquisito da
tastiera (o da file, la scelta è libera) il contenuto del vettore, chiami una funzione avente
prototipo

sottoSequenze(int V[], int N);

La funzione visualizzi tutti i sottovettori di dimensione massima formati da celle contigue, contenenti
dati non nulli.

Esempio:

dato il vettore [1 3 4 0 1 0 9 4 2 0], i due sottovettori di dimensione massima (3) contenenti dati non
nulli sono [1 3 4] e [9 4 2].

Suggerimenti:

Si noti che il problema può essere affrontando risolvendo due sottoproblemi:

- identificare sottovettori di dati non nulli:

      o è sufficiente “riconoscere” l’inizio e la fine di tali sottovettori

- selezionare quelli di lunghezza massima:

      o un metodo semplice consiste nel “provare” tutte le lunghezze in modo

         decrescente, fermandosi alla prima lunghezza per cui si trovano

         sottovettori;

      o un metodo più efficiente consiste nel determinare prima la lunghezza

         massima e poi cercarei sottovettori corrispondentio si potrebbe anche (in

         alternativa) cercare di fare una sola iterazione sul vettore principaleper

         riconoscere i sottovettori, determinare la lunghezza massima e “ricordare”

         (usando unaltro vettore) gli inizi dei sotto-vettori: ma complessità /

         efficienza non cambierebbe (oc-correrebbe comunaue una ulteriore

         iterazione per stampare i sotto-vettori) e (probabilmen-te) il programma

         sarebbe più complicate che nella versione precedente.
