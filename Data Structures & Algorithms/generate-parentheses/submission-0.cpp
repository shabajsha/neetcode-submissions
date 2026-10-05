class Solution {
public:
    void helper(vector<string>& ans, int n, int open, int close, string cur){
        if(close > open){
            return;
        }
        if (open > n)
            return;

        if(close + open == 2 * n){
            ans.push_back(cur);
            return;
        }
        
        helper(ans,n,open+1,close,cur + '(');
        helper(ans,n,open,close+1,cur + ')');
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        helper(ans,n,0,0,"");
        return ans;
    }
};
