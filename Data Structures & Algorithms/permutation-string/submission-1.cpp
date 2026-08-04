class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if(n > m) return false;

        vector<int> count(26, 0);

        // Store frequency of s1
        for(char c : s1) {
            count[c - 'a']++;
        }

        int l = 0;

        for(int r = 0; r < m; r++) {
            // Include current character in window
            count[s2[r] - 'a']--;

            // If window size exceeds n, shrink from left
            if(r - l + 1 > n) {
                count[s2[l] - 'a']++;
                l++;
            }

            // If window size == n, check if all zero
            if(r - l + 1 == n) {
                if(all_of(count.begin(), count.end(), [](int x){ return x == 0; })) {
                    return true;
                }
            }
        }

        return false;
    }
};