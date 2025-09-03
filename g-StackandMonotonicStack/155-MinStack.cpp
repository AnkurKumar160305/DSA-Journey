
//⏱️ Time & Space Complexity

// push → O(1)

// pop → O(1)

// top → O(1)

// getMin → O(1)

// Extra space: O(n) for minArr.
class MinStack {
    stack<int> s,st;
public:
    MinStack() {
    }
    
    void push(int val) {
        s.push(val);
        if(st.empty() || val<=st.top()){
            st.push(val);
        }
    }
    
    void pop() {
        if(s.empty()){
            return;
        }
        // if top of s equals top of st, pop from st too
        if (s.top() == st.top()) {
            st.pop();
        }
        s.pop();
    }
    
    int top() {
        if(s.empty()){
            return -1;
        }
        return s.top();
    }
    
    int getMin() {
        if(st.empty()){
            return -1;
        }
        return st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */