class Solution {
public:

    void helper(vector<vector<int>> &ans, vector<int> &nums, vector<int> &perm, int idx){
        if(idx == nums.size()){
            ans.push_back(perm);
            return;
        }
        unordered_set<int> st;
        
        for(int i = idx; i < nums.size(); i++){
            if(st.count(perm[i])){
                continue;
            }
            st.insert(perm[i]);
            swap(perm[idx],perm[i]);
            helper(ans,nums,perm,idx+1);
            swap(perm[idx],perm[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        vector<int> perm;
        perm = nums;
        helper(ans,nums,perm,0);
        return ans;
 
    }
};