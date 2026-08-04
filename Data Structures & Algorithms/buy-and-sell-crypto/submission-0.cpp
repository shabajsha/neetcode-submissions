class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int profit = 0;
        for(int num : prices){
            mini = min(mini,num);
            cout << num << " " << mini << endl;
            profit = max(profit,num - mini);
        }
        return profit;
    }
};
