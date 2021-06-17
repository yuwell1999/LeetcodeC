//
// Created by YuYue on 2021/6/18.
//
#include <vector>

using namespace std;

class Solution_724 {
public:
    int pivotIndex(vector<int> &nums) {
        int sum = 0;
        int subTotal = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            if (subTotal == sum - nums[i] - subTotal) {
                return i;
            }
            subTotal += nums[i];
        }

        return -1;
    }
};
