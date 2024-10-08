Given two strings s and t, return true if s is a 
subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed 
from the original string by deleting some (can be none) 
of the characters without disturbing the relative 
positions of the remaining characters. (i.e., "ace" is a 
subsequence of "abcde" while "aec" is not).

//code
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for(int j = 0;j<t.size();j++){
            if(s[i]==t[j]){
                i++;
            }
        }
        return i==s.size();
    }
};
int main() {
    string s = "abc";
    string t = "ahbgdc";
    if (isSubsequence(s, t)) {
        cout << s << " is a subsequence of " << t << endl;
    } else {
        cout << s << " is not a subsequence of " << t << endl;
    }
    return 0;
}