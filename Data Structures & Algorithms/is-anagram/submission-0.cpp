class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char,int> Map;
        for(auto it: s){
            if(Map[it] != 0){
                Map[it]++;
            }
            else{
                Map[it] = 1;
            }
        }
        for(auto it: t){
            if(Map[it] != 0){
                Map[it]--;
            }
            else{
                Map[it] = -1;
            }
        }
        for(auto it: Map){
            if(it.second != 0){
                return false;
            }
        }
        return true;
    }
};
