class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map <int,int> hash;
        int n = nums.size();
        // int count = 0;
        int maxi = 0;
        for(int num: nums){
            hash[num] = 1;
        }   
        
        for(int num: nums){
            if(hash[num-1] == 0){
                int count = 1;
                int temp = num;
                while(hash[temp+1] == 1){
                    count++;temp++;
                }
                maxi = max(maxi,count);
            }
        }

        return maxi;

    }
};
