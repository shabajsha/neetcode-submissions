class Solution {
public:
    void helper(vector<int> &nums, vector<int> &subset , vector<vector<int>> &ans, int idx, int target){

        if(target == 0){
            ans.push_back(subset);
            return;
        }

        if(target < 0 || idx >= nums.size()){
            return;
        }

        subset.push_back(nums[idx]);
        helper(nums,subset,ans,idx,target-nums[idx]);

        subset.pop_back();
        helper(nums,subset,ans,idx+1,target);

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;

        sort(nums.begin(),nums.end());
        vector<int> subset;
        helper(nums,subset,ans,0,target);
        return ans;
    }
};
