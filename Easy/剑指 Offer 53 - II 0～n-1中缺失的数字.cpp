//
// Created by YuYue on 2021/4/15.
//
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            result += i;
            result -= nums[i];
        }
        return result + nums.size();
    }
};