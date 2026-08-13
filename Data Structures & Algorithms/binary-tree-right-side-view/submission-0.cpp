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
    void helper(TreeNode* root,vector<int> &ans,int index){
        if(root == NULL){
            return;
        }

        if(ans.size() < index){
            ans.push_back(root->val);
        }
        helper(root->right,ans,index+1);
        helper(root->left,ans,index+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root){
            ans.push_back(root->val);
        }
        helper(root,ans,1);
        return ans;
    }
};
