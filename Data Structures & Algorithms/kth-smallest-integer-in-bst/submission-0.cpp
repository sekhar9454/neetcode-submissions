/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int ans, cnt;
    void helper(TreeNode* root , int k){
        if(root == nullptr) return;
        helper(root->left, k);
        if  (cnt == k-1) ans = root->val;// k-1 smaller than me finished in stack
        cnt++;
        helper(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        cnt=0;
        helper(root, k);
        return ans;
    }
};
