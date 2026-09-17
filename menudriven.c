#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int arr[MAX];
int n = 0;

void insertElement() {
    int pos, val;
    printf("Enter value to insert: ");
    scanf("%d", &val);
    printf("Enter position (0 to %d): ", n);
    scanf("%d", &pos);
    if (pos < 0 || pos > n || n >= MAX) {
        printf("Invalid position\n");
        return;
    }
    for (int i = n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = val;
    n++;
}

void deleteElement() {
    int pos;
    if (n == 0) {
        printf("Array is empty\n");
        return;
    }
    printf("Enter position to delete (0 to %d): ", n - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= n) {
        printf("Invalid position\n");
        return;
    }
    for (int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
}

void searchElement() {
    int val, found = 0;
    printf("Enter value to search: ");
    scanf("%d", &val);
    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Not found\n");
}

void displayElements() {
    if (n == 0) {
        printf("Array is empty\n");
        return;
    }
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1.Insert 2.Delete 3.Search 4.Display 5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insertElement(); break;
            case 2: deleteElement(); break;
            case 3: searchElement(); break;
            case 4: displayElements(); break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
