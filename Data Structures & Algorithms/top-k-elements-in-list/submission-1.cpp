class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int> freqArray(2001,0);
        vector<int> ans;
        int maxx = 0;
        for(auto it: nums){
            freqArray[it+1000]++;
            maxx = max(maxx,freqArray[it+1000]);
        }
        // int b[maxx] = {0};
        vector<vector<int>> b(maxx+1);

        for(int i = 2000; i >= 0; i--){
            if (freqArray[i] > 0) b[freqArray[i]].push_back(i - 1000);
        }
        int i = 0;
        int index = maxx;
        while(i < k){
            while(index >= 0 && b[index].empty()) index--;
            if (index < 0) break;
            ans.push_back(b[index].back());
            b[index].pop_back();

            i++;
        }
        return ans;
    }
};
