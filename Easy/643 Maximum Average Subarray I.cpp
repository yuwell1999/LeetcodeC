//
// Created by YuYue on 2021/5/21.
//
#include <vector>

using namespace std;

class Solution_643 {
public:
    double findMaxAverage(vector<int> &nums, int k) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        int maxSum = sum;

        for (int i = k; i < n; i++) {
            sum = sum - nums[i - k] + nums[i];
            maxSum = max(sum, maxSum);
        }

        return static_cast<double> (maxSum) / k;
    }
};