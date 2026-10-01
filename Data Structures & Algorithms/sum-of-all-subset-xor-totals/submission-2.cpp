class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int orSum = 0;
        
        for(auto it : nums){
            orSum |= it;
        }
        int n = nums.size();
        return orSum * (1 << (n-1));
    }
};