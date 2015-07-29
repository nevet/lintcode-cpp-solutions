// ohko
class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
        while (!stack1.empty()) stack1.pop();
        while (!stack2.empty()) stack2.pop();
    }

    void push(int element) {
        stack1.push(element);
    }
    
    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        
        int t = stack2.top();
        stack2.pop();
        
        return t;
    }

    int top() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        
        return stack2.top();
    }
};