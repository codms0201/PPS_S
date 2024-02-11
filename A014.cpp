#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> findRanges(vector<int>& nums) {
    vector<string> result;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        int start = nums[i];
        while (i < n - 1 && nums[i] + 1 == nums[i + 1]) {
            ++i;
        }
        int end = nums[i];
        if (start == end) {
            result.push_back(to_string(start));
        } else {
            result.push_back(to_string(start) + "->" + to_string(end));
        }
    }
    return result;
}

int main() {
    vector<int> nums = {0, 1, 2, 4, 5, 7};
    vector<string> result = findRanges(nums);

    cout << "Output: [";
    for (int i = 0; i < result.size(); ++i) {
        cout << "\"" << result[i] << "\"";
        if (i < result.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    return 0;
}
