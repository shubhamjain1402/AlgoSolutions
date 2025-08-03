class MinStack {
    stack<long long> st;
    long long mini = LLONG_MIN;

public:
    MinStack() {
        while (!st.empty()) st.pop();
        mini = LLONG_MAX;
    }

    void push(int val) {
        if (st.empty()) {
            mini = val;
            st.push(val);
        } else {
            if (val < mini) {
                // Encode previous mini into current val
                st.push(2LL * val - mini);
                mini = val;
            } else {
                st.push(val);
            }
        }
    }

    void pop() {
        if (st.empty()) return;
        long long x = st.top();
        st.pop();
        if (x < mini) {
            // Decode previous mini value
            mini = 2LL * mini - x;
        }
    }

    long long top() {
        if (st.empty()) return -1;
        long long x = st.top();
        return (x < mini) ? mini : x;
    }

    long long getMin() {
        return mini;
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