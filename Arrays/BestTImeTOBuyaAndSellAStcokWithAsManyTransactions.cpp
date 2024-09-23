 Best Time to Buy and Sell
You are given an array(PRICES) of stock prices for N 
consecutive days. Your task is to find the maximum profit 
that you can make by completing as many transactions as 
you like, where a transaction denotes buying one and 
selling one share of the stock.

//code
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        for(int i = 1; i < n; i++) {
            if(prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};

int main() {
    Solution solution;
    vector<int> prices = {7, 1, 5, 3, 6, 4}; // Example stock prices
    int result = solution.maxProfit(prices);
    cout << "Maximum profit: " << result << endl;
    return 0;
}