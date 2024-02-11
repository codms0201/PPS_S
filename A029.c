#include <stdio.h>

int main() {
    long long N;
    scanf("%lld", &N);

    int first_door_method;
    scanf("%d", &first_door_method);

    for (long long i = 2; i <= N; i++) {
        if (i % 2 == 0) {
            printf("%d\n", first_door_method);
        }
        else if (i % 3 == 0) {
            printf("%d\n", 1 - first_door_method);
        }
        else {
            printf("%d\n", 1 - first_door_method);
        }
    }

    return 0;
}
