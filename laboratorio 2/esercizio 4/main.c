#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fin, *fout;
    char c0, c1;
    int h=0;
    fin= fopen("../sorgente.txt", "r");
    fout= fopen("..//ricodificato.txt", "w");
    c0=fgetc(fin);
    while (!feof(fin)) {
        c1=fgetc(fin);
        if (isalpha(c0)) {
            if (isupper(c0)) {
                if (isalpha(c1)) {
                    h=c0-'A';
                    c1=c1+h;
                    if (c1>122) {
                        c1=c1-26;
                    }
                }
            }
            else if (islower(c0)){
                if (isalpha(c1)) {
                    h=c0-'a';
                    c1=c1+h;
                    if (c1>122) {
                        c1=c1-26;
                    }
                }
            }
            else {
                printf(fout, "%c", c0);
            }
            fprintf(fout, "%c", c0);
            c0=c1;
        }
        else {
            fprintf(fout, "%c", c0);
            c0=c1;
        }
    }
    return 0;
}
