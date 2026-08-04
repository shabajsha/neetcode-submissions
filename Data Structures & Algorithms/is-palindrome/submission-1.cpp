class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length()-1;
        int n = s.length();
        while(left < right){
            while (left < n && !isalnum(s[left])){
                left++;
            }
            while(right > 0 && !isalnum(s[right])){
                right--;
            }
            if(isalnum(s[left]) && isalnum(s[right]) && tolower(s[left]) != tolower(s[right])){
                // cout << s[left] << " " << s[right];
                return false;
            }
            left++;right--;
        }
        return true;
    }
};
