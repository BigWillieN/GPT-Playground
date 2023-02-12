#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data;
    struct node *left;
    struct node *right;
};

struct node* createNode(char data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right= NULL;
    return node;
}


void doubleTree(struct node *root, char flag){
  
    if (root == NULL) {
        return;
    }
  
    struct node *duplicate = createNode(root->data);

    if (flag =='L'){
        duplicate->left = root->left;
        root->left = duplicate;
        if(root->left != NULL)
          doubleTree(root->left->left, flag);
        doubleTree(root->right, flag);
    }
    else if (flag =='R'){
        duplicate->right = root->right;
        root->right = duplicate;
        if(root->right != NULL)
          doubleTree(root->right->right, flag);
        doubleTree(root->left, flag);
    }
}

int main() {
    struct node *root = createNode('A');
    root->left = createNode('B');
    root->right = createNode('C');

}
