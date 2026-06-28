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
    unordered_map<TreeNode*,int>mp;
    int ans = 0 ;
    int depth(TreeNode* node){
        if(!node) return 0;

        int left = depth(node->left);
        int right = depth(node->right);

        return mp[node] = 1+ max(left , right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        mp[root] = depth(root);
        if(!root) return 0;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* cur = q.front();q.pop();
            int left = (cur->left)?mp[cur->left]:0;
            int right = (cur->right)?mp[cur->right]:0;

            ans = max(ans ,  1 + left +right);
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }

        return ans-1;

    }
};
