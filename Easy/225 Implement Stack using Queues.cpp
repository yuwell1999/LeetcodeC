//
// Created by YuYue on 2021/6/17.
//
#include <queue>

using namespace std;

class MyStack {
public:
    // 一个队列实现栈
    queue<int> queue;

    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        int n = queue.size();
        queue.push(x);

        for (int i = 0; i < n; i++) {
            queue.push(queue.front());
            queue.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int r = queue.front();
        queue.pop();
        return r;
    }

    /** Get the top element. */
    int top() {
        return queue.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return queue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */