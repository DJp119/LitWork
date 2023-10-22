#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> sumToIndex;
    int maxLen = 0;
    int sum = 0;

    for (int i = 0; i < nums.size(); i++) {
        // Convert 0 to -1 for easier calculation
        if (nums[i] == 0) {
            sum -= 1;
        } else {
            sum += 1;
        }

        // If the sum is 0, it means there are an equal number of 0s and 1s from the beginning to this index.
        if (sum == 0) {
            maxLen = i + 1;
        } else if (sumToIndex.find(sum) != sumToIndex.end()) {
            // If the same sum is encountered again, it means the subarray between the previous and current index has an equal number of 0s and 1s.
            maxLen = max(maxLen, i - sumToIndex[sum]);
        } else {
            // Store the first occurrence of the sum in the map
            sumToIndex[sum] = i;
        }
    }

    return maxLen;
}

int main() {
    vector<int> nums;
    int n;
    while (cin >> n) {
        nums.push_back(n);
    }
    
    int maxLength = findMaxLength(nums);
    cout << maxLength << endl;

    return 0;
}
