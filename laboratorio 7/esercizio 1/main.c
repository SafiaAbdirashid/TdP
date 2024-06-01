#include <stdio.h>
#define MAX 50

int main() {
    int matrice[MAX][MAX], nr, nc, maxBase[5], maxArea[5], maxAltezza[5], estremo[2], base, base1 = 0, altezza, altezza1 = 0, area, area1 = 0, i, j, k,n;
    FILE *fin = fopen("..//mappa.txt", "r");
    fscanf(fin, "%d %d", &nr, &nc);

    for (i = 0; i < nr; i++) {
        for (j = 0; j < nc; j++) {
            fscanf(fin, " %d", &matrice[i][j]);
        }
    }
    for (i = 0; i < nr; i++) {
        for (j = 0; j < nc; j++) {
            if (matrice[i][j] == 1) {
                base=1;
                altezza=1;
                for (k = i+1; k < nr && matrice[k-1][j]==1; k++) {
                    if (matrice[k][j]==1) {
                        altezza+=1;
                    }
                    else {
                        for (n=j+1; n<nc && matrice[k-1][n-1]==1; n++) {
                            if (matrice[k-1][n]==1) {
                                base+=1;
                            }
                        }
                    }
                }

                area=base*altezza;
                estremo[0]=i;
                estremo[1]=j;
                // se è la base massima salviamo tutti i dati nel vettore ;)
                if (base>base1) {
                    base1=base;
                    maxBase[0] = estremo[0];
                    maxBase[1] = estremo[1];
                    maxBase[2] = base1;
                    maxBase[3] = altezza;
                    maxBase[4] = area;
                }
                // stessa cosa con l'altezza
                if (altezza > altezza1) {
                    altezza1 = altezza;
                    maxAltezza[0] = estremo[0];
                    maxAltezza[1] = estremo[1];
                    maxAltezza[2] = base;
                    maxAltezza[3] = altezza1;
                    maxAltezza[4] = area;
                }
                // repeat per l'area max
                if (area > area1) {
                    area1 = area;
                    maxArea[0] = estremo[0];
                    maxArea[1] = estremo[1];
                    maxArea[2] = base;
                    maxArea[3] = altezza;
                    maxArea[4] = area1;
                }
            }
        }
    }
    printf("Max Base: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d\n", maxBase[0], maxBase[1], maxBase[2], maxBase[3],
           maxBase[4]);
    printf("Max Area: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d\n", maxArea[0], maxArea[1], maxArea[2], maxArea[3],
           maxArea[4]);
    printf("Max Altezza: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d\n", maxAltezza[0], maxAltezza[1], maxAltezza[2],
           maxAltezza[3], maxAltezza[4]);
}
