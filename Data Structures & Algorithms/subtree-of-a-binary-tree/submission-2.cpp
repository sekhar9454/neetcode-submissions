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
    bool helper(TreeNode* r1 , TreeNode* r2 , TreeNode* r){
        if(r1 == nullptr && r2 == nullptr) return true;
        if(r1 == nullptr || r2 == nullptr) return false;

        if(r1->val == r2->val){
            return (helper(r1->left , r2->left , r) && helper(r1->right , r2->right , r)) || (helper(r1->left , r2 , r ) || helper(r1->right , r2 , r));
        }
        else{
            return helper(r1->left , r  , r) || helper(r1->right , r , r);
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return helper(root  , subRoot , subRoot);
    }
};
