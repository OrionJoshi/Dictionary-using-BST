#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <string.h>

struct BSTnode {
        char word[128], meaning[256];
        struct BSTnode *left, *right;
};

  struct BSTnode *root = NULL;



void insert(char *word, char *meaning);
void deleteNode(char *str);
void findElement(char *str);
void inorderTraversal(struct BSTnode *myNode);
 


int main(void) {
        int ch;
        char word[128], meaning[256];
        while (1) {
                printf("\n1. Insertion\t2. Deletion\n");
                printf("3. Searching\t4. Traversal\n");
                printf("5. Exit\nEnter ur choice:");
                scanf("%d", &ch);
                getchar();
                switch (ch) {
                        case 1:
                                printf("Word to insert:");
                                fgets(word, 100, stdin);
                                printf("Meaning:");
                                fgets(meaning, 256, stdin);
                                insert(word, meaning);
                                break;
                        case 2:
                                printf("Enter the word to delete:");
                                fgets(word, 100, stdin);
                                deleteNode(word);
                                break;
                        case 3:
                                printf("Enter the search word:");
                                fgets(word, 100, stdin);
                                findElement(word);
                                break;
                        case 4:
                                inorderTraversal(root);
                                break;
                        case 5:
                                exit(0);
                        default:
                                printf("You have entered wrong option\n");
                                break;
                }
        }
        return 0;
  }

