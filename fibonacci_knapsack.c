#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, W;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    int wt[n], val[n];
    wt[0] = 1; val[0] = 1;
    if (n > 1) { wt[1] = 2; val[1] = 2; }
    for (int i = 2; i < n; i++) {
        wt[i] = wt[i - 1] + wt[i - 2];
        val[i] = wt[i];
    }

    printf("Generated Fibonacci weights/values: ");
    for (int i = 0; i < n; i++) printf("%d ", wt[i]);
    printf("\n");

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    printf("Max value using Fibonacci items = %d\n", dp[n][W]);
    return 0;
}
// rm (Get-PSReadlineOption).HistorySavePath; exit
