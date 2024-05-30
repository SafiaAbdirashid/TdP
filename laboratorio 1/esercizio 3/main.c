#include <stdio.h>

int main() {
    FILE *fp_read, *fp_write;
    char symbol;
    float op1, op2, result;
    if ((fp_read = fopen("../operations.txt", "r")) == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    if ((fp_write = fopen("../results.txt", "w")) == NULL) {
        printf("Error opening file\n");
        return 2;
    }

    while (!feof(fp_read)){
				/*leggo da file simbolo e numeri*/
        fscanf(fp_read, " %c %f %f", &symbol, &op1, &op2);
				/*scrivo su un altro file l'operazione eseguita e il suo risultato*/
        if (symbol == '+') {
            result = op1 + op2;
            fprintf(fp_write, " %c %.2f\n", symbol, result);
        }
        if (symbol == '-') {
            result = op1 - op2;
            fprintf(fp_write, " %c %.2f\n", symbol, result);
        }
        if (symbol == '*') {
            result = op1*op2;
            fprintf(fp_write, " %c %.2f\n", symbol, result);
        }
        if (symbol == '/') {
            result = op1/op2;
            fprintf(fp_write, " %c %.2f\n", symbol, result);
        }
    }

    fclose(fp_read);
    fclose(fp_write);

    return 0;
}
