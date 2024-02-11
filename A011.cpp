#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, double>& a, pair<int, double>& b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> failureRates;

    sort(stages.begin(), stages.end());

    for (int i = 1; i <= N; i++) {
        int totalUsers = count(stages.begin(), stages.end(), i);
        int notClearedUsers = count_if(stages.begin(), stages.end(), [i](int stage) { return stage == i; });
        
        double failureRate = (totalUsers == 0) ? 0 : (double)notClearedUsers / totalUsers;
        failureRates.push_back({i, failureRate});
    }

    sort(failureRates.begin(), failureRates.end(), compare);

    for (auto& failureRate : failureRates) {
        answer.push_back(failureRate.first);
    }

    return answer;
}

int main() {
    vector<int> result1 = solution(5, {2, 1, 2, 6, 2, 4, 3, 3});
    vector<int> result2 = solution(4, {4, 4, 4, 4, 4});

    cout << "Result 1: ";
    for (int stage : result1) {
        cout << stage << " ";
    }
    cout << endl;

    cout << "Result 2: ";
    for (int stage : result2) {
        cout << stage << " ";
    }
    cout << endl;

    return 0;
}
