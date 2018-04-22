#include<stack>
#include<iostream>
using namespace std;
class MinStack {
private: 
    stack<int> minStack;
    stack<int> oriStack;
public:
    MinStack() {
        size = 0;
    }
    
    void push(int x) {
        if (size == 0 || x <= minStack.top()){
            minStack.push(x);
        }
        oriStack.push(x);
        size ++;
    }
    
    void pop() {
        if (minStack.top() == oriStack.top()){
            minStack.pop();
        }
        oriStack.pop();
        size --;
    }
    
    int top() {
        return oriStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }

    int size = 0;
};

int main(int argc, char const *argv[])
{
    MinStack mst;
    mst.push(-1);
    mst.push(1);
    mst.push(-2);
    mst.push(2);
    cout << mst.getMin() << endl;
    mst.pop();
    mst.pop();
    cout << mst.getMin() << endl;
    return 0;
}