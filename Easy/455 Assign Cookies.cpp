//
// Created by YuYue on 2021/5/21.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution_455 {
public:
    int findContentChildren(vector<int> &children, vector<int> &cookies) {
        sort(children.begin(), children.end());
        sort(cookies.begin(), cookies.end());

        int count = 0;

        for (int i = 0, j = 0; i < children.size() && j < cookies.size(); i++, j++) {
            while (j < cookies.size() && children[i] > cookies[j]) {
                j++;
            }
            if (j < cookies.size()) {
                count++;
            }
        }

        return count;
    }
};