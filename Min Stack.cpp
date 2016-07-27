class MinStack {
private:
    stack<int> stk;
    stack<int> mono;
public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        stk.push(number);
        if (mono.empty() || number <= mono.top()) mono.push(number);
    }

    int pop() {
        int res = stk.top(); stk.pop();
        if (mono.top() == res) mono.pop();
        return res;
    }

    int min() {
        return mono.top();
    }
};
