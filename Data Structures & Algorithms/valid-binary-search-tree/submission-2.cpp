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
    bool isValid(TreeNode* root, int mini , int maxi){
        if(root == NULL){
            return true;
        }
        
        if(root->val <= mini || root->val >= maxi){
            return false;
        }

        if(isValid(root->left,mini,root->val) && isValid(root->right,root->val,maxi)){
            return true;
        }
        return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root,INT_MIN,INT_MAX);
    }
};
