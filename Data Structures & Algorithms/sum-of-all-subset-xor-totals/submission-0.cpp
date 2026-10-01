class Solution {
public:
    int helper(vector<int> &nums, int idx, int total){
        if(idx == nums.size()){
            return total;
        }

        return helper(nums,idx+1, total ^ nums[idx]) + helper(nums,idx+1, total);
    }
    int subsetXORSum(vector<int>& nums) {
        return helper(nums,0,0);
    }
};