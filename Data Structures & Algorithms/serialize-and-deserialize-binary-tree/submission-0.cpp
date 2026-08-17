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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";

        if(root == NULL){
            return ans + "N";
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* top = q.front();
            q.pop();
            if(top == NULL){
                ans += "N,";
            }
            else{
                ans += to_string(top->val);
                ans += ",";
                q.push(top->left);
                q.push(top->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string val;
        getline(ss,val,',');

        if(val== "N"){
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(val));
        
        queue<TreeNode*> q;
        q.push(root);

        while(getline(ss,val,',')){
            TreeNode* top = q.front();
            q.pop();


            if(val != "N"){
                top->left = new TreeNode(stoi(val));
                q.push(top->left);
            }

            getline(ss,val,',');

            if(val != "N"){
                top->right = new TreeNode(stoi(val));
                q.push(top->right);
            }
            
        }
        return root;

    }
};
