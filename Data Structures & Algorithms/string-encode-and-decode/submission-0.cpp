class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string;
        string lengths;
        for(auto it: strs){
            int size = it.length();
            encoded_string += it;
            lengths = lengths + '#' + to_string(size);
        }
        lengths += '|';
        encoded_string = lengths +encoded_string;
        // cout << encoded_string;
        return encoded_string;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<int> sizes;
        vector<string> strs2;
        while(s[i] != '|'){
            if(s[i] == '#'){
                string temp = "";
                i++;
                while(s[i] != '#' && s[i] != '|'){
                    temp += s[i];
                    i++;
                }
                sizes.push_back(stoi(temp));
            }
            else{
                i++;
            }
        }
        i++;
        for(int index = 0; index < sizes.size(); index++){
            int len = sizes[index];
            string ans = "";

            for(int j = 0; j < len; j++){
                ans += s[i++];
            }

            strs2.push_back(ans);
        }
        
        return strs2;
    }
};
