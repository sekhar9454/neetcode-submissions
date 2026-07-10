class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (string &ch : tokens) {
            if (ch.size() == 1 &&
                (ch[0] == '+' || ch[0] == '-' || ch[0] == '*' || ch[0] == '/')) {

                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();

                switch (ch[0]) {
                    case '+': stk.push(a + b); break;
                    case '-': stk.push(a - b); break;
                    case '*': stk.push(a * b); break;
                    case '/': stk.push(a / b); break;
                }
            } else {
                stk.push(stoi(ch));
            }
        }

        return stk.top();
    }
};