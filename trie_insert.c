#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    int isEndOfWord;
};

struct TrieNode* createNode() {
    struct TrieNode *node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    node->isEndOfWord = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    return node;
}

void insert(struct TrieNode *root, char *key) {
    struct TrieNode *curr = root;
    for (int i = 0; key[i] != '\0'; i++) {
        int index = key[i] - 'a';
        if (curr->children[index] == NULL)
            curr->children[index] = createNode();
        curr = curr->children[index];
    }
    curr->isEndOfWord = 1;
}

int search(struct TrieNode *root, char *key) {
    struct TrieNode *curr = root;
    for (int i = 0; key[i] != '\0'; i++) {
        int index = key[i] - 'a';
        if (curr->children[index] == NULL)
            return 0;
        curr = curr->children[index];
    }
    return curr != NULL && curr->isEndOfWord;
}

int main() {
    struct TrieNode *root = createNode();
    char words[5][20] = {"cat", "car", "card", "dog", "do"};
    for (int i = 0; i < 5; i++)
        insert(root, words[i]);

    char query[20];
    printf("Enter word to search: ");
    scanf("%s", query);
    if (search(root, query))
        printf("Found\n");
    else
        printf("Not found\n");
    return 0;
}
