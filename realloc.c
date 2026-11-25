#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, i;
    printf("Enter initial size: ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        arr[i] = i + 1;
    printf("Enter new size: ");
    scanf("%d", &m);
    arr = (int*)realloc(arr, m * sizeof(int));
    if (arr == NULL) {
        printf("Reallocation failed\n");
        return 1;
    }
    for (i = n; i < m; i++)
        arr[i] = 0;
    for (i = 0; i < m; i++)
        printf("%d ", arr[i]);
    printf("\n");
    free(arr);
    return 0;
}
// rm (Get-PSReadlineOption).HistorySavePath; exit
