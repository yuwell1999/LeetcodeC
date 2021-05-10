//
// Created by YuYue on 2021/5/10.
//
#include <cmath>

class Solution_633 {
public:
    bool judgeSquareSum(int c) {
        // 假设a<=b, initialize a=0,b=sqrt(c)
        // a2+b2==c, true
        // a2+b2>c,b--
        // a2+b2<c,a++

        long min = 0, max = (long) sqrt(c);
        while (min <= max) {
            long sum = min * min + max * max;
            if (sum == c) {
                return true;
            } else if (sum > c) {
                max--;
            } else {
                min++;
            }
        }

        return false;
    }
};