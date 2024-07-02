Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters
 of a different word or phrase, typically using all the 
 original letters exactly once.

 //code
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        if(n != m)
            return false;
        
        unordered_map<char,int> mymap;
        
        for(int i = 0;i<n;i++){
            mymap[s[i]]++;
            mymap[t[i]]--;
        }
        
        for(auto itr = mymap.begin();itr != mymap.end();itr++){
            if(itr->second != 0)
                return false;
        }
        
        return true;


    }
};
