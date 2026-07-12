class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;

        for(char ch : s){
            if(!stk.empty()){
                char tp = stk.top();
                if(
                    (tp == '{' && ch == '}')||
                    (tp == '(' && ch == ')')||
                    (tp == '[' && ch == ']')
                ) {
                    stk.pop();
                }
                else stk.push(ch);
            }
            else stk.push(ch);
        }


        return stk.empty();
    }
};
