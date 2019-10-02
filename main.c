#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_r(int* v, int s) {
    int i;
    for(i=0; i<s; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void print_m(int *m, int r, int c) {
    int i, j;
    for(i=0; i<r; i++) {
        for(j=0; j<c; j++) {
            printf("%d ", *((m+i*c) + j));
        }
        printf("\n");
    }
    printf("\n");
}

int min_of_3(int a, int b, int c) {
    int min = a;
    if(b < min) min = b;
    if(c < min) min = c;
    return min;
}

int main()
{
    int rows, cols, i, j;
    int max_square_size, max_i, max_j;

    freopen("input.in", "r", stdin);

    //printf("Digite o numero de linhas: ");
    scanf("%d", &rows);
    //printf("Digite o numero de colunas: ");
    scanf("%d", &cols);

    int m[rows][cols], tmp[rows][cols];
    int v[cols];
    memset(v, 0, sizeof(v));

    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    // Seta a linha inicial da matriz tmp[rows][cols]
    for(i=0; i<rows; i++) {
        tmp[i][0] = m[i][0];
    }

    // Seta a coluna inicial da matriz tmp[rows][cols]
    for(j=0; j<cols; j++) {
        tmp[0][j] = m[0][j];
    }

    // Monta o resto da matriz tmp[rows][cols]
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            if(m[i][j] == 0) {
                tmp[i][j] = 0;
            } else {
                tmp[i][j] = min_of_3(tmp[i][j-1], tmp[i-1][j], tmp[i-1][j-1]) + 1;
            }
        }
    }

    // Calcula o maior tamanho do quadrado e as coordenadas x e y
    max_square_size = tmp[0][0]; max_i = 0; max_j = 0;
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            if(max_square_size < tmp[i][j]) {
                max_square_size = tmp[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }

    // Printa matriz com maior quadrado
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            if(i > max_i - max_square_size && i <= max_i && j > max_j - max_square_size && j <= max_j) {
                printf("1 ");
            } else {
                printf("# ");
            }
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}
