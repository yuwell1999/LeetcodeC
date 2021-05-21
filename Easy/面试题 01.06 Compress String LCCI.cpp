//
// Created by YuYue on 2021/5/21.
//
#include<string>

using namespace std;

class Solution_m01_06 {
public:
    string compressString(string S) {
        return getString(S).length() < S.length() ? getString(S) : S;
    }

    string getString(string s) {
        string ans = "";
        int cnt = 1;
        char c = s[0];
        for (int i = 1; i < s.length(); i++) {
            if (c == s[i]) {
                cnt++;
            } else {
                ans += c + to_string(cnt);
                c = s[i];
                cnt = 1;
            }
        }

        ans += c + to_string(cnt);

        return ans;
    }
};