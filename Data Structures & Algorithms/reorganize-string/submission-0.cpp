class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        int n = s.length();
        for(char c : s){
            mp[c]++;
            // if(mp[c] > n/2){
            //     return "";
            // }
        }
        
        priority_queue<pair<int,char>> pq;
        for(auto it : mp){
            pq.push({it.second, it.first});
        }

        pair<int,char> temp = {0, ' '};
        string ans = "";
        while(!pq.empty() || temp.first > 0){
            if(pq.empty() && temp.first > 0){
                return "";
            }

            auto [count, curChar] = pq.top();
            pq.pop();
            count--;
            ans += curChar;

            if(temp.first > 0){
                pq.push(temp);
            }
            temp = {count,curChar};
        }
        return ans;
    }
};