#include <stdio.h>

int main() {
    int N, n0 = 0, n1 = 1, c;
    printf("inserisci N:");
    scanf("%d", &N);
    printf("i primi %d numeri della serie di fibonacci sono:\n", N);
    for (int i =0; i<N; i++) {
        printf("%d", n0);
        c = n1;
        n1 = n0 + n1;
        n0 = c;
    }
    return 0;
}
