#include <stdio.h>
#define P 3.14159

// calcolare Area:
// QUADRATO(Q):
//   - diagonale(D): (D^2)/2
//   -     lato (L): L^2
// CERCHIO(C):
//   -  diametro(D): (P*(D^2))/4
//   -    raggio(R): (R^2)*P

int main() {
    int D, L, R;
    float area;
    char letter1, letter2;
    printf("Enter character one:");
    scanf("%c", &letter1);
    printf("The character is:%c\n", letter1);
    printf("Enter character two:");
    scanf("%c", &letter2);

    if (letter1 == 'Q') {
        scanf("%c", &letter2);
        printf("The character is:%c\n", letter2);
        if (letter2 == 'D') {
            printf("Enter value D:", D);
            scanf("%d", &D);
            area = ((D * D) / 2);
            printf("Area quadrato: %.1f\n", area);
        }
        if (letter2 == 'L') {
            printf("Enter value L:", L);
            scanf("%d", &L);
            area = (L * L);
            printf("Area quadrato: %.1f\n", area);
        }
    }
    if (letter1 == 'C') {
        scanf("%c", &letter2);
        printf("The character is:%c\n", letter2);
        if (letter2 == 'D') {
            printf("Enter value D:", D);
            scanf("%d", &D);
            area = ((P * (D * D)) / 4);
            printf("Area cerchio: %5.3f\n", area);
        }
        if (letter2 == 'R') {
            printf("Enter value R:", R);
            scanf("%d", &R);
            area = (R * R * P);
            printf("Area cerchio: %5.3f\n", area);
        }
    }
    return 0;
}
