#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct square{
    int x, y, size, order;
} Square;

int compare(struct square *a1, struct square *a2) {
    if(a1->size == a2->size)
        return a1->order < a2->order;
    return a1->size < a2->size;
}

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

int main()
{
    int rows, cols, i, j;

    freopen("input.in", "r", stdin);

    //printf("Digite o numero de linhas: ");
    scanf("%d", &rows);
    //printf("Digite o numero de colunas: ");
    scanf("%d", &cols);

    int m[rows][cols];
    int v[cols];
    memset(v, 0, sizeof(v));

    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    Square squares[MAX_SIZE];
    int sqr_it = 0;

    // Montas os vetores
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            if(m[i][j] == 0) {
                v[j] = 0;
            } else {
                v[j] += m[i][j];
            }
        }

        // Itera o vetor gerado e verifica se existe algum quadrado formado
        for(j=0; j<cols; j++) {
            if(v[j] >= 2) {
                int s = v[j], it, cont=0;
                if(j + s <= cols) {
                    for(it=j; it<j+s; it++) {
                        if(s <= v[it]) cont++;
                    }
                    if(s == cont) {
                        squares[sqr_it].x = i;
                        squares[sqr_it].y = j;
                        squares[sqr_it].size = s;
                        squares[sqr_it].order = sqr_it + 1;
                        sqr_it++;
                    }
                }
            }
        }
    }

    qsort(squares, sqr_it, sizeof(struct square), compare);

    int size = squares[0].size;
    int x = squares[0].x;
    int y = squares[0].y;

    printf("Tamanho do maior quadrado: %d\n\n", squares[0].size);
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            if(i >= x - size + 1 && i <= size && j >= y && j <= y + size - 1) {
                printf("1 ");
            } else {
                printf("# ");
            }
        }
        printf("\n");
    }

    return 0;
}
