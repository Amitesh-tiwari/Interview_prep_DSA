Given an integer x, return true if x is a 
palindrome
, and false otherwise.

//code
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int temp = x;
        long long int rev = 0;
        while(temp) {
            rev = rev * 10 + temp % 10;
            temp /= 10;
        }
        return rev == x;
    }
};