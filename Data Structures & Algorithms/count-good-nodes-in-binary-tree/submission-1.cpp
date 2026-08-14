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
private:
    int helper(TreeNode* root, int maxi){
        if(root == NULL){
            return 0;
        }

        if(root->val >= maxi){
            return 1 + helper(root->left,root->val) + helper(root->right,root->val);
        }
        return helper(root->left,maxi) + helper(root->right,maxi);
    }
public:
    int goodNodes(TreeNode* root) {
        int maxi = INT_MIN;
        
        return helper(root,maxi);
    }
};
