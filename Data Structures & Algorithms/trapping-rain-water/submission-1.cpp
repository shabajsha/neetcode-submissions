class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> prefix(n,0);
        vector<int> sufix(n,0);
        int maxi = 0;
        for(int i = 0; i < n ; i++){
            maxi = max(height[i],maxi);
            prefix[i] = maxi;
        }
        maxi = 0;
        for(int i = n-1; i >= 0 ; i--){
            maxi = max(height[i],maxi);
            sufix[i] = maxi;
        }

        int sum = 0;
        for(int i = 0 ; i <= n-1 ; i++){
            sum += (min(prefix[i],sufix[i]) - height[i]);
        }
        return sum;
    }
};
