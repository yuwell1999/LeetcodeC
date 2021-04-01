//
// Created by YuYue on 2021/4/1.
//

#include <vector>

using namespace std;

class Solution_62 {
public:
    int uniquePaths(int m, int n) {
//        vector<vector<int>> dp(m, vector<int>(n));
//        for (int row = 0; row < m; row++) {
//            dp[row][0] = 1;
//        }
//        for (int col = 0; col < n; col++) {
//            dp[0][col] = 1;
//        }
//
//        for (int row = 1; row < m; row++) {
//            for (int col = 1; col < n; ++col) {
//                dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
//            }
//        }
//        return dp[m - 1][n - 1];


        // 组合数学
        // 从左上角到右下角，一共需要移动m+n-2次
        // 其中m-1次向下移动，n-1次向右移动
        // ans = C[m+n-2,m-1] = (m+n-2)!/((m-1)!*(n-1)!)
        long long ans = 1;
        for (int x = n, y = 1; y < m; x++, y++) {
            ans = ans * x / y;
        }
        return ans;
    }
};