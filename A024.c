#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

bool lemonadeChange(int* bills, int billsSize) {
    int five = 0, ten = 0;

    for (int i = 0; i < billsSize; i++) {
        if (bills[i] == 5) {
            five++;
        } else if (bills[i] == 10) {
            five--;
            ten++;
        } else if (ten > 0) {
            ten--;
            five--;
        } else {
            five -= 3;
        }

        if (five < 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int bills[] = {5, 5, 5, 10, 20};
    int billsSize = sizeof(bills) / sizeof(bills[0]);

    bool result = lemonadeChange(bills, billsSize);

    if (result) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
