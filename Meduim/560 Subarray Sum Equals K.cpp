//
// Created by YuYue on 2021/4/2.
//
#include <vector>
#include <unordered_map>

using namespace std;

class Solution_560 {
public:
    int subarraySum(std::vector<int> &nums, int k) {
        unordered_map<int, int> map;
        map[0] = 1;
        int count = 0, pre = 0;

        // 前缀和，<和，出现次数>
        for (auto x:nums) {
            pre += x;
            if (map.find(pre - k) != map.end()) {
                count += map[pre - k];
            }
            map[pre]++;
        }
        return count;
    }
};