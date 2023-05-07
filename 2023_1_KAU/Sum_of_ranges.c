#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int** square = (int**)malloc(sizeof(int*) * (n + 1));
    for (int i = 0; i <= n; i++) {
        square[i] = (int*)malloc(sizeof(int) * (n + 1));
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int num;
            scanf("%d", &num);
            square[i][j] = num + square[i - 1][j] + square[i][j - 1] - square[i - 1][j - 1];
        }
    }

    int result[m];
    for (int i = 0; i < m; i++){
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        result[i] = square[c][d] - square[a - 1][d] - square[c][b - 1] + square[a - 1][b - 1];
    }
    for (int i = 0; i < m; i++){
      printf("%d\n", result[i]);
    }

    for (int i = 0; i <= n; i++) {
        free(square[i]);
    }
    free(square);

    return 0;
}