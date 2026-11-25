#include <stdio.h>

int main() {
    int n, i;
    long long a = 0, b = 1, next;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series: ");
    for (i = 0; i < n; i++) {
        printf("%lld ", a);
        next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
    return 0;
}
// rm (Get-PSReadlineOption).HistorySavePath; exit
