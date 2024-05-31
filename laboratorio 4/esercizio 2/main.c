#include <stdio.h>
#define maxN 30
void ruota(int v[], int N);


int main() {
    int N, v[maxN];
    printf("N vale:");
    scanf("%d", &N);
    printf("il vettore ha elementi:");
    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }
    ruota(v, N);
    return 0;
}

void ruota(int v[], int N) {
    int pos, dir,x;
    printf("numero posizioni(pos<N): ");
    scanf("%d", &pos);
    printf("\n");
    printf("direzione (dir=-1 per dx, dir=1 per sx): ");
    scanf("%d", &dir);

    if (dir==1) {
        for (int j = 0; j < pos; j++) {
            x=v[0];
            for (int i = 0; i <= N-2; i++) {
                v[i]=v[i+1];
            }
            v[N-1]=x;
        }
    }
    else if (dir==-1) {
        for (int j = 0; j < pos; j++) {
            x=v[N-1];
            for (int i = N-2; i >= 0; i--) {
                v[i+1]=v[i];
            }
            v[0]=x;
        }
    }
    for (int i = 0; i < N; i++) {
        printf("%d", v[i]);
    }
}
