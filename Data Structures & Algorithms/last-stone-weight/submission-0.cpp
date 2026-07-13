class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int i : stones) pq.push(i);

        while(pq.size() > 1){
            int tp1 = pq.top();pq.pop();
            int tp2 = pq.top();pq.pop();

            if(tp1 != tp2) {
                pq.push(tp1 - tp2);
            }
        }


        if(pq.empty() ) return 0;

        return pq.top();
    }
};
