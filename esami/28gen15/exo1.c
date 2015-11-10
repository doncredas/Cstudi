#include <stdio.h>
#include <stdlib.h>


typedef enum { false, true } bool;
typedef struct { int numR; int numC; } numeroRC;
float** create(int, int);
void read(float**, int, int);
void print(float**, int, int);
numeroRC trova_righe_colonne(float**, float*, int, int);
bool trovaRighe(float**, float*, int, int);
bool trovaColonne(float**, float*, int, int);

int main() {
    int r,c,i,j;
    printf("Inserisci il numero di righe > ");
    scanf("%d", &r);
    printf("Inserisci il numero di colonne > ");
    scanf("%d", &c);

    float** m = create(r, c);

    printf("------------------- LETTURA DELLA MATRICE ----------------\n");
    read(m, r, c);
    printf("------------------- PRINT DELLA MATRICE -------------------\n");
    print(m, r, c);

    printf("------------------- TROVA RIGHE COLONNE --------------------\n");

    float v[] = { 3, 3, 3 };
    numeroRC numRC = trova_righe_colonne(m, v, r, c);

    printf("Il y a %d numero di righe perfettamente uguali\n", numRC.numR);
    printf("Il y a %d numero di colonne uguali\n", numRC.numC);

    return 0;
}

float** create(int r, int c){
    float** m = (float**) malloc (r * sizeof(float*));

    if (m == NULL) {
        printf("Memoria non disponibile!!");
        free(m);
        exit(-1);
    } else {
        int i, j;
        for(i = 0; i < c; i++){
            m[i] = (float *) malloc (sizeof(float));
            if (m[i] == NULL) {
                printf("Memoria non disponibile!!");
                free(m);
                exit(-1);
            }
        }

        return m;
    }
}

void print(float** m, int r, int c){
    int i, j;
    for (i = 0; i < r; ++i) {
        for (j = 0; j < c; ++j) {
            printf("m[%d][%d] = %f", i, j, m[i][j]);
            printf("\n");
        }
    }
}

void read(float** m, int r, int c){
    int i, j;
    for (i = 0; i < r; ++i) {
        for (j = 0; j < c; ++j) {
            printf("Inserisci l'elemento m[%d][%d] > ", i, j);
            scanf("%f", &m[i][j]);
        }
    }
}

bool trovaRighe(float** m, float* v, int r, int c) {
    int i;
    for (i = 0; i < c; ++i) {
        if (m[r][i] != v[i]) {
            return false;
        }
    }
    return true;
}

bool trovaColonne(float** m, float* v, int r, int c) {
    int i, j, presente = 0, count = 0;
    for (i = 0; i < r; ++i) {
        for (j = 0; j < r; ++j) {
            if (m[j][c] == v[i]) {
                presente++;
            }
        }
        if (presente == 0) count++;
        if (count == 2) return false;
    }

    return true;
}

numeroRC trova_righe_colonne(float** m, float* v, int r, int c){
    int i, j, countR = 0, countC = 0;
    numeroRC nrc;
    for (i = 0; i < r; ++i) {
        if (trovaRighe(m, v, i, c)) {
            countR++;
        }
    }
    for (j = 0; j < c; ++j) {
        if (trovaColonne(m, v, r, j)) {
            countC++;
        }
    }

    nrc.numR = countR;
    nrc.numC = countC;

    return nrc;
}