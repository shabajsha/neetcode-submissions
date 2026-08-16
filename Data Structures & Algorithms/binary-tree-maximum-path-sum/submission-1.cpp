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
    int helper(TreeNode* root,  int& maxi){
        if(root == NULL){
            return 0;
        }

        int left = helper(root->left,maxi);
        left = left < 0 ? 0 : left;

        int right = helper(root->right , maxi);
        right = right < 0 ? 0 : right;

        maxi = max(maxi , root->val + left + right);

        return root->val + max(left,right);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        int temp = helper(root,maxi);
        return maxi;
    }
};
