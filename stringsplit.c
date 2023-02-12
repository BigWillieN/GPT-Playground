

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node_t;
struct node_t *splitStr(char *str);
struct node_t *newNode(char *str);

struct node_t {
    char *str;
    struct node_t *next;
};

struct node_t *newNode(char *str) {
  struct node_t *node = (struct node_t *)malloc(sizeof(struct node_t));
  node->str = str;
  node->next = NULL;
  return node;
}

struct node_t *splitStr (char *str){
  struct node_t *head = NULL;
  char *p = strtok (str, ".");
  while (p!=NULL){
    struct node_t *node = newNode(p);
    node->next = head;
    head = node;
    p = strtok(NULL, ".");
  }
  return head;
}


void printList(struct node_t *head){
    while (head!=NULL){
        printf("%s->", head->str);
        head = head->next;
    }
    printf("NULL\n");
  
}

int main(){
    char str[]= "a.bb.ccc.dddd.eeee.ffff";
    struct node_t *head = splitStr(str);
    printList(head);
    return 0;
}