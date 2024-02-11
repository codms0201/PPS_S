#include <stdio.h>
#include <ctype.h>

int main() {
    int count[26] = {0};
    char word[1000001];

    scanf("%s", word);

    for (int i = 0; word[i] != '\0'; i++) {
        if (isalpha(word[i])) {
            int index = tolower(word[i]) - 'a';
            count[index]++;
        }
    }

    int maxCount = 0;
    int maxIndex = -1;
    for (int i = 0; i < 26; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            maxIndex = i;
        } else if (count[i] == maxCount) {
            maxIndex = -1;
        }
    }

    if (maxIndex != -1) {
        printf("%c\n", 'A' + maxIndex);
    } else {
        printf("?\n");
    }

    return 0;
}
