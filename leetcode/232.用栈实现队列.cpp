/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
public:
    stack<int> stackint;
    stack<int> stackout;
public:
    MyQueue() {

    }
    
    void push(int x) {
        stackint.push(x);
    }
    
    int pop() {
        if(stackout.empty()){
            while(!stackint.empty()){
                stackout.push(stackint.top());
                stackint.pop();
            }
        }
        int front = stackout.top();
        stackout.pop();
        return front;
    }
    
    int peek() {
        int res = this->pop();
        stackout.push(res);
        return res;
    }
    
    bool empty() {
        return stackint.empty()&&stackout.empty();
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
// @lc code=end

