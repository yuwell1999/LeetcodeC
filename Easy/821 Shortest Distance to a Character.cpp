//
// Created by YuYue on 2021/5/10.
//
#include <vector>
#include <string>

using namespace std;

class Solution_821 {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> ans(n, n - 1);

        ans[0] = s[0] == c ? 0 : ans[0];

        for (int i = 1; i < n; i++) {
            ans[i] = s[i] != c ? ans[i - 1] + 1 : 0;
        }

        ans[n - 1] = s[n - 1] == c ? 0 : ans[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            ans[i] = min(ans[i], s[i] != c ? ans[i + 1] + 1 : 0);
        }

        return ans;
    }
};