#include <stdio.h>

long long fact(int n) {
    long long f = 1;
    for (int i = 1; i <= n; i++)
        f *= i;
    return f;
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact(n) / (fact(r) * fact(n - r));
}

int main() {
    int n, r;
    printf("Enter n and r: ");
    scanf("%d %d", &n, &r);
    printf("%d C %d = %lld\n", n, r, nCr(n, r));
    return 0;
}
// rm (Get-PSReadlineOption).HistorySavePath; exit
