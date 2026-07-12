class Solution {
public:
    int getSum(int a, int b) {
        int ans = 0;
        int pc = 0;
        for(int i = 0 ; i < 32 ; i++){
            int btA = (a>>i)&1;
            int btB = (b>>i)&1;

            int sm = pc^btA^btB;
            ans |= (sm<<i);
            pc = btA&btB | btB&pc |  btA&pc;
        }

        return ans;
    }
};
