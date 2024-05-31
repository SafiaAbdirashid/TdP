Esercizio 3.

Competenze: IO su file, manipolazioni di caratteri;

Categoria: problemi di codifica applicati a testi/caratteri (3.2.2)

Un file (sorgente.txt) contiene un testo composto da un numero indefinito di righe.

Notare che il testo NON contiene il carattere ‘$’.

Lo scopo del programma è di ricodificare il testo sostituendo sequenze di caratteri ripetuti
da 2 a 9 volte (ATTENZIONE: il numero non comprende il primo carattere, cioè AA contiene una
ripetizione, BBB due ripetizioni, ecc.) con la terna di caratteri
<carattere ripetuto>$<numero di ripetizioni>

(ATTENZIONE: per il <numero di ripetizioni> è sufficiente un carattere). Se un carattere fosse
ripetuto più di 9 volte, le ripetizioni sarebbero spezzate in più intervalli.

Ad esempio, la sequenza di caratteri “il numero 1000000 e’ grande”, viene compressa in
“il numero 10$5 è grande”. La sequenza, “ci sono 15 = ripetuti: =============== e 4 punti....”
viene ricodificata in: “ci sono 15 = ripetuti: =$9=$4 e 4 punti.$3”

Il risultato della ricodifica sia salvato su un secondo file (compresso.txt).

Esempio:

Il contenuto del file sorgente.txt è:

Partenza Destinazione Costo

Parigi New York 1000

Roma Londra 700

Sidney Los Angeles 2222

Il file di uscita ricodificato.txt conterrà:

Partenza $5Destinazione $3Costo

$2Parigi $9New York $410$2

$4Roma $9 Londra $5700

$2Sidney $6Los Angeles $42$3

Si scrivano due funzioni, in grado di effettuare, rispettivamente, la compressione e la decompressione.
I prototipi delle funzioni siano

int comprimi(FILE *fin, FILE *fout);
int decomprimi(FILE *fin, FILE *fout);

In caso di errore le funzioni ritornano come risultato 0, diversamente ritornano il numero di caratteri
scritto nel file in uscita. Il main permette all’utente di selezionare (in base a un opportune input)
codifica oppure decodifica, apre i file quello in input e quello in output. chiama la funzione
selezionata.

Si consiglia di usare un terzo file per il testo de-compresso (evitando così di sovrascrivere,
perdendolo, il file originale sorgente.txt)
