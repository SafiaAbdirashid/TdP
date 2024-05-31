#include <stdio.h>
#define filein "../numeri.txt"

int main() {
    int max=-100,min=100,x,x1,x2, scartati=0;
    FILE *fin, *fout;

    fin= fopen(filein, "r");
    fout= fopen("../output.txt", "w");

    while (!feof(fin)) {
        fscanf(fin, "%d", &x);
        if (x<min) {
            min=x;
        }
        if (x>max) {
            max=x;
        }
        fscanf(fin, "%d", &x1);
        fscanf(fin, "%d", &x2);
        if (x2!=(x+x1) && x2!=(x-x1) &&  x2!=(x*x1) && x2!=(x/x1)) {
            scartati++;
        }
    }
    fprintf(fout, "Numero massimo: %d\n", max);
    fprintf(fout, "Numero minimo: %d\n", min);
    fprintf(fout, "Numeri scartati: %d\n", scartati);

    fclose(fin);
    fclose(fout);
    return 0;
}
