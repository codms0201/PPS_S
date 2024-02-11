#include <stdio.h>
#include <stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    // 예외 처리
    if (numRows <= 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    // 반환할 이차원 배열 동적 할당
    int** result = (int**)malloc(numRows * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));
    *returnSize = numRows;

    for (int i = 0; i < numRows; i++) {
        result[i] = (int*)malloc((i + 1) * sizeof(int));
        (*returnColumnSizes)[i] = i + 1;
    }

    // 파스칼의 삼각형 값 계산
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                // 양 끝 값은 항상 1
                result[i][j] = 1;
            } else {
                // 중간 값은 윗 행의 두 값의 합
                result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
            }
        }
    }

    return result;
}

// 예시로 결과 출력하는 함수
void printResult(int** result, int numRows, int* returnColumnSizes) {
    for (int i = 0; i < numRows; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1) {
                printf(", ");
            }
        }
        printf("]");
        if (i < numRows - 1) {
            printf(", ");
        }
    }
}

// 메모리 해제 함수
void freeResult(int** result, int numRows) {
    for (int i = 0; i < numRows; i++) {
        free(result[i]);
    }
    free(result);
}

int main() {
    int numRows;

    // 사용자로부터 numRows 입력 받기
    printf("파스칼의 삼각형을 몇 행까지 생성할까요? ");
    scanf("%d", &numRows);

    int returnSize;
    int* returnColumnSizes;

    int** result = generate(numRows, &returnSize, &returnColumnSizes);

    // 결과 출력
    printf("[");
    printResult(result, numRows, returnColumnSizes);
    printf("]\n");

    // 메모리 해제
    freeResult(result, numRows);
    free(returnColumnSizes);

    return 0;
}
