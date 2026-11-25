#include <stdio.h>
#include <string.h>

int main() {
    char str[100], pat[100];
    printf("Enter main string: ");
    scanf("%s", str);
    printf("Enter pattern to find: ");
    scanf("%s", pat);

    int n = strlen(str);
    int m = strlen(pat);
    int pos = -1;

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (str[i + j] != pat[j])
                break;
        }
        if (j == m) {
            pos = i;
            break;
        }
    }

    if (pos != -1)
        printf("Pattern found at index %d (position %d)\n", pos, pos + 1);
    else
        printf("Pattern not found\n");

    return 0;
}
// rm (Get-PSReadlineOption).HistorySavePath; exit
