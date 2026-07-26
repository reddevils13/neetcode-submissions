class MinStack {
private:
    stack<long long> st;
    long long minEle;

public:
    MinStack() {
    }

    void push(int val) {
        if (st.empty()) {
            st.push(val);
            minEle = val;
        }
        else if (val >= minEle) {
            st.push(val);
        }
        else {
            // Store encoded value
            st.push(2LL * val - minEle);
            minEle = val;
        }
    }

    void pop() {
        if (st.empty()) return;

        long long top = st.top();
        st.pop();

        if (top < minEle) {
            // Restore previous minimum
            minEle = 2 * minEle - top;
        }
    }

    int top() {
        long long top = st.top();

        if (top < minEle)
            return (int)minEle;   // Encoded value represents current minimum

        return (int)top;
    }

    int getMin() {
        return (int)minEle;
    }
};