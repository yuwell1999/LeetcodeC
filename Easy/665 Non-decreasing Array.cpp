//
// Created by YuYue on 2021/5/21.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution_665 {
public:
    bool checkPossibility(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            int x = nums[i], y = nums[i + 1];
            if (x > y) {
                // 将nums[i]修改为nums[i+1]
                nums[i] = y;
                if (is_sorted(nums.begin(), nums.end())) {
                    return true;
                }
                nums[i] = x;
                // 将nums[i+1]修改为nums[i]
                nums[i + 1] = x;
                return is_sorted(nums.begin(), nums.end());
            }
        }

        return true;
    }
};