#include <stdio.h>

void comprimi(FILE *fin, FILE *fout);
void decomprimi(FILE *fin, FILE *fout);

int main() {
    FILE *fin, *fout;
    int scelta;

    if ((fin = fopen("../sorgente.txt", "r")) == NULL) {
        printf("Error opening file 1\n");
        return 1;
    }
    if ((fout = fopen("../ricodificato.txt", "w")) == NULL) {
        printf("Error opening file 2\n");
        return 2;
    }

    /*utente sceglie se comprimere o decomprimere*/
    printf("C (comprimi) o D (decomprimi) ");
    scanf("%c", &scelta);
    if (scelta == 'C') {
        comprimi(fin, fout);
    }
    else if (scelta == 'D') {
        decomprimi(fin, fout);
    }
    else {
        return 1;
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
void comprimi(FILE *fin, FILE *fout) {
    char c1, c2;
    int rip=1;
    c1= fgetc(fin);
    while (!feof(fin)) {
        c2= fgetc(fin);
        if (c1==c2) {
            if (rip<10) {
                rip++;
            }
            else if (rip==10) {
                fprintf(fout, "%c$%d", c1, rip-1);
                rip=1;
            }
        }
        else if (c1!=c2) {
            if (rip==1) {
                fprintf(fout, "%c", c1);
                rip=1;
            }
            else if (rip<=10) {
                if (rip==2) {
                    fprintf(fout, "%c%c", c1, c1);
                    rip=1;
                }
                else {
                    fprintf(fout, "%c$%d", c1, rip-1);
                    rip=1;
                }
            }
        }
        c1=c2;
    }
}

void decomprimi(FILE *fcod, FILE *fout){
    char c1, c2;
    int c3;
    c1= fgetc(fcod);
    while (!feof(fcod)) {
        c2= fgetc(fcod);
        if (c2=='$') {
            c3= fgetc(fcod);
            c3=c3-'0';
            for (int i = 0; i < c3; i++) {
                fprintf(fout, "%c", c1);
            }
        }
        else if (c2!='$') {
            if (c1!='$') {
                fprintf(fout, "%c", c1);
            }
            c1=c2;
        }
    }
}
