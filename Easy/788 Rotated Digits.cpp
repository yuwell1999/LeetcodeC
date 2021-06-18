//
// Created by YuYue on 2021/6/18.
//

using namespace std;

class Solution_788 {
public:
    int rotatedDigits(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (isGood(i, false)) {
                count++;
            }
        }
        return count;
    }

    bool isGood(int n, bool flag) {
        if (n == 0) {
            return flag;
        }
        int d = n % 10;
        if (d == 3 || d == 4 || d == 7) {
            return false;
        }
        if (d == 0 || d == 1 || d == 8) {
            return isGood(n / 10, flag);
        }
        return isGood(n / 10, true);
    }
};