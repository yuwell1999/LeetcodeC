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
        for (auto key:nums) {
            map[key]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&compare)> q(compare);
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