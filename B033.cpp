#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    int A = T / 300;
    T %= 300;

    int B = T / 60;
    T %= 60;

    int C = T / 10;
    T %= 10;

    if (T != 0) {
        cout << -1 << endl;
    } else {
        cout << A << " " << B << " " << C << endl;
    }

    return 0;
}
