#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int size = number.size() - k;
    int start = 0;

    for (int i = 0; i < size; ++i) {
        char maxDigit = number[start];
        int maxIndex = start;

        for (int j = start; j <= k + i; ++j) {
            if (maxDigit < number[j]) {
                maxDigit = number[j];
                maxIndex = j;
            }
        }

        start = maxIndex + 1;
        answer += maxDigit;
    }

    return answer;
}

int main() {
    // Test cases
    string number1 = "1924";
    int k1 = 2;
    string result1 = solution(number1, k1);
    cout << result1 << endl;

    string number2 = "1231234";
    int k2 = 3;
    string result2 = solution(number2, k2);
    cout << result2 << endl;

    string number3 = "4177252841";
    int k3 = 4;
    string result3 = solution(number3, k3);
    cout << result3 << endl;

    return 0;
}
