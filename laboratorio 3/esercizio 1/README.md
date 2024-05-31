Esercizio 1. (Esercizio da consegnare per il bonus-laboratorio)

Competenze: IO su file, manipolazioni di caratteri

Categoria: problemi di elaborazione testi (Dal problema al programma: 3.3)

Elaborazione testi a livello di singoli caratteri

E’ dato un file testo, contenente solo caratteri alfabetici, numerici, segni di punteggiatura (. , ; : ! ?),

spazi e a-capo. Si vuole generare un secondo file contenente il testo, letto dal primo file e trasformato

nel modo seguente:

- Sostituire le cifre numeriche con il carattere '*'.
- Inserire uno spazio dopo ogni segno di punteggiatura, a meno che questo non sia già seguito da uno

spazio o un a-capo.

- Il primo carattere alfabetico successivo a un punto, punto esclamativo o interrogativo deve essere

maiuscolo; se non lo è, trasformarlo in maiuscolo (anche se tra la punteggiatura e il carattere

alfabetico ci sono uno o più spazi o a capo).

- Le righe del testo devono essere al massimo di 25 caratteri (a-capo escluso). Se sono più lunghe

vanno troncate (anche a metà di una parola) aggiungendo un a-capo esattamente dopo il

venticinquesimo carattere.

- Al termine di ogni riga vanno aggiunti, prima dell’a-capo, eventuali spazi per raggiungere i 25

caratteri.

- Ogni riga deve terminare con il numero di caratteri del file originale trascritti nella riga, nel

formato: " | c:%d \n".

I nomi dei file sono costanti (il primo file è input.txt, il secondo testo.txt) e definiti con #define (es.#define filein "input.txt").
