Problem statement
Given two strings, ‘A’ and ‘B’. Return the shortest 
supersequence string ‘S’, containing both ‘A’ and ‘B’ as 
its subsequences. If there are multiple answers, return 
any of them.

Note: A string 's' is a subsequence of string 't' if 
deleting some number of characters from 't' (possibly 0) 
results in the string 's'.

//code
#include <bits/stdc++.h> 
string shortestSupersequence(string a, string b)
{
    int n = a.size();
    int m = b.size();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else if(a[i-1] == b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int i = n;
    int j = m;
    string ans = "";
    while(i>0 && j>0){
        if(a[i-1] == b[j-1]){
            ans += a[i-1];
            i--;
            j--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]){
                ans += a[i-1];
                i--;
            }
            else{
                ans += b[j-1];
                j--;
            }
        }
    }
    while(i>0){
        ans += a[i-1];
        i--;
    }
    while(j>0){
        ans += b[j-1];
        j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}