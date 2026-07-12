class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tm) {
        stack<int>stk;

        int n = tm.size();
        vector<int>ans(n,0);
        for(int i = n-1 ; i >= 0 ; i--){
            while(!stk.empty() && tm[i] >= tm[stk.top()]) stk.pop();

            if(!stk.empty()) ans[i] = stk.top() - i;
            stk.push(i);
        }

        return ans;

    }
};
