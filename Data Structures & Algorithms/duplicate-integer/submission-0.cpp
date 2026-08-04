class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> Map;
        for(auto it : nums){
            if(Map[it] != 0){
                return true;
            }
            else{
                Map[it]++;
            }
        }
        return false;
    }
};