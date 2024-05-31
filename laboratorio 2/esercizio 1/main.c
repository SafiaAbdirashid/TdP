#include <stdio.h>
/*acquisisco due numeri interi e calcolo utilizzando la formula di eurelo il loro mcd*/
int main() {
    int a, b, i, mcd;
    printf("inserisci numero positivo a:");
    scanf("%d", &a);

    printf("inserisci numero positivo b:");
    scanf("%d", &b);
    for (int i = 1; i <= a ; ++i) {
        if (a % i == 0) {
            if (b % i == 0) {
                mcd = i;
            }
        }
    }
    printf("il mcd di %d e %d e': %d \n", a, b, mcd);
    return 0;
}
