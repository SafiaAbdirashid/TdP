#include <stdio.h>
#define N 100

void insertionSort(int a[], int n);
void selectionSort(int a[], int n);
void shellSort(int a[], int n);


int main() {
    FILE *f_read;
    int a[N];
    int n, sequenze, j, i;

    f_read= fopen("../sort1.txt", "r");

    printf("Prima gli elementi erano: \n");
    if (f_read!=NULL) {
        fscanf(f_read, "%d", &sequenze);
        for (i = 0; i < sequenze; i++) {
            fscanf(f_read, "%d", &n);
            for (j = 0; j < n; j++) {
                fscanf(f_read, "%d", &a[j]);
            }
        }
        insertionSort(a, n);
        selectionSort(a, n);
        shellSort(a, n);
    }
    else {
        printf("Errore nell'aprire file");
    }

    fclose(f_read);
    return 0;
}

 /* insertion sort */
void insertionSort(int a[], int n) {
    int i, j, l=0, r=n-1, x;
    int scambi=0, cicloesterno=0, ciclointerno=0, totiterazioni=0;
    for (i=l+1; i<= r; i++) {
        x= a[i];
        j= i-1;
        while (j>=1 && x < a[j]){
            a[j+1]=a[j];
            scambi++;
            ciclointerno++;
            j--;
        }
        a[j+1]=x;
        cicloesterno++;
    }

    totiterazioni=cicloesterno+ciclointerno;
    printf("Insertion sort:\nNumero degli scambi: %d\nNumero iterazioni ciclo esterno: %d\n"
           "Numero iterazioni ciclo interno: %d\nNumero totale iterazioni: %d\n", scambi, cicloesterno, ciclointerno, totiterazioni);
    printf("\n");
}

/* selection sort */
void selectionSort(int a[], int n) {
    int i, j, l=0, r=n-1, min;
    int temp;
    int scambi=0, cicloesterno=0, ciclointerno=0, totiterazioni=0;
    for (i = l; i < r; i++) {
        cicloesterno++;
        min = i;
        for (j = i+1; j <= r; j++)
            ciclointerno++;
            if (a[j]<a[min])
                min=j;
        if (min!=i) {
            scambi++;
            temp= a[i];
            a[i]=a[min];
            a[min]=temp;
        }
    }
    totiterazioni=cicloesterno+ciclointerno+scambi;
    printf("Selection sort:\nNumero degli scambi: %d\nNumero iterazioni ciclo esterno: %d\nNumero iterazioni ciclo interno: %d\n"
           "Numero totale iterazioni: %d\n", scambi, cicloesterno, ciclointerno, totiterazioni);
    printf("\n");
        return;
}

/* shell sort */
void shellSort(int a[], int n) { /* utilizzo la sequenza di knuth */
    int i, j, l=0, r=n-1, x, h=1; /* scegli una h a piacere, in questo caso ho preso h=1 */
    int scambi=0, cicloesterno=0, ciclointerno=0, totiterazioni=0;

    while (h<n/3) {
        h=3*h+1;
    }

    while (h>=1) {
        for (i = l+h; i <=r ; i++) {
            x=a[i];
            j=i;
            while (j>= l+h && x<a[j-h]) {
                ciclointerno++;
                scambi++;
                a[j]=a[j-h];
                j-=h;
            }
            a[j]=x;
            cicloesterno++;
        }
        h=h/3;
    }
    totiterazioni=cicloesterno+ciclointerno+scambi;
    printf("Shell sort:\nNumero degli scambi: %d\nNumero iterazioni ciclo esterno: %d\nNumero iterazioni ciclo interno: %d"
           "\nNumero totale iterazioni: %d\n", scambi, cicloesterno, ciclointerno, totiterazioni);
    printf("\n");
}
