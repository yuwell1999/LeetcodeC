//
// Created by YuYue on 2021/4/15.
//
#include <string>

using namespace std;

class Solution_680 {
public:
    bool validPalindrome(string s) {
        int low = 0, high = s.size() - 1;

        while (low < high) {
            char c1 = s[low], c2 = s[high];
            if (c1 == c2) {
                low++;
                high--;
            } else {
                return checkPalinrome(s, low, high - 1) || checkPalinrome(s, low + 1, high);
            }
        }

        return true;
    }

    // 判断s[low,high]是否为回文
    bool checkPalinrome(const string &s, int low, int high) {
        for (int i = low, j = high; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
};