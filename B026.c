#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;
    struct ListNode* current = &dummy;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    if (list1 != NULL) {
        current->next = list1;
    } else {
        current->next = list2;
    }

    return dummy.next;
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
    struct ListNode* list1 = createNode(1);
    list1->next = createNode(2);
    list1->next->next = createNode(4);

    struct ListNode* list2 = createNode(1);
    list2->next = createNode(3);
    list2->next->next = createNode(4);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    struct ListNode* mergedList = mergeTwoLists(list1, list2);

    printf("Merged List: ");
    printList(mergedList);

    while (mergedList != NULL) {
        struct ListNode* temp = mergedList;
        mergedList = mergedList->next;
        free(temp);
    }

    return 0;
}
