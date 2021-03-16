//
// Created by YuYue on 2021/3/16.
//

#include <vector>

using namespace std;

class Solution_46 {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        dfs(res, nums, 0, (int) nums.size());
        return res;
    }

    // 从左到右填写到第first个位置，当前排列为output
    void dfs(vector<vector<int>> &res, vector<int> &output, int first, int len) {
        if (first == len) {
            res.push_back(output);
            return;
        }
        for (int i = first; i < len; i++) {
            // 维护动态数组
            swap(output[i], output[first]);
            dfs(res, output, first + 1, len);
            swap(output[i], output[first]);
        }
    }
};