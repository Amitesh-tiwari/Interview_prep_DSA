Problem statement
Given two strings, 'S' and 'T' with lengths 'M' and 'N', 
find the length of the 'Longest Common Subsequence'.

For a string 'str'(per se) of length K, the subsequences 
are the strings containing characters in the same relative
 order as they are present in 'str,' but not necessarily 
 contiguous. Subsequences contain all the strings of length 
 varying from 0 to K.

Example :
Subsequences of string "abc" are:  ""(empty string), a, b, 
c, ab, bc, ac, abc.
//code

#include<vector>

int solve(string& s, string& t, int i, int j,vector<vector<int>> dp){

	if(i == s.length())
		return 0;

	if(j == t.length())
		return 0;

	if(dp[i][j] != -1){
		return dp[i][j];
	}
	
	int ans = 0;
	if(s[i] == t[j]){
		ans = 1 + solve(s,t,i+1,j+1,dp);
	}
	else{
		ans = max(solve(s,t,i+1,j,dp), solve(s,t,i,j+1,dp));
	}

	return dp[i][j] = ans;

}


int lcs(string s, string t)
{
	vector<vector<int>> dp (s.length(), vector<int> (t.length(),-1));
	return solve(s,t,0,0,dp);
}