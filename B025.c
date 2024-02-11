#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void deleteNode(struct ListNode* node) {
    if (node == NULL || node->next == NULL) {
        return;
    }

    struct ListNode* temp = node->next;
    node->val = temp->val;
    node->next = temp->next;

    free(temp);
}

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

int main() {
    struct ListNode* head = createNode(4);
    head->next = createNode(5);
    head->next->next = createNode(1);
    head->next->next->next = createNode(9);

    struct ListNode* nodeToDelete = head->next;

    printf("Original Linked List: ");
    printList(head);

    deleteNode(nodeToDelete);

    printf("Linked List after deletion: ");
    printList(head);

    while (head != NULL) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
