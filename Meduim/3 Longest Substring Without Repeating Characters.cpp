//
// Created by YuYue on 2021/4/9.
//
#include<unordered_set>

using namespace std;

class Solution_3 {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set; // 记录是否出现过
        int rk = -1, ans = 0; // 右指针初始值为-1
        for (int i = 0; i < s.size(); i++) {
            if (i != 0) {
                set.erase(s[i - 1]);
            }
            while (rk + 1 < s.size() && !set.count(s[rk + 1])) {
                // 不断移动右指针
                set.insert(s[rk + 1]);
                rk++;
            }
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }
};