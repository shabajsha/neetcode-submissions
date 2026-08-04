class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, r = 0, minlen = 9999;
        string minstring = "";
        // vector<int> hash(256,0);
        vector<int> hash(256, 0);
        vector<int> hash2(256, 0);
        for(int c : t){
            hash[c]++;
        }
        string hashResult = "";
        for(int t : hash){
            hashResult += to_string(t);
        }
        // cout << "dd";
        cout << hashResult << endl;
        while(r < s.length()){
            int count = 0;
            string hash2Result = "";
            // if(hash[s[r]] != 0){
            // }
            hash2[s[r]]++;

            // hash[s[r]]--;
            // cout << "s[r] : "<<s[r] << endl;
            // cout << "hash[s[r]] : "<< hash[s[r]] << endl;
            // cout << "hash2[s[r]] : "<< hash2[s[r]] << endl;

            // cout << "coutn is " << count <<endl;

            bool valid = true;

            for(int i = 0; i < 256; i++){
                if(hash2[i] < hash[i]){
                    valid = false;
                    break;
                }
            }

            // if(valid)

            cout << hash2Result << endl;
            if(valid){
                // bool valid = true;
                // while(hash[s[l]] == 0){
                //     l++;
                // }
                cout << "jhi" << endl;
                cout << minlen << endl;
                cout << "----" << endl;
                cout << r-l+1 << endl;

                cout << "we" << endl;
                if((r - l + 1) < minlen){
                    minlen = r - l + 1;
                    minstring = s.substr(l, minlen);
                }
                cout << minlen << endl;
                cout << minstring << endl;
                // hash2[s[l]]--;
                // l++;

                // while(valid)
                // // count--; 

                while(valid){
                    if((r - l + 1) < minlen){
                        minlen = r - l + 1;
                        minstring = s.substr(l, minlen);
                    }

                    hash2[s[l]]--;
                    l++;

                    // recompute validity after shrinking
                    valid = true;
                    for(int i = 0; i < 256; i++){
                        if(hash2[i] < hash[i]){
                            valid = false;
                            break;
                        }
                    }
                }
            }
            r++;
        }
        return minstring;
    }
};
