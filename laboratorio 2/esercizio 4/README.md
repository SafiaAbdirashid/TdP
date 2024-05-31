Esercizio 4.

Competenze: IO su file, manipolazioni di caratteri;

Categoria: problemi di codifica applicati a testi/caratteri (3.2.2)

Un file contiene un testo composto da un numero non noto di caratteri.

Lo scopo del programma è di ricodificare il testo, generando un secondo file, nel quale i caratteri
sono stati ricodificati secondo le regole seguenti:

I caratteri numerici sono ricodificati in questo modo:

- I caratteri numerici (‘0’..’9’) sono ricodificati nel carattere numerico posto k posizioni più avanti,
  con k che, partendo da 0, viene incrementato ad ogni carattere numerico ricodificato
  (ATTENZIONE: gli incrementi sono effettuati MODULO 10, cioè, arrivati a 9 si riparte da 0).
  Se ad esempio il file iniziasse con la riga: “Il numero 248 è pari”, il ‘2’ verrebbe ricodificato
  (k parte da 0) in ‘2’+0 = ‘2’ (k diventa 1), il ‘4’ in ‘4’+1 = ‘5’ (k diventa 2) e ‘8’ viene
  ricodificato in ‘8’+2 = ‘0’ (perché arrivati a ‘9’ si riparte da ‘0’).

I caratteri alfabetici sono invece ricodificati in questo modo:

- Se un carattere alfabetico è preceduto da un carattere non alfabetico, resta inalterato
- Se è preceduto da un carattere alfabetico (sia c0 il carattere precedente), il suo codice si sposta
  di h posizioni in avanti, nell’insieme dei caratteri alfabetici (con h = c0-‘A’, se c0 è maiuscolo,
  h=c0-‘a’, se c0 è minuscolo. L’incremento di h è modulo 26, cioè arrivati alla ‘z’ o ‘Z’ (a seconda
  che il carattere ricodificato sia maiuscolo o minuscolo) si riparte da ‘a’ o ‘A’.

Il risultato della ricodifica sia salvato su un secondo file (I nomi dei file siano opportunamente
acquisiti da tastiera).

Esempio:

Se il contenuto del file è:

Apelle figlio di Apollo

fece una palla di pelle di pollo

tutti i pesci vennero a galla

per vedere la palla di pelle di pollo

fatta da Apelle figlio di Apollo.

Il file di uscita ricodificato.txt conterrà:

Aptept fntema dl Apdozn

fjlp uhh ppall dl ptept dl pdozn

tngzh i ptlnv vzmzdui a ggrcc

ptk vzcgxb ll ppall dl ptept dl pdozn

ffyrr dd Aptept fntema dl Apdozn.

Si scrivano due funzioni, in grado di effettuare, rispettivamente, la codifica e la decodifica.

I prototipi delle funzioni siano:

int codifica(FILE *fin, FILE *fout);

int decodifica(FILE *fin, FILE *fout);

In caso di errore le funzioni ritornano come risultato 0, diversamente ritornano il numero di caratteri
scritto nel file in uscita. Il main permette all’utente di selezionare (in base a un opportuno input)
codifica oppure decodifica, apre i file quello in input e quello in output. chiama la funzione
selezionata.
