Given two strings needle and haystack, return 
the index of the first occurrence of needle in 
haystack, or -1 if needle is not part of haystack.

//code

class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = 0;
        if(needle.length() > haystack.length()){
            return -1;
        }
        int n = needle.length();
        int m = haystack.length();
        for(int i = 0;i<m;i++){
            if(haystack[i] == needle[index]){
                index++;
            }
            else{
                i = i-index;
                index = 0;
            }
            
            if(index == needle.length()){
                return i-index+1;
            }
        }
        return -1;
        
    }
};