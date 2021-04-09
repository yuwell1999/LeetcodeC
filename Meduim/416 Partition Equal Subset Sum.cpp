//
// Created by YuYue on 2021/4/9.
//
#include<vector>
#include<numeric>
#include<algorithm>

using namespace std;

class Solution_416 {
public:
    bool canPartition(vector<int> &nums) {
        int n = nums.size();
        if (n < 2) {
            return false;
        }

        int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxNum = *max_element(nums.begin(), nums.end());

        if (sum % 2 == 1) {
            return false;
        }

        int target = sum / 2;

        if (maxNum > target) {
            return false;
        }
        // dp[i][j]表示从数组[0,i]范围内选取若干个整数（可为0）,是否存在一种方案可以使得选取的和为j
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        // 对于target=0，可以不选任何数，所以dp[i][0] = true
        // i=0,只有一个正整数nums[0]可以选取，所以dp[0][nums[0]] = true
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;

        /**
         * 对于i，j>0的情况
         * 如果j>nums[i],对于当前数字nums[i]可选可不选，下面两种情况只要有一个，就为true
         *      如果不选nums[i]，dp[i][j] = dp[i-1][j]
         *      如果选取nums[i]，dp[i][j] = dp[i-1][j-nums[i]]
         * 如果j<nums[i]，在选取数字和等于j情况下，无法选择当前数字nums[i]
         *      dp[i][j] = dp[i-1][j]
         */
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {
                if (j >= nums[i]) {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][target];
    }
};