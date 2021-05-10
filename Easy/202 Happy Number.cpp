//
// Created by YuYue on 2021/5/10.
//

class Solution_202 {
public:
    bool isHappy(int n) {
        // 最终得到1
        // 最终循环
        // 接近无穷大，不可能
        int slow = n;
        int fast = getNext(n);
        while (fast != 1 && slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }

        return fast == 1;
    }

    int getNext(int n) {
        int sum = 0;
        while (n > 0) {
            int divide = n % 10;
            n /= 10;
            sum += divide * divide;
        }

        return sum;
    }
};