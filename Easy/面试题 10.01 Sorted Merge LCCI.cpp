//
// Created by YuYue on 2021/5/21.
//
#include <vector>

using namespace std;

class Solution_m10_01 {
public:
    void merge(vector<int> &A, int m, vector<int> &B, int n) {
        // 逆向双指针
        int pa = m - 1, pb = n - 1;
        int tail = m + n - 1;
        int cur;

        while (pa >= 0 || pb >= 0) {
            if (pa == -1) {
                cur = B[pb--];
            } else if (pb == -1) {
                cur = A[pa--];
            } else if (A[pa] > B[pb]) {
                cur = A[pa--];
            } else {
                cur = B[pb--];
            }
            A[tail--] = cur;
        }
    }
};