#include <stdio.h>

int main() {
    int test_cases;
    scanf("%d", &test_cases);

    for (int i = 0; i < test_cases; i++) {
        int n;
        scanf("%d", &n);

        int scores[n];
        int sum = 0;

        for (int j = 0; j < n; j++) {
            scanf("%d", &scores[j]);
            sum += scores[j];
        }

        double average = (double)sum / n;
        int count_above_average = 0;

        for (int j = 0; j < n; j++) {
            if (scores[j] > average) {
                count_above_average++;
            }
        }

        double percentage_above_average = ((double)count_above_average / n) * 100;
        printf("%.3lf%%\n", percentage_above_average);
    }

    return 0;
}
