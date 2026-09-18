#include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

#define SIZE 26

struct TrieNode {
 struct TrieNode *child[SIZE];
 int end;
 };

struct TrieNode *createNode() {
 struct TrieNode *newNode;
 int i;

 newNode = malloc(sizeof(struct TrieNode));

 if (newNode == NULL) {
 printf("Memory allocation failed\n");
 exit(1);
 }

 newNode->end = 0;

 for (i = 0; i < SIZE; i++) {
 newNode->child[i] = NULL;
 }

 return newNode;
 }

void insert(struct TrieNode *root, char word[]) {
 struct TrieNode *curr = root;
 int i, index;

 for (i = 0; word[i] != '\0'; i++) {
 index = word[i] - 'a';

 if (curr->child[index] == NULL) {
 curr->child[index] = createNode();
 }

 curr = curr->child[index];
 }

 curr->end = 1;

 printf("Word inserted successfully.\n");
 }

int search(struct TrieNode *root, char word[]) {
 struct TrieNode *curr = root;
 int i, index;

 for (i = 0; word[i] != '\0'; i++) {
 index = word[i] - 'a';

 if (curr->child[index] == NULL) {
 return 0;
 }

 curr = curr->child[index];
 }

 return curr->end;
 }

void deleteWord(struct TrieNode *root, char word[]) {
 struct TrieNode *curr = root;
 int i, index;

 for (i = 0; word[i] != '\0'; i++) {
 index = word[i] - 'a';

 if (curr->child[index] == NULL) {
 printf("Word not found.\n");
 return;
 }

 curr = curr->child[index];
 }

 if (curr->end == 1) {
 curr->end = 0;
 printf("Word deleted successfully.\n");
 } else {
 printf("Word not found.\n");
 }
 }

void display(struct TrieNode *root, char word[], int level) {
 int i;

 if (root == NULL) {
 return;
 }

 if (root->end == 1) {
 word[level] = '\0';
 printf("%s\n", word);
 }

 for (i = 0; i < SIZE; i++) {
 if (root->child[i] != NULL) {
 word[level] = i + 'a';
 display(root->child[i], word, level + 1);
 }
 }
 }

int main() {
 struct TrieNode *root;
 char word[20];
 char displayWord[20];
 int choice;

 root = createNode();

 while (1) {
 printf("\n--- TRIE MENU ---\n");
 printf("1. Insert Word\n");
 printf("2. Search Word\n");
 printf("3. Delete Word\n");
 printf("4. Display Words\n");
 printf("5. Exit\n");

 printf("Enter your choice: ");
 scanf("%d", &choice);

 switch (choice) {

 case 1:
 printf("Enter word: ");
 scanf("%19s", word);

 insert(root, word);
 break;

 case 2:
 printf("Enter word to search: ");
 scanf("%19s", word);

 if (search(root, word)) {
 printf("Word found.\n");
 } else {
 printf("Word not found.\n");
 }
 break;

 case 3:
 printf("Enter word to delete: ");
 scanf("%19s", word);

 deleteWord(root, word);
 break;

 case 4:
 printf("\nWords stored in Trie:\n");
 display(root, displayWord, 0);
 break;

 case 5:
 printf("Exiting...\n");
 return 0;

 default:
 printf("Invalid choice.\n");
 }
 }
}
