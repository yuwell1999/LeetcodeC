//
// Created by YuYue on 2021/3/15.
//

#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution_17 {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        if (digits.empty()) {
            return combinations;
        }

        unordered_map<char, string> phoneMap{
                {'2', "abc"},
                {'3', "def"},
                {'4', "ghi"},
                {'5', "jkl"},
                {'6', "mno"},
                {'7', "pqrs"},
                {'8', "tuv"},
                {'9', "wxyz"}
        };

        string combination;
        dfs(combinations, phoneMap, digits, 0, combination);
        return combinations;
    }

    void dfs(vector<string> &combinations, const unordered_map<char, string> &phoneMap, const string &digits, int index,
             string &combination) {
        if (index == digits.length()) { // 到了叶子节点退出当前回溯
            combinations.push_back(combination);
        } else {
            char digit = digits[index];
            const string &letters = phoneMap.at(digit);
            for (const char &letter:letters) {
                combination.push_back(letter);
                dfs(combinations, phoneMap, digits, index + 1, combination);
                combination.pop_back();
            }
        }
    }
};