#include <stdio.h>
#define N 20
#define M 20
int main() {
    int mat[N][M];
    int n, m;
    FILE *fin, *fout;
    fin= fopen("../mat.txt", "r");
    fout= fopen("../output.txt", "w");

    while (!feof(fin)) {
        fscanf(fin, "%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                fscanf(fin, "%d", &mat[i][j]);
            }
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (mat[i][j]==3) {
                fprintf(fout, " il vincitore della giornata %d e': %d\n", j+1, i+1);
            }
        }
    }
    return 0;
}
