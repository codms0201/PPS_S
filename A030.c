#include <stdio.h>

int main() {
    int N, current_mood;
    scanf("%d %d", &N, &current_mood);

    double good_to_good, good_to_bad, bad_to_good, bad_to_bad;
    scanf("%lf %lf %lf %lf", &good_to_good, &good_to_bad, &bad_to_good, &bad_to_bad);

    double dp[2][2] = {0};

    dp[0][current_mood] = 1.0;

    for (int i = 1; i <= N; i++) {
        dp[i % 2][0] = dp[(i - 1) % 2][0] * good_to_good + dp[(i - 1) % 2][1] * bad_to_good;
        dp[i % 2][1] = dp[(i - 1) % 2][0] * good_to_bad + dp[(i - 1) % 2][1] * bad_to_bad;
    }

    printf("%.1lf\n", dp[N % 2][0] * 1000.0 + 0.5);
    printf("%.1lf\n", dp[N % 2][1] * 1000.0 + 0.5);

    return 0;
}
