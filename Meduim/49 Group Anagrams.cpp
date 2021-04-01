//
// Created by YuYue on 2021/4/1.
//

#include<vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution_49 {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        // 对于单词排序之后，字符串作为哈希表的key
        unordered_map<string, vector<string>> map;
        for (string &str:strs) {
            string key = str;
            sort(key.begin(), key.end());
            map[key].emplace_back(str); // 相当于push_back
        }

        vector<vector<string>> ans;

        for (auto item = map.begin(); item != map.end(); item++) {
            ans.emplace_back(item->second);
        }
        return ans;
    }
};