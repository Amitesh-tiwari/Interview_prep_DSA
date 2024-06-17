You are given an integer array prices where prices[i] 
is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. 
You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

//code
class Solution {
public:
    int solve(int index, int buy,vector<int>& prices,vector<vector<int> > &dp){
        if(index == prices.size())
            return 0;
        if(dp[index][buy] != -1){
            return dp[index][buy];
        }
        int profit = 0;
        if(buy){
            int buyKaro = -prices[index] + solve(index+1,0,prices,dp);
            int skipKaro = 0 + solve(index+1,1,prices,dp);
            profit = max(buyKaro,skipKaro);
        }
        else{
            int sellKaro = +prices[index] + solve(index+1,1,prices,dp);
            int skipKaro = 0 + solve(index+1,0,prices,dp);
            profit = max(sellKaro,skipKaro);
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int> > dp(n, vector<int> (2,-1));
        return solve(0,1,prices,dp);
        
    }
};

//optimal solution
class Solution {
public:
        int maxProfit(vector<int>& prices) {
        int  n = prices.size();
        int maxi = 0,profit=0;
        int buy=prices[0];
        for(int i=0;i<n;i++){
            if(prices[i]<buy){
                buy=prices[i];
            }
            else{
                profit=prices[i]-buy;
                buy=prices[i];
                maxi+=profit;
            }
        }
        return maxi;
    }
};