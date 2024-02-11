#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int A, B, N;
    cin >> A >> B >> N;

    vector<int> favorite(N);
    for (int i = 0; i < N; ++i) {
        cin >> favorite[i];
    }

    sort(favorite.begin(), favorite.end());

    int minButtons = abs(A - B);

    for (int i = 0; i < N; ++i) {
        int buttons = abs(A - favorite[i]) + abs(favorite[i] - B);
        minButtons = min(minButtons, buttons);
    }

    cout << minButtons << endl;

    return 0;
}
