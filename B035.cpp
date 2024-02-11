#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> coins(N);
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }

    int count = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (K == 0) {
            break;
        }

        if (coins[i] <= K) {
            count += K / coins[i];
            K %= coins[i];
        }
    }

    cout << count << endl;

    return 0;
}
