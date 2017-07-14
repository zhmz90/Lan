// copyright 2014 Lanting Guo

/** 155. Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
 */

#include <iostream>
#include <vector>

class MinStack {
 public:
    /** initialize your data structure here. */
    MinStack() {
      data = {};
      size = 0;
    }
    void push(int x) {
      if (size == 0) {
        data.push_back(x);
        data.push_back(x);
        size += 2;
        return;
      }
      int min = getMin();
      if (x < min) min = x;
      data.push_back(min);
      data.push_back(x);
      size += 2;
    }
    void pop() {
      if (size > 0) {data.pop_back(), data.pop_back(); size -= 2;}
    }
    int top() {
      if (size > 0) return data[size-1];
      return NULL;
    }
    int getMin() {
      if (size > 0)
        return data[size-2];  // if  size>0
      return NULL;
    }
  void output() {
    int i;
    for (i = 0; i < size; i++) {
      std::cout << data[i] << " ";
    }
    std::cout << "\n";
  }
 private:
  std::vector<int> data;  // [min, x, min, x]
  int size;
};

int main(int argc, char *argv[]) {
  MinStack* obj = new MinStack();
  obj->push(-2);
  obj->push(0);
  obj->push(-3);
  obj->getMin();
  obj->output();
  obj->pop();
  obj->top();
  obj->getMin();
  obj->output();
  return 0;
}
