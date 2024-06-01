#include <stdio.h>
#define MAXR 50

void leggiMatrice(int M[][MAXR], int *nr, int *nc);
int riconosciRegione(int M[MAXR][MAXR], int *nr, int *nc);

int main() {
    int nr, nc, M[MAXR][MAXR], nrett;
    int r, c;
    leggiMatrice(M, &nr, &nc);
    nrett=riconosciRegione(M, &nr, &nc);
    return 0;
}

void leggiMatrice(int M[][MAXR], int *nr, int *nc) {
    FILE *f_read;
    f_read= fopen("../mappa.txt", "r");

    /* leggo la matrice dal file di ingresso */
    if (f_read==NULL){
        printf("Errore apertura file");
    }
    else {
        fscanf(f_read, "%d %d", nr, nc);
        for (int r = 0; r < *nr; r++) {
            for (int c = 0; c < *nc; c++) {
                fscanf(f_read, "%d", &M[r][c]);
            }
        }
    }
    fclose(f_read);
}

int riconosciRegione(int M[][MAXR], int *nr, int *nc) {
    int k, trovato=0, altezza, base, maxBase[5], maxArea[5], maxAltezza[5], estremo[2], base1 = 0, altezza1 = 0, area, area1 = 0, n;
    int nrett=0;
    for (int i = 0; i < *nr; i++) {
        for (int j = 0; j < *nc; j++) {
            if (M[i][j] == 1) {
                if (M[i-1][j]==0 && M[i][j-1]==0) {
                    base = 1;
                    altezza = 1;
                    trovato++;
                    for (k = i+1; k <*nr && M[k-1][j]==1; k++) {
                        if (M[k][j]==1) {
                            altezza+=1;
                        }
                        else {
                            for (n=j+1; n<*nc && M[k-1][n-1]==1; n++) {
                                if (M[k-1][n]==1) {
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
    }
    printf("Max Base: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d\n", maxBase[0], maxBase[1], maxBase[2], maxBase[3],
           maxBase[4]);
    printf("Max Area: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d\n", maxArea[0], maxArea[1], maxArea[2], maxArea[3],
           maxArea[4]);
    printf("Max Altezza: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d\n", maxAltezza[0], maxAltezza[1], maxAltezza[2],
           maxAltezza[3], maxAltezza[4]);
    if (trovato!=0) {
        return 1;
    }
    else {
        return 0;
    }
}
