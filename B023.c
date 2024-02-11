#include <stdlib.h>

typedef struct {
    int k;
    int* heap;
    int size;
} KthLargest;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(KthLargest* obj, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (obj->heap[parent] > obj->heap[index]) {
            swap(&obj->heap[parent], &obj->heap[index]);
            index = parent;
        } else {
            break;
        }
    }
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->k = k;
    obj->heap = (int*)malloc(k * sizeof(int));
    obj->size = 0;

    for (int i = 0; i < numsSize; i++) {
        kthLargestAdd(obj, nums[i]);
    }

    return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->size < obj->k) {
        obj->heap[obj->size++] = val;
        heapifyUp(obj, obj->size - 1);
    } else if (val > obj->heap[0]) {
        obj->heap[0] = val;
        heapifyUp(obj, 0);
    }

    return obj->heap[0];
}

void kthLargestFree(KthLargest* obj) {
    free(obj->heap);
    free(obj);
}

int main() {
    int k = 3;
    int nums[] = {4, 5, 8, 2};

    KthLargest* kthLargest = kthLargestCreate(k, nums, sizeof(nums) / sizeof(nums[0]));

    printf("%d\n", kthLargestAdd(kthLargest, 3));
    printf("%d\n", kthLargestAdd(kthLargest, 5)); 
    printf("%d\n", kthLargestAdd(kthLargest, 10));
    printf("%d\n", kthLargestAdd(kthLargest, 9));
    printf("%d\n", kthLargestAdd(kthLargest, 4)); 

    kthLargestFree(kthLargest);

    return 0;
}
