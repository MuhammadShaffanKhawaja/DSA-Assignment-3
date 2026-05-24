#include <iostream>
using namespace std;
 
// Manual integer stack for postfix evaluation
class IntStack {
private:
    int arr[50];
    int top;
public:
    IntStack() { top = -1; }
    bool isEmpty() { return top == -1; }
    void push(int v) { arr[++top] = v; }
    int pop() { return arr[top--]; }
    int peek() { return arr[top]; }
};
 
// Logic:
// Step 1: Read character by character
// Step 2: If digit -> push to stack
// Step 3: If operator -> pop b then pop a -> apply op -> push result
// Step 4: After loop the stack top is the final answer
int evaluatePostfix(string expr) {
    IntStack s;
    for (int i = 0; i < (int)expr.length(); i++) {
        char c = expr[i];
        if (c >= '0' && c <= '9') {
            s.push(c - '0');
        } else {
            int b = s.pop();
            int a = s.pop();
            if (c == '+') s.push(a + b);
            else if (c == '-') s.push(a - b);
            else if (c == '*') s.push(a * b);
            else if (c == '/') {
                if (b == 0) {
                    cout << "Error: Division by zero!" << endl;
                    return -1;
                }
                s.push(a / b);
            }
        }
    }
    return s.peek();
}
 
int main() {
    cout << "23+   = " << evaluatePostfix("23+")   << endl; // 5
    cout << "53*2+ = " << evaluatePostfix("53*2+") << endl; // 17
    cout << "842-* = " << evaluatePostfix("842-*") << endl; // 16
    return 0;
}

