//
// Created by YuYue on 2021/6/9.
//
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int> &nums) {
        int duplicated = -1, wrong_index = 1; // start from 1

        // [1,2,2,3]  -> [-1,-2,2,-3]
        for (auto n:nums) {
            if (nums[abs(n) - 1] < 0) { // nums内元素从1开始，所以访问下标要减去1
                duplicated = abs(n);
            } else {
                nums[abs(n) - 1] *= -1;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                wrong_index = i + 1;
            }
        }

        vector<int> ans{duplicated, wrong_index};
        return ans;
    }
};