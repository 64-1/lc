#include <iostream>
#include <vector>

using namespace std;

class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        queue.push_back(x);
    }
    
    int pop() {
        int res = queue.back();
        queue.pop_back();
        return res;
    }
    
    int top() {
        int res = queue.back();
        return res;
    }
    
    bool empty() {
        if(queue.empty()){
            return true;
        }
        return false;
    }
    vector<int> queue;

};

int main(){
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    cout << obj->pop() << endl;
    cout << obj->top() << endl;
    cout << obj->empty() << endl;
    return 0;
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */