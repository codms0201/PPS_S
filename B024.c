#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int score;
    int index;
} Athlete;

int compare(const void *a, const void *b) {
    return ((Athlete*)b)->score - ((Athlete*)a)->score;
}

char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    Athlete* athletes = malloc(scoreSize * sizeof(Athlete));
    for (int i = 0; i < scoreSize; i++) {
        athletes[i].score = score[i];
        athletes[i].index = i;
    }

    qsort(athletes, scoreSize, sizeof(Athlete), compare);

    char** result = (char**)malloc(scoreSize * sizeof(char*));
    for (int i = 0; i < scoreSize; i++) {
        result[i] = (char*)malloc(20 * sizeof(char));
    }

    for (int i = 0; i < scoreSize; i++) {
        int index = athletes[i].index;
        if (i == 0) {
            sprintf(result[index], "Gold Medal");
        } else if (i == 1) {
            sprintf(result[index], "Silver Medal");
        } else if (i == 2) {
            sprintf(result[index], "Bronze Medal");
        } else {
            sprintf(result[index], "%d", i + 1);
        }
    }

    *returnSize = scoreSize;

    free(athletes);

    return result;
}

int main() {
    int score[] = {5, 4, 3, 2, 1};
    int scoreSize = sizeof(score) / sizeof(score[0]);
    int returnSize;

    char** output = findRelativeRanks(score, scoreSize, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", output[i]);
        free(output[i]);
    }

    free(output);

    return 0;
}
