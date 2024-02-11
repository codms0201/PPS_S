#include <stdio.h>

int main() {
    int scores[5][4];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &scores[i][j]);
        }
    }

    int maxScore = 0;
    int winner = 0;

    for (int i = 0; i < 5; i++) {
        int totalScore = 0;
        for (int j = 0; j < 4; j++) {
            totalScore += scores[i][j];
        }

        if (totalScore > maxScore) {
            maxScore = totalScore;
            winner = i + 1;
        }
    }

    printf("%d %d\n", winner, maxScore);

    return 0;
}
