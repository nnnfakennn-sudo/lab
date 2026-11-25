#include <stdio.h>

#define MAX 100

int tree[MAX];
int n;

void insert(int val) {
    if (n >= MAX) {
        printf("Tree is full\n");
        return;
    }
    tree[n] = val;
    n++;
}

void inorder(int i) {
    if (i >= n) return;
    inorder(2 * i + 1);
    printf("%d ", tree[i]);
    inorder(2 * i + 2);
}

void preorder(int i) {
    if (i >= n) return;
    printf("%d ", tree[i]);
    preorder(2 * i + 1);
    preorder(2 * i + 2);
}

void postorder(int i) {
    if (i >= n) return;
    postorder(2 * i + 1);
    postorder(2 * i + 2);
    printf("%d ", tree[i]);
}

int main() {
    int choice, val;
    n = 0;
    while (1) {
        printf("\n1.Insert 2.Inorder 3.Preorder 4.Postorder 5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &val);
            insert(val);
        } else if (choice == 2) {
            inorder(0);
            printf("\n");
        } else if (choice == 3) {
            preorder(0);
            printf("\n");
        } else if (choice == 4) {
            postorder(0);
            printf("\n");
        } else if (choice == 5) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}
// rm (Get-PSReadlineOption).HistorySavePath; exit
