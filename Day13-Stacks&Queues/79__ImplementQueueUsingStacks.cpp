/////////////////////
///  Solution 1  ///
///////////////////


// Time Complexity - O(n) => push, O(1) => pop
// Space Complexity - O(n)


class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        // Move all elements from 's1' to 's2'
        while(s1.empty() == false) {
            int ele = s1.top();
            s1.pop();
            s2.push(ele);
        }
        
        // Push new element into 's1'
        s1.push(x);
        
        // Move all elements back to 's1'
        while(s2.empty() == false) {
            int ele = s2.top();
            s2.pop();
            s1.push(ele);
        }
    }
    
    int pop() {
        int ele = s1.top();
        s1.pop();
        return ele;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};





/////////////////////
///  Solution 2  ///
///////////////////

/*
******* Since we shift 'input' to 'output' very rarely
******* Amortized O(1), Worst O(n) => for pop, peek
******* O(1) => for push
*/

// Time Complexity - 
// Space Complexity - O(n)

class MyQueue {
    stack<int> inp;
    stack<int> out;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        inp.push(x);
    }
    
    int pop() {
        if(out.empty()) {
            // Move all 'input' stack element to 'output' stack
            while(inp.empty() == false) {
                out.push(inp.top());
                inp.pop();
            }
        }
        int ele = out.top();
        out.pop();
        return ele;
    }
    
    int peek() {
        if(out.empty()) {
            // Move all 'input' stack element to 'output' stack
            while(inp.empty() == false) {
                out.push(inp.top());
                inp.pop();
            }
        }
        return out.top();
    }
    
    bool empty() {
        return (inp.empty()  &&  out.empty());
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