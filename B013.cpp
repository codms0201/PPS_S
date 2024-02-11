#include <iostream>
#include <queue>
#include <set>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    set<pair<int, int>> visited;

    set<int> result;

    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        if (visited.count({a, b}) > 0) {
            continue;
        }
        visited.insert({a, b});

        int c = C - a - b;

        if (a == 0) {
            result.insert(c);
        }

        q.push({max(0, a - (B - b)), min(B, b + a)});
        q.push({max(0, a - (C - c)), b});
        q.push({min(A, a + b), max(0, b - (A - a))});
        q.push({a, max(0, b - (C - c))});
        q.push({min(A, a + c), b});
        q.push({a, min(B, b + c)});
    }

    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}
