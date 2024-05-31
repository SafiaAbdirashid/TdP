#include <stdio.h>
#define N 30

void sottoSequenze(int V[], int n);

int main(void) {
    int V[N], n;
    FILE *fp;
    fp= fopen("../elementi.txt", "r");
    /* acquisisco da tastiera contenuto vettore */
    printf("lunghezza vettore(max 30):");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &V[i]);
    }
    sottoSequenze(V, n);
    fclose(fp);
    return 0;
}

void sottoSequenze (int V[], int n) {
    int S[n], inizio = 0, fine = 0, contatore = 0, contmax = 0;
    /* sottovettore max */
    for (int i = 0; i < n; i++) {
        if (V[i] != 0) {
            contatore++;
            if (contatore > contmax) {
                contmax = contatore;
            }
        } else if (V[i] == 0) {
            contatore = 0;
        }
    }
    printf("\nil sottovettore max e' lungo %d\n", contmax);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 1; j++) {
            if (V[i] != 0 && V[i + 1] != 0) {
                V[j] = V[i];
                printf("%d", V[j]);
            }
            else if (V[i] == 0) {
                V[j] = V[i-1];
                printf("%d\n", V[j]);
            }
        }
    }
}
