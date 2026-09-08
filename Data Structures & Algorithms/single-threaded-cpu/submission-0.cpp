class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<pair<int,pair<int,int>>> temp;
        for(int i = 0; i < tasks.size(); i++){
            temp.push_back({i, {tasks[i][0], tasks[i][1]}});
        }
        sort(temp.begin(), temp.end(),[] (const auto &a , const auto &b){
            return a.second.first < b.second.first;
        });


        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;

        vector<int> ans;
        // pq.push({temp[0].second.second, temp[0].first});
        int idx = 0;
        // while(temp[idx].second.first == temp[0].second.first){
        //     pq.push({temp[idx].second.second, temp[idx].first});        
        //     idx++;
        // }
        long long currentTime = 0;

        // ans.push_back(temp[0].first);
        // while(!pq.empty()){
        //     int cur = pq.top().first;
        //     int curIdx = pq.top().second;
        //     pq.pop();
        //     while(idx < temp.size() && temp[curIdx].second.first + cur >= temp[idx].second.first ){
        //         pq.push({temp[idx].second.second, temp[idx].first});
        //         idx++;
        //     }

        //     ans.push_back(curIdx);
        // }   


        while (idx < temp.size() || !pq.empty()) {

            // CPU is idle
            if (pq.empty()) {
                currentTime = max(
                    currentTime,
                    (long long)temp[idx].second.first
                );
            }

            // Add all tasks that have arrived
            while (idx < temp.size() &&
                   temp[idx].second.first <= currentTime) {

                pq.push({
                    temp[idx].second.second, // processing time
                    temp[idx].first          // original index
                });

                idx++;
            }

            // Take shortest processing time
            auto [processingTime, originalIndex] = pq.top();
            pq.pop();

            ans.push_back(originalIndex);

            // CPU finishes this task
            currentTime += processingTime;
        }

        return ans;
    }
};