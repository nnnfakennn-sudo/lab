#include <stdio.h>

int main() {
    int a[10][10], b[10][10], c[10][10];
    int r, col, choice;

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &col);

    printf("Enter Matrix A:\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < col; j++)
            scanf("%d", &a[i][j]);

    printf("Enter Matrix B:\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < col; j++)
            scanf("%d", &b[i][j]);

    printf("\n1. Addition\n2. Multiplication\n3. Transpose of A\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Addition Result:\n");
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < col; j++) {
                c[i][j] = a[i][j] + b[i][j];
                printf("%d ", c[i][j]);
            }
            printf("\n");
        }
    } else if (choice == 2) {
        printf("Multiplication Result:\n");
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < col; j++) {
                c[i][j] = 0;
                for (int k = 0; k < col; k++)
                    c[i][j] += a[i][k] * b[k][j];
                printf("%d ", c[i][j]);
            }
            printf("\n");
        }
    } else if (choice == 3) {
        printf("Transpose of A:\n");
        for (int i = 0; i < col; i++) {
            for (int j = 0; j < r; j++)
                printf("%d ", a[j][i]);
            printf("\n");
        }
    }

    return 0;
}
