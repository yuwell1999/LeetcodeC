//
// Created by YuYue on 2021/4/14.
//
# include <vector>

using namespace std;

class Solution_338 {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1);
//        for (int i = 0; i <= num; i++) {
//            ans[i] = countOnes(i);
//        }
        int highBit = 0;
        for (int i = 1; i <= num; i++) {
            if ((i & (i - 1)) == 0) {
                // 当一个数是2的整数次幂，只有最高位是1，其余全是0
                // 如i=4，[100]
                highBit = i;
            }
            // ans[4] = 1
            // ans[5] = ans[5-4]+1 = 2
            ans[i] = ans[i - highBit] + 1;
        }
        return ans;
    }

    int countOnes(int x) {
        int ones = 0;
        while (x > 0) {
            x &= (x - 1);
            ones++;
        }
        return ones;
    }
};