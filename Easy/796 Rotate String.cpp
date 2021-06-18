//
// Created by YuYue on 2021/6/18.
//

#include <string>

using namespace std;

class Solution_796 {
public:
    bool rotateString(string s, string goal) {
        // ab[cdeab]cde  cdeab
        return s.size() == goal.size() && (s + s).find(goal) != string::npos;
    }
};