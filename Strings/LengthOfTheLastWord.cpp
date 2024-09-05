Given a string s consisting of words and spaces, return 
the length of the last word in the string.

A word is a maximal 
substring consisting of non-space characters only.

int lengthOfLastWord(string s){
    int n = s.size();
    int count = 0;
    for(int i = n-1;i>=0;i--){
        if(s[i] == ' '){
            if(count > 0){
                return count;
            }
        }
        else{
            count++;
        }
    }
    if(count > 0){
        return count;
    }
    return 0;
}

//approach 2
class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        bool counting = false;
        
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                counting = true;
                length++;
            }
            else if (counting) {
                break;
            }
        }
        
        return length;
    }
       
};