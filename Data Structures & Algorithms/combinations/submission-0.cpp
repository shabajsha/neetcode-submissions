class Solution {
public:
    void helper(vector<vector<int>> &ans, int n, int k, vector<int> &subset, int idx){
        if(subset.size() == k){
            ans.push_back(subset);
            return;
        }
        if(idx > n || subset.size() > k){
            return ;
        }

        for(int i = idx; i <= n; i++){
            subset.push_back(i);
            helper(ans,n,k,subset,i+1);
            subset.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> subset;

        helper(ans,n,k,subset,1);

        return ans;
    }
};