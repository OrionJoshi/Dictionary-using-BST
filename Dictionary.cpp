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
  struct BSTnode * createNode(char *word, char *meaning) {
        struct BSTnode *newnode;
        newnode = (struct BSTnode *)malloc(sizeof(struct BSTnode));
        strcpy(newnode->word, word);
        strcpy(newnode->meaning, meaning);
        newnode->left = newnode->right = NULL;
        return newnode;
  }

  void insert(char *word, char *meaning) {
        struct BSTnode *parent = NULL, *current = NULL, *newnode = NULL;
        int res = 0;
        if (!root) {
                root = createNode(word, meaning);
                return;
        }
        for (current = root; current !=NULL;
           current = (res > 0) ? current->right : current->left) {
                res = strcasecmp(word, current->word);
                if (res == 0) {
                        printf("Duplicate entry!!\n");
                        return;
                }
                parent = current;
        }
        newnode = createNode(word, meaning);
        res > 0 ? (parent->right = newnode) : (parent->left = newnode);
        return;
  }

  void deleteNode(char *str) {
        struct BSTnode *parent = NULL, *current = NULL, *temp = NULL;
        int flag = 0, res = 0;
        if (!root) {
                printf("BST is not present!!\n");
                return;
        }
        current = root;
        while (1) {
                res = strcasecmp(current->word, str);
                if (res == 0)
                        break;
                flag = res;
                parent = current;
                current = (res > 0) ? current->left : current->right;
                if (current == NULL)
                        return;
        }
        /* deleting leaf node */
        if (current->right == NULL) {
                if (current == root && current->left == NULL) {
                        free(current);
                        root = NULL;
                        return;
                } else if (current == root) {
                        root = current->left;
                        free (current);
                        return;
                }

                flag > 0 ? (parent->left = current->left) :
                                (parent->right = current->left);
        } else {
                /* delete node with single child */
                temp = current->right;
                if (!temp->left) {
                        temp->left = current->left;
                        if (current == root) {
                                root = temp;
                                free(current);
                                return;
                        }
                        flag > 0 ? (parent->left = temp) :
                                        (parent->right = temp);
                } else {
                        /* delete node with two children */
                        struct BSTnode *successor = NULL;
                        while (1) {
                                successor = temp->left;
                                if (!successor->left)
                                        break;
                                temp = successor;
                        }
                        temp->left = successor->right;
                        successor->left = current->left;
                        successor->right = current->right;
                        if (current == root) {
                                root = successor;
                                free(current);
                                return;
                        }
                        (flag > 0) ? (parent->left = successor) :
                                        (parent->right = successor);
                }
        }
        free (current);
        return;
  }

  void findElement(char *str) {
        struct BSTnode *temp = NULL;
        int flag = 0, res = 0;
        if (root == NULL) {
                printf("Binary Search Tree is out of station!!\n");
                return;
        }
        temp = root;
        while (temp) {
                if ((res = strcasecmp(temp->word, str)) == 0) {
                        printf("Word   : %s", str);
                        printf("Meaning: %s", temp->meaning);
                        flag = 1;
                        break;
                }
                temp = (res > 0) ? temp->left : temp->right;
        }
        if (!flag)
                printf("Search Element not found in Binary Search Tree\n");
        return;
  }

  void inorderTraversal(struct BSTnode *myNode) {
        if (myNode) {
                inorderTraversal(myNode->left);
                printf("Word    : %s", myNode->word);
                printf("Meaning : %s", myNode->meaning);
                printf("\n");
                inorderTraversal(myNode->right);
        }
        return;
  }


