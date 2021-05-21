//
// Created by YuYue on 2021/5/21.
//
#include<vector>

using namespace std;

class Solution_54 {
private:
    static constexpr int directions[4][2] = {{0,  1}, // row +0, col +1 往右
                                             {1,  0}, // row+1, col+0 往下
                                             {0,  -1}, //row +0, col-1 往左
                                             {-1, 0}}; // row-1, col+0.往上

public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        // 模拟，用visit矩阵判断是否遍历，元素长度等于路径长度就结束
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<bool>> visit(rows, vector<bool>(cols));
        int total = cols * rows;
        vector<int> ans(total);

        int row = 0, col = 0, directionIndex = 0;

        for (int i = 0; i < total; i++) {
            ans[i] = matrix[row][col];
            visit[row][col] = true;
            // 预计算下一行
            int nextRow = row + directions[directionIndex][0];
            int nextCol = col + directions[directionIndex][1];

            // 数组越界就要重新计算方向
            if (nextRow < 0 || nextRow >= rows || nextCol < 0 || nextCol >= cols || visit[nextRow][nextCol]) {
                directionIndex = (directionIndex + 1) % 4;
            }
            row += directions[directionIndex][0];
            col += directions[directionIndex][1];
        }

        // return ans;

        if (matrix.empty()) {
            return ans;
        }
        int up = 0;
        int down = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while (true) {
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[up][i]); // 向右移动到最右
            }
            ++up;
            if (up > down) {
                break; // 上边界大于下边界，遍历完成
            }
            for (int i = up; i <= down; i++) {
                ans.push_back(matrix[i][right]);
            }
            --right;
            if (right < left) {
                break;
            }
            for (int i = right; i >= left; i--) {
                ans.push_back(matrix[down][i]);
            }
            --down;
            if (down < up) {
                break;
            }
            for (int i = down; i >= up; i--) {
                ans.push_back(matrix[i][left]);
            }
            ++left;
            if (left > right) {
                break;
            }
        }

        return ans;
    }
};