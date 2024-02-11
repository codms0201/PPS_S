#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> jump(n);
    for (int i = 0; i < n; ++i) {
        cin >> jump[i];
    }

    int s;
    cin >> s;

    int leftCount = 0;
    for (int i = s - 1; i >= 0; --i) {
        if (jump[i] + i >= s - 1) {
            s = i + 1;
            leftCount++;
        }
    }

    s = jump.size();

    int rightCount = 0;
    for (int i = s - 1; i >= 0; --i) {
        if (jump[i] + i >= s - 1) {
            s = i + 1;
            rightCount++;
        }
    }

    cout << leftCount + rightCount - 1 << endl;

    return 0;
}
