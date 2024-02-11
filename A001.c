#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 비교 함수
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// 과자를 나눠주는 함수
int findContentChildren(int* g, int gSize, int* s, int sSize) {
    // 배열을 정렬
    qsort(g, gSize, sizeof(int), compare);
    qsort(s, sSize, sizeof(int), compare);

    int contentChildren = 0;
    int i = 0, j = 0;

    // 욕심 지수와 과자 크기를 비교하면서 나눠주기
    while (i < gSize && j < sSize) {
        if (s[j] >= g[i]) {
            // 과자 크기가 욕심 지수보다 크거나 같으면 자녀를 만족시키고 다음 자녀와 과자로 넘어감
            contentChildren++;
            i++;
        }
        j++;
    }

    return contentChildren;
}

int main() {
    int gSize, sSize;

    // 욕심 지수 배열 입력
    printf("각 자녀의 욕심 지수를 입력하세요 (띄어쓰기로 구분): ");
    
    // 배열 동적 할당 및 입력 받기
    int* g = NULL;
    char buffer[256];
    fgets(buffer, sizeof(buffer), stdin);
    gSize = 0;
    char* token = strtok(buffer, " ");
    while (token != NULL) {
        g = realloc(g, (gSize + 1) * sizeof(int));
        g[gSize++] = atoi(token);
        token = strtok(NULL, " ");
    }

    // 과자 크기 배열 입력
    printf("각 과자의 크기를 입력하세요 (띄어쓰기로 구분): ");

    // 배열 동적 할당 및 입력 받기
    int* s = NULL;
    fgets(buffer, sizeof(buffer), stdin);
    sSize = 0;
    token = strtok(buffer, " ");
    while (token != NULL) {
        s = realloc(s, (sSize + 1) * sizeof(int));
        s[sSize++] = atoi(token);
        token = strtok(NULL, " ");
    }

    int result = findContentChildren(g, gSize, s, sSize);

    printf("최대로 만족시킬 수 있는 자녀의 수: %d\n", result);

    // 동적으로 할당한 배열들의 메모리 해제
    free(g);
    free(s);

    return 0;
}
