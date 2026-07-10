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
    int ans = -1e9;
    int mx(TreeNode* root){
        if(root== nullptr) return 0;

        int left = mx(root->left);
        int right = mx(root->right);

        ans = max({ans ,left + root->val , right + root->val , root->val + left  + right , root->val});

        return root->val + max({right , left , 0});
    }
    int maxPathSum(TreeNode* root) {
        mx(root);

        return ans;
    }
};
