class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> temp(10001,0);

        for(auto it : trips){
            temp[it[1]] += it[0];
            temp[it[2]] -= it[0];
        }
        int ans = 0;
        for(int i = 0; i < 10001; i++){
            ans += temp[i];

            if(ans > capacity){
                return false;
            }
        }
        return true;
    }
};