#include <iostream>
#include <vector>

using namespace std;

int countPrimes(int n) {
    if (n <= 2) {
        return 0;
    }

    vector<bool> isPrime(n, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int count = 0;
    for (int i = 2; i < n; ++i) {
        if (isPrime[i]) {
            ++count;
        }
    }

    return count;
}

int main() {
    cout << "Example 1: " << countPrimes(10) << endl;
    cout << "Example 2: " << countPrimes(0) << endl;
    cout << "Example 3: " << countPrimes(1) << endl;

    return 0;
}
