#include <iostream>
using namespace std;
 
// Manual char stack for bracket checking
class CharStack {
private:
    char arr[100];
    int top;
public:
    CharStack() { top = -1; }
    bool isEmpty() { return top == -1; }
    void push(char c) { arr[++top] = c; }
    char pop() { return arr[top--]; }
    char peek() { return arr[top]; }
};
 
// Goes through each character:
// opening bracket -> push onto stack
// closing bracket -> match with top of stack
// if mismatch or stack empty -> not balanced
bool isBalanced(string expr) {
    CharStack s;
    for (int i = 0; i < (int)expr.length(); i++) {
        char c = expr[i];
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (s.isEmpty()) return false;
            char t = s.pop();
            if (c == ')' && t != '(') return false;
            if (c == ']' && t != '[') return false;
            if (c == '}' && t != '{') return false;
        }
    }
    return s.isEmpty();
}
 
int main() {
    string e1 = "(a + [b * {c + d}])";
    string e2 = "{a + (b - [c]}";
 
    cout << e1 << " -> ";
    cout << (isBalanced(e1) ? "balanced" : "not balanced") << endl;
 
    cout << e2 << " -> ";
    cout << (isBalanced(e2) ? "balanced" : "not balanced") << endl;
 
    return 0;
}


