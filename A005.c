#include <stdio.h>
#include <string.h>

int isSubset(char* skill, char* skill_tree) {
    int skill_order[26];
    memset(skill_order, -1, sizeof(skill_order));

    for (int i = 0; skill[i] != '\0'; i++) {
        skill_order[skill[i] - 'A'] = i;
    }

    int prev = -1;
    for (int i = 0; skill_tree[i] != '\0'; i++) {
        int current = skill_tree[i] - 'A';
        if (skill_order[current] != -1) {
            if (skill_order[current] != prev + 1) {
                return 0;
            }
            prev = skill_order[current];
        }
    }

    return 1;
}

int solution(char* skill, char* skill_trees[], int skill_trees_len) {
    int answer = 0;

    for (int i = 0; i < skill_trees_len; i++) {
        if (isSubset(skill, skill_trees[i])) {
            answer++;
        }
    }

    return answer;
}

int main() {
    char skill[] = "CBD";
    char* skill_trees[] = {"BACDE", "CBADF", "AECB", "BDA"};
    int skill_trees_len = sizeof(skill_trees) / sizeof(skill_trees[0]);

    int result = solution(skill, skill_trees, skill_trees_len);
    printf("%d\n", result);  // Output: 2

    return 0;
}
