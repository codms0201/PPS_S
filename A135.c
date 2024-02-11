#include <stdio.h>
#include <string.h>

#define MAX_TITLE_LENGTH 51
#define MAX_BOOKS 1001

int main() {
    int N;
    scanf("%d", &N);

    char books[MAX_BOOKS][MAX_TITLE_LENGTH];
    int count[MAX_BOOKS] = {0};

    for (int i = 0; i < N; i++) {
        scanf("%s", books[i]);
        count[i]++;
        for (int j = i - 1; j >= 0; j--) {
            if (strcmp(books[i], books[j]) == 0) {
                count[j]++;
                count[i]--;
                break;
            }
        }
    }

    int maxIndex = 0;
    for (int i = 1; i < N; i++) {
        if (count[i] > count[maxIndex] || (count[i] == count[maxIndex] && strcmp(books[i], books[maxIndex]) < 0)) {
            maxIndex = i;
        }
    }

    printf("%s\n", books[maxIndex]);

    return 0;
}
