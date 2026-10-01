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

        for (int i = idx; i < nums.size(); i++) {

            if (nums[i] > target)
                break;

            subset.push_back(nums[i]);

            helper(nums, subset, ans, i, target - nums[i]);

            subset.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;

        sort(nums.begin(),nums.end());
        vector<int> subset;
        helper(nums,subset,ans,0,target);
        return ans;
    }
};
