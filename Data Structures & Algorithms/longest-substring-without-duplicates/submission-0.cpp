class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <int,int> hash;
        int n = s.length();
        int maxi = 0;
        for(int i = 0; i < n; i++){
            if(hash[s[i]] == 0){
                cout << "Hi" << endl;
                hash[s[i]] = 1;
                maxi = i;
            }
            else{
                break;
            }
        }
        cout << "Cur" << maxi << endl;
        for(int i = 0; i < n; i++){
            if(i+maxi < n){
                string temp = s.substr(i,maxi+1);
                cout << "temp " << temp << endl;
                unordered_map <int,int> tempHash;
                bool flag = true;
                for(char c : temp){
                    if(tempHash[c] == 0){
                        tempHash[c] = 1;
                    }
                    else{
                        flag = false;
                        break;
                    }
                }
                cout << "Bool " << flag << endl;
                if(flag){
                    int k = i+maxi+1;
                    cout << "cur str " << temp << endl;
                    cout << "cur idx " << k << endl;
                    while(k < n && tempHash[s[k]] == 0){
                        temp += s[k];
                        tempHash[s[k]] = 1;
                        k++;
                        // maxi = max(,maxi);
                    }
                    int modMax = temp.length();
                    maxi = max(modMax,maxi);
                    cout << "mod str " << temp << endl;
                    cout << "new "<<k<< endl;
                }
                cout << maxi << endl;
            }
        }
        return maxi;
    }
};
