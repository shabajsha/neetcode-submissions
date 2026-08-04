class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // vector<int> prefix(n,0);
        // vector<int> suffix(n,0);

        vector<int> ans(n,1);

                
        // prefix[0] = -1;
        // suffix[n-1] = -1;

        int prev = nums[0];
        int post = nums[n-1];

        int i = 1, j = n-2;

        while(i < n-1 && j >= 1){
            // prefix[i] = prev;
            // suffix[j] = post;
    
            ans[i] = ans[i] * prev;
            ans[j] = ans[j] * post;
            prev *= nums[i];
            post *= nums[j];
            i++;j--;
        }
        ans[n-1] = prev;
        ans[0] = post;

        return ans;
    }
};
