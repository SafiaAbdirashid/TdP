Esercizio 1. (Esercizio da consegnare per il bonus-laboratorio)

Competenze: selezione/filtro dati mediante ricerca in tabelle di nomi/stringhe, tipi enumerativi

Categoria: problemi di selezione (Dal problema al programma: 3.4.2 e 4.5.2)

Azienda di trasporti

Un'azienda di trasporti urbani, traccia i propri automezzi in un file di log (file testuale di nome
corse.txt).

Il file è organizzato come segue:

- sulla prima riga, un intero positivo indica il numero di successive righe del file stesso (al più
  1000)
- le righe successive riportano le informazioni sulle tratte, una per riga, con formato:
  <codice_tratta><partenza><destinazione><data><ora_partenza><ora_arrivo><ritardo>

Tutte le stringhe sono lunghe al massimo 30 caratteri. Il ritardo è un numero intero, eventualmente
nullo, che rappresenta i minuti di ritardo accumulati dalla corsa.

Si scriva un programma C che, letto il file e acquisitone il contenuto in una oppurtuna struttura dati,
risponda alle seguenti interrogazioni (presentate mediante un menu):

1. elencare tutte le corse partite in un certo intervallo di date

2. elencare tutti le corse partite da una certa fermata (partenza)

3. elencare tutti le corse aventi una data destinazione (capolinea)

4. elencare tutte le corse che hanno raggiunto la destinazione in ritardo, in un certo intervallo di
   date

5. elencare il ritardo complessivo accumulato dalle corse identificate da un certo codice di tratta

Le interrogazioni di cui sopra siano gestite mediante menu di comandi (si veda il paragrafo 4.4.1,
Dal problema al programma). Ogni comando consiste di una parola tra "date", "partenza", "capolinea",
"ritardo", "ritardo_tot" e "fine", eventualmente seguita sulla stessa riga da altre informazioni, ad
esempio due date per "date", una fermata di partenza per "partenza", etc.

Si utilizzi la strategia di codifica dei comandi mediante tipo enum comando_e, contenente i simboli
r_date, r_partenza, r_capolinea, r_ritardo, r_ritardo_tot, r_fine, che consentemenu basati su
switchcase.

Si consiglia di:

• realizzare una funzione leggiComando che, acquisito in modo opportuno il comando, ritorni il
corrispondente valore di tipo comando_e

• realizzare una funzione menuParola che, ricevuti tra i parametri la tabella, la dimensione
(cioè il numero effettivo di dati) della tabella e il tipo di comando, gestisca mediante menu
l’acquisizione delle informazioni aggiuntive necessarie per quel comando e la chiamata di un’opportuna
funzione di selezione e stampa dei dati selezionati.

Si noti che la data di una corsa non subisce variazioni a causa del ritardo.
