//
// Created by YuYue on 2021/6/9.
//

#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> ans;
        int i = 0;
        int n = nums.size();

        while (i < n) {
            int low = i;
            i++; // 右指针先移动一位
            while (i < n && nums[i] == nums[i - 1] + 1) {
                i++; // 找到第一个不连续的右指针位置
            }
            int high = i - 1; // 区间右边界为上面的左侧值
            string temp = to_string(nums[low]);
            if (low < high) {
                temp.append("->");
                temp.append(to_string(nums[high]));
            }
            ans.push_back(temp);
        }

        return ans;
    }
};