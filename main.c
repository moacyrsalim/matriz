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

    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            if(m[i][j] == 0) {
                v[j] = 0;
            } else {
                v[j] += m[i][j];
            }
        }
        print_r(v, cols);
    }

    return 0;
}
