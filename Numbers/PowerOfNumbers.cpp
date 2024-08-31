Problem statement
You are given a number 'N' and its reverse 'R'.

Return the number raised to the power of its own reverse.
 As answers can be very large, print the result modulo 
'10^9 + 7'.

For Example:

For 'N' = 20, 'R' = 2
The answer is 400 since 20^2 as the reverse of 20 is 2.

//code
int power(int N, int R){
    int mod = 1000000007;
    int ans = 1;
    for(int i=0;i<R;i++){
        ans = (ans*N)%mod;
    }
    return ans;
}