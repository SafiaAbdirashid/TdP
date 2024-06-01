Esercizio 2. (Esercizio da consegnare per il bonus-laboratorio)

Competenze: manipolazioni di stringhe e matrici di caratteri, costrutti iterativi

Categoria: problemi di codifica ed elaborazione testi (Dal problema al programma: 4.3 e 4.4)

**Ricodifica di testo con dizionario**

Un file (sorgente.txt) contiene un testo composto da un numero indefinito di righe, di lunghezza
massima 200 caratteri ognuna. Un secondo file (dizionario.txt) contiene un elenco di coppie di
stringhe. Il file dizionario.txt è organizzato come segue:

- sulla prima riga è presente un numero intero e positivo S (≤ 30), che indica il numero di possibili
  ricodifiche (sostituzioni) presenti nel dizionario
- seguono S coppie <ricodifica><originale> a rappresentare le sostituzioni possibili. Ogni
  sostituzione <compresso> è nella forma $<intero>$

Lo scopo del programma è di ricodificare il primo file di testo andando a sostituire sequenze di
caratteri sulla base dei contenuti del secondo file. In caso di più sostituzioni possibili per una
certa sottostringa, il programma scelga la prima sostituzione trovata. Il risultato della ricodifica
sia salvato su un terzo file (ricodificato.txt).

Esempio:

Il contenuto del file sorgente.txt è:

apelle figlio di apollo

fece una palla di pelle di pollo

tutti i pesci vennero a galla

per vedere la palla di pelle di pollo

fatta da apelle figlio di apollo

Il contenuto del file dizionario.txt è:

9

$11$ pelle

$2$ pollo

$333$ palla

$41$ alla

$5078$ tta

$6$ tti

$7$ ll

$81$ er

$900$ ere

Il file di uscita ricodificato.txt conterrà:

a$11$ figlio di a$2$

fece una $333$ di $11$ di $2$

tu$6$ i pesci venn$81$o a g$41$

p$81$ ved$81$e la $333$ di $11$ di $2$

fa$5078$ da a$11$ figlio di a$2$
