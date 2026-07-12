class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();

        vector<int>nse(n,n) , pse(n , -1);

        stack<int>s;

        for(int i =n-1 ; i >= 0 ; i--){
            while(!s.empty() && h[s.top()] >= h[i]) s.pop();

            if(!s.empty()) nse[i] = s.top();

            s.push(i);
        }

        while(!s.empty()) s.pop();

        for(int i = 0 ; i < n ; i++){
            while(!s.empty( ) && h[s.top()] >= h[i]) s.pop();

            if(!s.empty()) pse[i] = s.top();

            s.push(i);
        }

        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            int ht = h[i];
            int width= nse[i] - pse[i] - 1;

            ans = max(ans , ht*width); 
        }

        return ans;
    }
};
