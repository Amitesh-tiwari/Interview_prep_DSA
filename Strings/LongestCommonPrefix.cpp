Write a function to find the longest common prefix 
string amongst an array of strings.

If there is no common prefix, return an empty string "".

//code
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        for(int i = 0;i<strs[0].size();i++){
            for(int j = 1;j<n;j++){
                if(strs[j].size() <= i || strs[j][i] != strs[0][i]){
                    return strs[0].substr(0,i);
                }
            }
        }
        return strs[0];
        
    }
};