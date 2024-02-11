#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> days(N);
    for (int i = 0; i < N; ++i) {
        cin >> days[i];
    }

    sort(days.begin(), days.end(), greater<int>());

    int maxDay = 0;
    for (int i = 0; i < N; ++i) {
        maxDay = max(maxDay, days[i] + i + 1);
    }

    cout << maxDay + 1 << endl;

    return 0;
}
