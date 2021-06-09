//
// Created by YuYue on 2021/6/9.
//

#include <vector>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int> &nums) {
        int ans = 0;
        int n = nums.size();
        int start = 0;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] <= nums[i - 1]) {
                // 非递增，出现驼峰，更新start
                start = i;
            }
            // 每次都更新最大长度
            ans = max(ans, i - start + 1);
        }

        return ans;
    }
};