//
// Created by YuYue on 2021/4/1.
//

# include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution_347 {
public:
    static bool compare(pair<int, int> &m, pair<int, int> &n) {
        return m.second > n.second;
    }

    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> map;
        // 先建立映射
        for (auto key:nums) {
            map[key]++;
        }

        // 小顶堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&compare)> q(compare);
        // 按次序取映射中的元素，放入堆中比较
        for (auto &[num, count]:map) {
            if (q.size() == k) {
                if (q.top().second < count) {
                    q.pop();
                    q.emplace(num, count);
                }
            } else {
                q.emplace(num, count);
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.emplace_back(q.top().first);
            q.pop();
        }

        return ans;
    }
};