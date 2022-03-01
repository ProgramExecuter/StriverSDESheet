/////////////////////
///  Solution 1  ///
///////////////////


// Time Complexity - O(n) => push, O(1) => pop
// Space Complexity - O(2*n)

class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    
    int pop() {
        int ele = q1.front();
        q1.pop();
        return ele;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};





/////////////////////
///  Solution 2  ///
///////////////////


// Time Complexity - O(n) => push, O(1) => pop
// Space Complexity - O(n)

class MyStack {
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        int n = q.size();
        q.push(x);
        
        // For first 'N' elements
        // Remove from front and move them to back
        while(n--) {
            int ele = q.front();
            q.pop();
            q.push(ele);
        }
    }
    
    int pop() {
        int ele = q.front();
        q.pop();
        return ele;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
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