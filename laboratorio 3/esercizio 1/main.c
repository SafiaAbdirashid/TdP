#include <stdio.h>

int main() {
    char c, c1, c2;
    int i=0;
    FILE *f_read, *f_write;

    f_read = fopen("../input.txt", "r");
    f_write = fopen("../output.txt", "w");

    while (!feof(f_read)) {
        c= fgetc(f_read);
        /* caso in cui il numero di caratteri per riga è minore di 25*/
        if (i < 25) {
            i++;
            /*conteggio riga*/
            if (c =='\n') {
                c= ' ';
                fprintf(f_write, " | c: %d \n", i);
                i = 0;
            }
            /*metto asterischi al posto dei numeri*/
            if (c >= '0' && c <= '9') {
                c = '*';
            }
            if (c == '.' || c == '!' || c == '?') {
                fscanf(f_read, "%c", &c1);
                fscanf(f_read, "%c", &c2);
                /*gestisco punteggiatura e maiuscole*/
                if (c1 >= 'a' && c1 <= 'z') {
                    c1 = c1 - 32;
                    fprintf(f_write, "%c%c%c", c, ' ', c1);
                }
                if (c1== '\n') {
                    if (c2 >= 'a' && c2<= 'z') {
                        c2= c2 - 32;
                        fprintf(f_write, "%c", c);
                        fprintf(f_write, " | c: %d \n", i);
                        fprintf(f_write, "%c", c2);
                    }
                }
                if (c1 == ' ') {
                    if (c2 >= 'a' && c2<= 'z') {
                        c2= c2 - 32;
                        fprintf(f_write, "%c%c%c", c, c1, c2);
                    }
                }
            }
            else {
                fprintf(f_write, "%c", c);
            }
        }
        /* caso in cui il numero di caratteri per riga è maggiore di 25*/
        if (i == 25) {
            fprintf(f_write, " | c: %d \n", i);
            i = 0;
            if (c >= '0' && c <= '9') {
                c = '*';
                c1='*';
            }
            if (c == '.' || c == '!' || c == '?') {
                fscanf(f_read, "%c", &c1);
                fscanf(f_read, "%c", &c2);
                if (c1 >= 'a' && c1 <= 'z') {
                    c1 = c1 - 32;
                    fprintf(f_write, "%c%c%c", c, ' ', c1);
                }
                else if (c1== '\n' || c1 == ' ') {
                    if (c2 >= 'a' && c2<= 'z') {
                        c2= c2 - 32;
                        fprintf(f_write, "%c%c%c", c, c1, c2);
                    }
                }
            }
        }
    }
    fclose(f_read);
    fclose(f_write);

    return 0;
}
