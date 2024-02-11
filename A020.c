#include <stdio.h>

int main() {
    int people[4][2];
    int current = 0;
    int max_people = 0;

    for (int i = 0; i < 4; i++) {
        scanf("%d %d", &people[i][0], &people[i][1]);
    }

    for (int i = 0; i < 4; i++) {
        current = current - people[i][0] + people[i][1];
        if (current > max_people) {
            max_people = current;
        }
    }

    printf("%d\n", max_people);

    return 0;
}
