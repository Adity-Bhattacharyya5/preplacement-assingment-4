#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* pairwiseSwap(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct Node* prev = head;
    struct Node* curr = head->next;

    head = curr;

    while (1) {
        struct Node* next = curr->next;
        curr->next = prev;  
        if (next == NULL || next->next == NULL) {
            prev->next = next;
            break;
        }
        prev->next = next->next;
        prev = next;
        curr = prev->next;
    }
    return head;
}
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    printf("Original list:\n");
    printList(head);

    head = pairwiseSwap(head);

    printf("List after pairwise swap:\n");
    printList(head);

    return 0;
}

