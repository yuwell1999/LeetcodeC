//
// Created by YuYue on 2021/3/14.
//
# include<vector>
#include<math.h>
#include <algorithm>

class Solution_16 {
public:
    int threeSumClosest(std::vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 1e7;

        auto update = [&](int cur) {
            if (abs(cur - target) < abs(ans - target)) {
                ans = cur;
            }
        };

        // 枚举a
        for (int i = 0; i < n; i++) {
            // 保证和上一次元素不相等
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // 使用双指针枚举b和c
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    return target;
                }

                update(sum);

                if (sum > target) {
                    // 和大于target，移动c对应指针
                    // 移动到下一个不相同的元素
                    int k0 = k - 1;
                    while (j < k0 && nums[k0] == nums[k]) {
                        --k0;
                    }
                    k = k0;
                } else {
                    // 和小于target，移动b对应指针
                    // 移动到下一个不相同的元素
                    int j0 = j + 1;
                    while (j0 < k && nums[j0] == nums[j]) {
                        ++j0;
                    }
                    j = j0;
                }
            }
        }
        return ans;
    }
};