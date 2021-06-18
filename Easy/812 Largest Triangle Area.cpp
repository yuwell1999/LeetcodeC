//
// Created by YuYue on 2021/6/18.
//

#include <vector>
#include <math.h>

using namespace std;

class Solution_812 {
public:
    double largestTriangleArea(vector<vector<int>> &points) {
        int N = points.size();
        double ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    ans = max(ans, area(points[i], points[j], points[k]));
                }
            }
        }

        return ans;
    }

    double area(vector<int> &x, vector<int> &y, vector<int> &z) {
        return 0.5 * abs(
                x[0] * y[1] + y[0] * z[1] + z[0] * x[1]
                - x[1] * y[0] - y[1] * z[0] - z[1] * x[0]
        );
    }
};