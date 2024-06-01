#include <stdio.h>
#define max_len 200+1
#define max_diz 20

typedef struct {
    char ricodificata[max_len];
    char originale[max_len];
} t_voce;

int main() {
    int nr_diz, diverso=0,trovata=0, s=0;
    char riga[max_len];
    t_voce dizionario[max_diz];
    FILE *fsorgente, *fdiz, *fricodificato;

    fsorgente= fopen("../sorgente.txt", "r");
    fdiz= fopen("../dizionario.txt", "r");
    fricodificato= fopen("../ricodificato.txt", "w");

    fscanf(fdiz, "%d", &nr_diz);
    for (int i = 0; i < nr_diz; i++) {
        fscanf(fdiz, "%s %s", &dizionario[i].ricodificata,  &dizionario[i].originale);
    }

    while (!feof(fsorgente)) {
        fgets(riga,max_len,fsorgente);

        for (int i = 0; i < max_len && riga[i]!='\0'; i++) {
            if (riga[i]!='\n') {
                for (int j = 0; j < nr_diz; j++) {
                    diverso=0;
                    if (riga[i] != dizionario[j].originale[0]) {
                        diverso = 1;
                        trovata=0;
                    }
                    else {
                        for (int k = 0; k < max_len && dizionario[j].originale[k] != '\0'; k++) {
                            if (riga[i+k] == dizionario[j].originale[k]) {
                                trovata = 1;
                                s=k;
                                diverso=0;
                            }
                            else {
                                trovata = 0;
                                diverso=1;
                                break;
                            }
                        }
                        if (trovata==1) {
                            fprintf(fricodificato, "%s", dizionario[j].ricodificata);
                            i=i+s+1;
                        }
                    }
                }
                if (diverso==1) {
                    fprintf(fricodificato, "%c", riga[i]);
                }
            }
            else {
                fprintf(fricodificato, "\n");
            }
        }
    }



    fclose(fsorgente);
    fclose(fdiz);
    fclose(fricodificato);
    return 0;
}
