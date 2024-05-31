#include <stdio.h>
#define MAXR 20
#define MAXC 20

int main() {
    int m[MAXR][MAXC];
    int nr,nc, min, dim, inizio=0;
    char fname[20];
    FILE *fin;
    printf("nome file: ");
    scanf("%s", &fname );
    fin= fopen(fname, "r");
    fscanf(fin,"%d %d", &nr, &nc);
    while (!feof(fin)) {
        for (int i = 0; i < nr; i++) {
            for (int j = 0; j < nc; j++) {
                fscanf(fin, "%d", &m[i][j]);
            }
        }
    }
    if (nr<nc) {
        min=nr;
    }
    else {
        min=nc;
    }

    while (fin!=EOF) {
        printf("inserire valore 1<=dim<=min: ");
        scanf("%d", &dim);
        if (dim>=1 && dim<=min) {
            for (int i = 0; i < nr; i++) {
                for (int j = 0; j < nc; j++) {
                    if (i+dim>nr || j+dim>nc) {
                        inizio=0;
                    }
                    else {
                        inizio=1;
                        for (int k = i; k < i+dim; k++) {
                            for (int l = j; l < j+dim;l++) {
                                printf("%d ", m[k][l]);
                            }
                            printf("\n");
                        }
                        printf("\n");
                    }
                }
            }
            /*for (int i = 0; i <nr; i++) {
                for (int j = 0; j < nc; j++) {
                    if(i+1==nr&&j+1!=nc){
                        printf("%d",m[i][j]);
                        printf("%d\n",m[i][j+1]);
                        printf("%d",m[i+1][j]);
                        printf("%d",m[i+1][j+1]);
                    }else if(j+1==nc&&i+1!=nr){
                        printf("%d",m[i][j]);
                        printf("%d\n",m[i][j+1]);
                        printf("%d",m[i+1][j]);
                        printf("%d",m[i+1][j+1]);
                    } else {
                        printf("%d",m[i][j]);
                        printf("%d\n",m[i][j+1]);
                        printf("%d",m[i+1][j]);
                        printf("%d",m[i+1][j+1]);
                    }
                }
            }*/
        }
        else {
            printf("valore non coerente con le dimensioni delle matrici");
        }
    }
    fclose(fin);
    return 0;
}
