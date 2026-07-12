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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;

        if(!root) return {};
        q.push(root);

        vector<vector<int>>lvlOrder;

        while(!q.empty()){
            int sz = q.size();
            vector<int>lvl;
            while(sz--){
                TreeNode* cur = q.front();
                q.pop();
                lvl.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            lvlOrder.push_back(lvl);
        }

        return lvlOrder;
    }
};
