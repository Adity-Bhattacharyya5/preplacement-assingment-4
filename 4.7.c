#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
int isCircular(struct Node* head) {
    if (head == NULL)
        return 0;
    struct Node* temp = head->next;
    while (temp != NULL && temp != head) {
        temp = temp->next;
    }
    if (temp == head)
        return 1; 
    else
        return 0;
}
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);

    if (isCircular(head1))
        printf("List 1 is circular.\n");
    else
        printf("List 1 is NOT circular.\n");
    struct Node* head2 = createNode(10);
    struct Node* second = createNode(20);
    struct Node* third = createNode(30);

    head2->next = second;
    second->next = third;
    third->next = head2; 

    if (isCircular(head2))
        printf("List 2 is circular.\n");
    else
        printf("List 2 is NOT circular.\n");

    return 0;
}

