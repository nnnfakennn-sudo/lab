#include <stdio.h>
#include <stdlib.h>

struct Item {
    int val, wt;
    double ratio;
};

int cmp(const void *a, const void *b) {
    struct Item *i1 = (struct Item *)a;
    struct Item *i2 = (struct Item *)b;
    if (i2->ratio > i1->ratio) return 1;
    if (i2->ratio < i1->ratio) return -1;
    return 0;
}

int main() {
    int n, W;
    printf("Enter number of items and capacity: ");
    scanf("%d %d", &n, &W);

    struct Item items[n];
    printf("Enter value and weight for each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].val, &items[i].wt);
        items[i].ratio = (double)items[i].val / items[i].wt;
    }

    qsort(items, n, sizeof(items[0]), cmp);

    double totalVal = 0.0;
    int curWt = 0;

    for (int i = 0; i < n; i++) {
        if (curWt + items[i].wt <= W) {
            curWt += items[i].wt;
            totalVal += items[i].val;
        } else {
            int remain = W - curWt;
            totalVal += items[i].val * ((double)remain / items[i].wt);
            break;
        }
    }

    printf("Maximum Value = %.2f\n", totalVal);
    return 0;
}
// rm (Get-PSReadlineOption).HistorySavePath; exit
