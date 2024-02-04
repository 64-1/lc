#include <iostream>
#include <stack>

using namespace std;


class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stackIn.push(x);
    }
    
    int pop() {
        if(stackOut.empty()){
            while(!stackIn.empty()){
                stackOut.push(stackIn.top());
                stackIn.pop();
            }
        }
        int res = stackOut.top();
        stackOut.pop();
        return res;
    }
    
    int peek() {
        int res = this->pop();
        stackOut.push(res);
        return res;
    }
    
    bool empty() {
        if(stackIn.empty() && stackOut.empty()){
            return true;
        }
        return false;
    }
    stack<int> stackIn;
    stack<int> stackOut;
};

int main(){
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    cout << obj->pop() << endl;
    cout << obj->peek() << endl;
    cout << obj->empty() << endl;
    return 0;
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */