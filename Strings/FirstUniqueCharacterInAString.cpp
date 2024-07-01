Given a string s, find the first non-repeating character 
in it and return its index. 
If it does not exist, return -1.


class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        
        for(int i = 0;i<n;i++){
            bool found = true;
            for(int j=0;j<n;j++){
                if(i != j && s[i] == s[j]){
                    found = false;
                    break;
                }
            }
            if(found)
                return i;
        }
        return -1;
    }
};