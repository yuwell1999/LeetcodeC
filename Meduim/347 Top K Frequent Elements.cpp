//
// Created by YuYue on 2021/4/1.
//

# include <vector>
#include <unordered_map>

using namespace std;

class Solution_347 {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> map;
        for (auto key:nums) {
            map[key]++;
        }
    }
};