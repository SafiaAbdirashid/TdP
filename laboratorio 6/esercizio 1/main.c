#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXC 30
#define maxrighe 1000


/* COMANDI DA INSERIRE:
 * DATE = elencare tutte le corse partite in un  certo intervallo di date
 * PARTENZA= elencare tutte le corse partite da una certa fermata
 * CAPOLINEA = elencare tutti le corse aventi una data destinazione
 * RITARDO = elencare tutte le corse che hanno raggiunto la destinazione in ritardo, in un certo intervallo di date
 * CODICE = elencare il ritardo complessivo accumulato dalle corse identificate da un certo codice di tratta*/



/* definisco per enumerazone t_comandi */
typedef enum {
    c_data, c_partenza, c_capolinea, c_ritardo, c_codice, c_fine, c_err
} t_comandi;

t_comandi leggiComando (void);


struct tratte {
    char codice[MAXC];
    char partenza[MAXC];
    char destinazione[MAXC];
    char data[MAXC];
    char hpartenza[MAXC];
    char harrivo[MAXC];
    int ritardo;
};

void menuParola (struct tratte tratta[], int dim);

void strToLower(char s[]);
void data(struct tratte tratta[], int dim);
void partenza(struct tratte tratta[], int dim);
void capolinea(struct tratte tratta[], int dim);
void ritardo(struct tratte tratta[], int dim);
void codice(struct tratte tratta[], int dim);



int main() {
    FILE *f_read;
    struct tratte tratta[maxrighe];
    int i, dim;
    f_read= fopen("../log.txt", "r");
    if (f_read!=NULL) { /* la prima riga e' la dimensione */
        fscanf(f_read, "%d", &dim);
        i=0;
        while (!feof(f_read)) { /* associo ad ogni stringa un campo della struct */
            fscanf(f_read, "%s %s %s %s %s %s %d", tratta[i].codice, tratta[i].partenza, tratta[i].destinazione, tratta[i].data, tratta[i].hpartenza, tratta[i].harrivo, &tratta[i].ritardo);
            i++;
        }
        menuParola(tratta, dim);
    }
    fclose(f_read);
    return 0;
}

void menuParola (struct tratte tratta[], int dim) {
    t_comandi codiceComando;
    int continua=1;

    /* ciclo  controllato da un flag(continua) dove:
     * - si acquisisce la funzione leggiComando e restituisce codiceComando;
     * - lo switch chiama le varie funzioni oppure esce dal menu */
    while (continua) {
        codiceComando = leggiComando();
        switch (codiceComando) {
            case c_data:data(tratta, dim);
                break;
            case c_partenza:partenza(tratta, dim);
                break;
            case c_capolinea:capolinea(tratta, dim);
                break;
            case c_ritardo:ritardo(tratta, dim);
                break;
            case c_codice:codice(tratta, dim);
                break;
            case c_fine: continua=0;
                break;
            case c_err:
            default: printf("comando errato\n");
        }
    }
}

t_comandi leggiComando (void) {
    t_comandi c;
    char cmd[MAXC];
    char *tabella[c_err] = {
            "date", "partenza", "capolinea", "ritardo", "codice"
    };
    printf("inserire comando");
    fflush(stdin);
    scanf("%s", cmd); /* acquisisco comando */
    strToLower(cmd);
    c=c_data;
    while (c<c_err && strcmp(cmd, tabella[c])!=0) {
        c++;
    }
    return (c);
}

void strToLower (char s[]) {
    int i;
    for (int i = 0; s[i] != '\0'; i++) {
        s[i]= tolower(s[i]);
    }
}

/* corse partite in un certo intervallo di date */
void data(struct tratte tratta[], int dim) {
    int i;
    char datecheckstart[MAXC];
    char datecheckend[MAXC];
    fflush(stdin);
    printf("Inserire date\n");
    scanf("%s %s", datecheckstart, datecheckend);
    for (int i = 0; i < dim; i++) {
        if ((strcmp(datecheckstart, tratta[i].data)<0) && (strcmp(datecheckend, tratta[i].data)>0)) {
            printf("%s %s %s %s %s %s %d", tratta[i].codice, tratta[i].partenza, tratta[i].destinazione, tratta[i].data, tratta[i].hpartenza, tratta[i].harrivo, &tratta[i].ritardo);
            printf("\n");
        }
    }
}

/* elenca tutte le corse partite da una certa fermata */
void partenza(struct tratte tratta[], int dim) {
    int i;
    char partenzacheck[MAXC];
    fflush(stdin);
    printf("inserire partenza\n");
    scanf("%s", partenzacheck);
    for (int i = 0; i < dim; i++) {
        if (strcmp(partenzacheck, tratta[i].partenza)==0) {
            printf("%s %s %s %s %s %s %d", tratta[i].codice, tratta[i].partenza, tratta[i].destinazione, tratta[i].data, tratta[i].hpartenza, tratta[i].harrivo, &tratta[i].ritardo);
            printf("\n");
        }
    }
}

/* elenca tutte le corse aventi un dato capolinea */
void capolinea(struct tratte tratta[], int dim) {
    int i;
    char capolineacheck[MAXC];
    fflush(stdin);
    printf("inserire capolinea\n");
    scanf("%s", capolineacheck);
    for (int i = 0; i < dim; i++) {
        if (strcmp(capolineacheck, tratta[i].destinazione)==0) {
            printf("%s %s %s %s %s %s %d", tratta[i].codice, tratta[i].partenza, tratta[i].destinazione, tratta[i].data, tratta[i].hpartenza, tratta[i].harrivo, &tratta[i].ritardo);
            printf("\n");
        }
    }
}

/* elenca tutte le corse che hanno raggiunto la
 * destinazione in ritardo in un certo
 * intervallo di date */
void ritardo(struct tratte tratta[], int dim) {
    int i;
    char datecheckstart[MAXC], datecheckend[MAXC];
    fflush(stdin);
    printf("inserire date\n");
    scanf("%s", datecheckstart);
    for (int i = 0; i < dim; i++) {
        if (strcmp(datecheckstart, tratta[i].data)==0) {
            printf("%s %s %s %s %s %s %d", tratta[i].codice, tratta[i].partenza, tratta[i].destinazione, tratta[i].data, tratta[i].hpartenza, tratta[i].harrivo, &tratta[i].ritardo);
            printf("\n");
        }
    }
}


/* elenca il ritardo complessivo accumulato
 * dalle corse con un certo codice di tratta */
void codice(struct tratte tratta[], int dim) {
    int i, ritardo=0;
    char codicecheck[MAXC];
    fflush(stdin);
    printf("inserire codice tratta\n");
    scanf("%s", codicecheck);
    for (int i = 0; i < dim; i++) {
        if (strcmp(codicecheck, tratta[i].codice)==0) {
            ritardo=ritardo+tratta[i].ritardo;
        }
    }
    printf("%s %d\n", codicecheck, ritardo);
}
