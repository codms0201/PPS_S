#include <stdio.h>
#include <string.h>

int solution(char s[]) {
    int answer = strlen(s);

    for (int i = 1; i <= strlen(s) / 2; i++) {
        char compressed[1001] = "";
        char prev[1001];
        strncpy(prev, s, i);
        prev[i] = '\0';
        int count = 1;

        for (int j = i; j <= strlen(s); j += i) {
            if (strcmp(prev, s + j) == 0) {
                count++;
            } else { 
                if (count > 1) {
                    char temp[10];
                    sprintf(temp, "%d", count);
                    strcat(compressed, temp);
                }
                strcat(compressed, prev);

                strncpy(prev, s + j, i);
                prev[i] = '\0';
                count = 1;
            }
        }

        if (count > 1) {
            char temp[10];
            sprintf(temp, "%d", count);
            strcat(compressed, temp);
        }
        strcat(compressed, prev);

        answer = (answer < strlen(compressed)) ? answer : strlen(compressed);
    }

    return answer;
}

int main() {
    printf("%d\n", solution("aabbaccc"));
    printf("%d\n", solution("ababcdcdababcdcd"));
    printf("%d\n", solution("abcabcdede"));
    printf("%d\n", solution("abcabcabcabcdededededede")); 
    printf("%d\n", solution("xababcdcdababcdcd"));

    return 0;
}
