//
// Created by YuYue on 2021/5/21.
//
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool isStraight(vector<int> &nums) {
        set<int> set;
        int max = 0, min = 14;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                continue;
            }
            max = nums[i] > max ? nums[i] : max;
            min = nums[i] < min ? nums[i] : min;

            if (set.count(nums[i]) == 1) {
                return false;
            }
            set.insert(nums[i]);
        }

        return max - min < 5;
    }
};