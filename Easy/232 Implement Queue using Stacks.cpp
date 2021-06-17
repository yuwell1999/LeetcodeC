//
// Created by YuYue on 2021/6/17.
//
#include <stack>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> stack1, stack2;
    int front;

    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        if (stack1.empty()) {
            front = x;
        }
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        stack2.push(x);

        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        stack1.pop();
        if (!stack1.empty()) {
            front = stack1.top();
        }

        return front;
    }

    /** Get the front element. */
    int peek() {
        return front;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stack1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */