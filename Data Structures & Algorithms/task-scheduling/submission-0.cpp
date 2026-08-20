class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int, char>> pq;
        unordered_map<char,int> mp;
        for(auto it : tasks){
            mp[it]++;
        }

        for(auto it : mp){
            pq.push({it.second,it.first});
        }
        int maxi = pq.top().first - 1;
        int idle = (maxi) * n;
        pq.pop();
        while(!pq.empty()){
            int top  = pq.top().first;
            pq.pop();
            idle -= min(top,maxi);
        }
        return idle > 0 ? tasks.size()+idle : tasks.size();
    }
};