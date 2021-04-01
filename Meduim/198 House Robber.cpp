//
// Created by YuYue on 2021/4/1.
//

#include <vector>

using namespace std;

class Solution_198 {
public:
    int rob(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }

        // 对于第k（k>2）间房，有两种选项
        // 偷窃第k间房，就不能偷窃第k-1间，偷窃总金额为前k-2间的最高总金额和第k间金额之和
        // 不偷窃第k间，总金额为前k-1间房的最高总金额
        vector<int> dp = vector<int>(nums.size(), 0);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < dp.size(); i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        return dp[nums.size() - 1];
    }
};