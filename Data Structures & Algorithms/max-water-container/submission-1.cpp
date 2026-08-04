class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        
        int l = 0, r = n-1;
        int result = 0;
        while(l < r){

            int temp = (r-l)*min(heights[l],heights[r]);
            result = max(result,temp);
            if(heights[l] < heights[r]){
                l++;
            }
            else{
                r--;
            }

        }
        return result;
    }
};
