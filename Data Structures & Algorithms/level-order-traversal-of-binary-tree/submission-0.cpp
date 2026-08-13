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
        vector<vector<int>> ans;
        if(!root){
            return {};
        }
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});

        while(!q.empty()){
            TreeNode* top = q.front().first;
            int index = q.front().second;

            q.pop();
            if(ans.size() <= index){
                ans.push_back({});
            }
            ans[index].push_back(top->val);
            if(top->left){
                q.push({top->left,index+1});
            }
            if(top->right){
                q.push({top->right,index+1});            
            }
        }  
        return ans;     
    }
};
