class Solution {
public:
    int n;
    void helper(vector<vector<int>>& ans, int ind, vector<int>& given, vector<int> temp){
        ans.push_back(temp);

        for(int i = ind; i < n ; i++){
            if(i != ind && given[i] == given[i-1]){
                continue;
            }
            temp.push_back(given[i]);
            helper(ans,i+1,given,temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> ans;
        vector<int> temp;
        n = nums.size();
        helper(ans,0,nums,temp);
        
        return ans;
    }
};