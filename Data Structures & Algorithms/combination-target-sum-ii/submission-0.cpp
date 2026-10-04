class Solution {
private:
    void helper(vector<int>& candidates, int target, int idx,
                vector<vector<int>>& ans, vector<int>& subset) {

        if (target == 0) {
            ans.push_back(subset);
            return;
        }

        if (idx >= candidates.size() || target < 0) {
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {

            // Skip duplicates at the same recursion level
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;

            // Since sorted, no later element can work
            if (candidates[i] > target)
                break;

            subset.push_back(candidates[i]);

            // i + 1 because each element can be used only once
            helper(candidates, target - candidates[i],
                   i + 1, ans, subset);

            subset.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> subset;

        helper(candidates, target, 0, ans, subset);

        return ans;
    }
};