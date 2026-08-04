    class Solution {
    private:
        int searchArray(vector<vector<int>> &array,vector<int> &temp){
            if(array.size() == 0){
                return -1;
            }
            // int flag = 0;

            for(int i = 0; i < array.size(); i++){
                int found = true;
                for(int j = 0;j < 26 ; j++){
                    if(array[i][j] != temp[j]){
                        found = false;
                        break;
                    }
                }
                if(found){
                    return i;
                }
            }
            return -1;
        }
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            // unordered_map <int, vector<string>> Map;
            vector<vector<int>> array;
            vector<vector<string>> ans;
            for(auto it: strs){
                vector<int> temp(26,0);
                
                for(auto letter: it){
                    temp[letter-'a']++;
                }
                int index = searchArray(array,temp);
                if(index == -1){
                    array.push_back(temp);
                    ans.push_back({it});
                    // Map[Map.size()].pushback(it);
                }
                else{
                    // Map[index].pushback(it);
                    // array[index].push_back(temp);
                    ans[index].push_back(it);
                }
            }
            return ans;
        }
    };
