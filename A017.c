#include <stdio.h>

int main() {
    char roomNumber[7];
    int count[10] = {0};

    scanf("%s", roomNumber);

    for (int i = 0; roomNumber[i] != '\0'; i++) {
        int digit = roomNumber[i] - '0';
        count[digit]++;
    }

    int sixNineCount = count[6] + count[9];
    if (sixNineCount % 2 == 1) {
        sixNineCount = (sixNineCount / 2) + 1;
    } else {
        sixNineCount /= 2;
    }

    int maxCount = 0;
    for (int i = 0; i < 10; i++) {
        if (i != 6 && i != 9 && count[i] > maxCount) {
            maxCount = count[i];
        }
    }

    int sets = (maxCount > sixNineCount) ? maxCount : sixNineCount;

    printf("%d\n", sets);

    return 0;
}
