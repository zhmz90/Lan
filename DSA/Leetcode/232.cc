/* Copyright 2017 Lanting Guo */
/** 232. Implement Queue using Stacks
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stack>
using string = std::string;

class MyQueue {
 public:
    /** Initialize your data structure here. */
    MyQueue() {
      s = {};
    }

    /** Push element x to the back of queue. */
    void push(int x) {
      s.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
      stack<int> v;
      while (!s.empty()) {
        v.push(s.top());
        s.pop();
      }
      int ret = v.top();
      v.pop();
      while (!v.empty()) {
        s.push(v.top());
        v.pop();
      }
      return ret;
    }

    /** Get the front element. */
    int peek() {
      stack<int> v;
      while (!s.empty()) {
        v.push(s.top());
        s.pop();
      }
      int ret = v.top();
      while (!v.empty()) {
        s.push(v.top());
        v.pop();
      }
      return ret;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
      return s.empty();
    }

 private:
  stack<int> s;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */


int main(int argc, char *argv[]) {
  Solution solu;
  return 0;
}
