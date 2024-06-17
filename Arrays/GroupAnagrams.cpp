Given an array of strings strs, group the anagrams together. 
You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters 
of a different word or phrase, typically using all the original 
letters exactly once.

//code
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> mymap;
        int n = strs.size();
        string temp;
        
        for(int i = 0;i<n;i++){
            temp = strs[i];
            sort(strs[i].begin(),strs[i].end());
            mymap[strs[i]].push_back(temp);
            
        }
        
        vector<vector<string>> result;
        for(auto itr = mymap.begin(); itr != mymap.end();itr++){
            result.push_back(itr->second);
        }
        
        return result;
        
    }
};


 