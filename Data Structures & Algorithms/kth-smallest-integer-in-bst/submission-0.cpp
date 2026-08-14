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
    void kth(TreeNode* root, int& k , int &ans){
        if(root == NULL || ans != -1){
            return;
        }
        kth(root->left,k,ans);
        if (ans != -1) {
            return;
        }
        if(k == 1){
            ans = root->val;
            return;
        }
        k--;
        kth(root->right,k,ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        kth(root,k,ans);
        return ans;
    }
};
