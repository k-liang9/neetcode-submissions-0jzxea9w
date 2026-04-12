// initiate 2 stacks, 1 for values, and another for prefix minimums at the current position of the stack
// when pushing and popping, modify both stacks
// when pushing, compare the current value pushed to the top of the prefix min stack and store the minimum of those to the min stack
// getMin returns the top of the prefix min stack

class MinStack {
private:
    stack<int> val_stack;
    stack<int> prefix_min;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        val_stack.push(val);
        if (prefix_min.empty()) {
            prefix_min.push(val);
        } else {
            prefix_min.push(min(val, prefix_min.top()));
        }
    }
    
    void pop() {
        val_stack.pop();
        prefix_min.pop();
    }
    
    int top() {
        return val_stack.top();
    }
    
    int getMin() {
        return prefix_min.top();
    }
};