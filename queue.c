#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *head;
    struct node *tail;
};

struct node* newNode(int data) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void enqueue(struct queue *q, int data) {
    struct node *temp = newNode(data);
    if (q->tail == NULL) {
        q->head = q->tail = temp;
        return;
    }
    q->tail->next = temp;
    q->tail = temp;
}

int dequeue(struct queue *q) {
    if (q->head == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    struct node *temp = q->head;
    int data = temp->data;
    q->head = q->head->next;
    if (q->head == NULL) {
        q->tail = NULL;
    }
    free(temp);
    return data;
}

int main() {
    struct queue q;
    q.head = q.tail = NULL;

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    return 0;
}