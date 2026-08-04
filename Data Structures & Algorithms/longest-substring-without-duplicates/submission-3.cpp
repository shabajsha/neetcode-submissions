class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0; int r = 0;
        int n = s.length();
        // unordered_map <int,int> hash;
        int maxi = 0;
        vector<int> hash(256,-1);
        while(r < n){
            if(hash[s[r]] != -1){
                if(hash[s[r]] >= l){
                    l = hash[s[r]]+1;
                }
            }
            hash[s[r]] = r;
            maxi = max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};
