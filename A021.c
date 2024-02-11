#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int total_plugs = 0;
    int max_plugs = 0;

    for (int i = 0; i < n; i++) {
        int plugs;
        scanf("%d", &plugs);

        total_plugs += plugs;

        if (plugs > max_plugs) {
            max_plugs = plugs;
        }
    }

    printf("%d\n", total_plugs - max_plugs);

    return 0;
}
