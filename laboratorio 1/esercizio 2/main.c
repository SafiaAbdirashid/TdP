#include <stdio.h>

int main() {
    char letter;
    float op1, op2, result;

    /*Acquisisco da tastiera utilizzando getchar l’operazione da eseguire (‘+’, ‘-‘, ‘*’ e ‘/’)*/
    printf("Insert character: ");
    letter = getchar();

    /*Acquisisco da tastiera utilizzando scanf i due operandi (float)*/
    printf("enter op1");
    scanf("%f", &op1);

    printf("enter op2");
    scanf("%f", &op2);

    if (letter == '+') {
        result = (op1 + op2);
        printf("%c %.2f\n",letter, result);
    }

    if (letter == '-') {
        result = (op1 - op2);
        printf("%c %.2f\n",letter, result);
    }

    if (letter == '/') {
        if ( op2 != 0.0) {
            result = (op1 / op2);
            printf("%c %.2f\n",letter, result);
        }
    }

    if (letter == '*') {
        result = (op1 * op2);
        printf("%c %.2f\n",letter, result);
    }
    else {
        printf("Error\n");
    }
    return 0;
}

// APPROFONDIMENTO: quando op2 è uguale a 0 viene stampato sia il risultato dell'operazione sia l'errore
