#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bst {
    int data;
    struct bst *left;
    struct bst *right;
    struct list *list_head;
} bst_t;

typedef struct list {
    char name[101];
    struct list *next;
} list_t;

void insert_list(list_t **list, char *name) {
    list_t *newnode = (list_t *)malloc(sizeof(list_t));
    strncpy(newnode->name, name, 100);
    newnode->name[100] = '\0';
    newnode->next = *list;
    *list = newnode;
}

bst_t *insert_bst(bst_t **root, int data, char *name) {
    // If the tree is empty, create a new node
    if (*root == NULL) {
        *root = (bst_t *)malloc(sizeof(bst_t));
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
        insert_list(&(*root)->list_head, name);
        return *root;
    }
    // If the data is less than the current node's data, insert into the left subtree
    else if (data < (*root)->data) {
        return insert_bst(&(*root)->left, data, name);
    }
    // If the data is greater than the current node's data, insert into the right subtree
    else if (data > (*root)->data) {
        return insert_bst(&(*root)->right, data, name);
    }
    // If the data matches the current node's data, add the name to the linked list
    else {
        insert_list(&(*root)->list_head, name);
        (*root)->data = data;
        return *root;
    }
}

bst_t *insert(char *name) {
    FILE *fp = fopen(name, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", name);
        exit(EXIT_FAILURE);
    }
    bst_t *root = NULL; //root of the tree initialized as NULL
    int data; //int number read from file
    char name_buf[101]; //buffer to store the strings read from the file
    while (fscanf(fp, "%d %100s", &data, name_buf) == 2) {
        insert_bst(&root, data, name_buf);
        fgetc(fp);
    }
    fclose(fp);
    return root;
}