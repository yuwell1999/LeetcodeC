//
// Created by YuYue on 2021/5/10.
//

#include <vector>

using namespace std;

class Solution_704 {
public:
    int search(vector<int> &nums, int target) {
        int mid, left = 0, right = nums.size() - 1;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
};