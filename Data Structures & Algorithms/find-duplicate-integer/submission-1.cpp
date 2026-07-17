class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Phase 1: Find intersection point in the cycle using Floyd's algorithm
        // Treat array as linked list where nums[i] points to index nums[i]
        int slow = nums[0];
        int fast = nums[0];
        
        // Move slow pointer one step and fast pointer two steps
        // Continue until they meet inside the cycle
        do {
            slow = nums[slow];      // Move one step
            fast = nums[nums[fast]]; // Move two steps
        } while (slow != fast);
        
        // Phase 2: Find the entrance to the cycle (duplicate number)
        // Reset one pointer to start and move both pointers one step at a time
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];  // Move one step from start
            fast = nums[fast];  // Move one step from meeting point
        }
        
        // Both pointers now point to the duplicate number
        return slow;
    }
};