#include <stdio.h>

int main() {
    float af;
    double ad;
    int bigEndian;
    char *x1=(char *) &af, *x2=(char *) &ad;
    printf("insert 2 float numbers: ");
    scanf("%f %f", &af, &ad);
    if (x1[0]==0) {
        bigEndian=1;
        printf("float is big endian %d\n", bigEndian);
    }
    else {
        bigEndian=0;
        printf("float is little endian %d\n", bigEndian);
    }

    if (x2[0]==0) {
        bigEndian=1;
        printf("double is big endian %d\n", bigEndian);
    }
    else {
        bigEndian=0;
        printf("double is little endian %d\n", bigEndian);
    }
    return 0;
}
