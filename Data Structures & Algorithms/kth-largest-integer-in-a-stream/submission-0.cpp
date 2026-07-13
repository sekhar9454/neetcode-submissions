class KthLargest {
public:
    int k;
    vector<int>arr;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        arr = nums;
        sort(arr.begin() , arr.end());
    }
    
    int add(int val) {
        arr.push_back(val);
        int idx = arr.size()-2;

        while(idx >= 0 && arr[idx] >= val) {arr[idx+1] = arr[idx]; idx--;}

        arr[idx+1 ] = val;

        return arr[arr.size() - k];
    }
};
