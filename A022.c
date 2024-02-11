#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int total_time = 0;
    for (int i = 0; i < N; i++) {
        int time;
        scanf("%d", &time);
        total_time += time;
    }

    int young_sik_fee = ((total_time / 30) + 1) * 10;

    int min_sik_fee = ((total_time / 60) + 1) * 15;

    if (young_sik_fee < min_sik_fee) {
        printf("Y %d\n", young_sik_fee);
    } else if (young_sik_fee > min_sik_fee) {
        printf("M %d\n", min_sik_fee);
    } else {
        printf("Y M %d\n", young_sik_fee);
    }

    return 0;
}
