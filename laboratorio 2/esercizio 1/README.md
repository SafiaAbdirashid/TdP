Esercizio 1.

Competenze: IO formattato, manipolazioni di numeri;

Categoria: problemi numerici (Dal problema al programma: 3.1), con affinità ai problemi di codifica di numeri (3.2.1)

Scrivere un programma C che, acquisiti 2 numeri interi positivi ne calcoli il massimo comune divisore utilizzando la formula di Eulero.

Formula di Eulero o metodo dei resti: si procede per divisioni successive del numero maggiore per quello minore, sostituendo ad ogni passo il valore maggiore con il minore ed il minore col resto della divisione. Il processo termina quando il resto è 0.

Esempio: A = 34 , B = 18

passo 1: 34 % 18 = 16

passo 2: 18 % 16 = 2

passo 3: 16 % 2 = 0 ← stop!

Risultato: MCD = 2
