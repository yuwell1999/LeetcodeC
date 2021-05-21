//
// Created by YuYue on 2021/5/21.
//
#include <vector>

using namespace std;

class Solution_1539 {
public:
    int findKthPositive(vector<int> &arr, int k) {
        // 缺失的正整数一定大于等于k
        // 数组中每出现一个小于等于k的数字，意味着少了一个缺失的数字，k++
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= k) {
                k++;
            }
        }

        return k;
    }
};