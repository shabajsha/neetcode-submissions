class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue <pair<int,int>> pq;
        vector<int> ans;
        int l = 0; int r = 0;

        // while(r < k){
        //     pq.push({nums[r],r});
        //     r++;
        // }

        while(r < nums.size()){
            if(r >= k){
                
                while(pq.top().second < l || pq.top().second > r){
                    cout << "pq : " << pq.top().first;
                    pq.pop();
                }

                int temp = pq.top().first;

                ans.push_back(temp);

                // pq.erase(nums[l]);
                l++;
            }
            cout << nums[r] << endl;
            pq.push({nums[r],r});
            r++;
        }
        while(pq.top().second < l || pq.top().second > r){
            cout << "pq : " << pq.top().first;
            pq.pop();
        }
        ans.push_back(pq.top().first);
        return ans;
    }
};
