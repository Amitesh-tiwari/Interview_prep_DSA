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
                    //The condition checks two things:
                    //If the current string strs[j] is shorter 
                    //than the current index i (strs[j].size() <= i), 
                    //meaning the current string does not have a 
                    //character at index i.
                    //If the character at index i in the current string 
                    //strs[j] does not match the character at index i in the 
                    //first string strs[0] (strs[j][i] != strs[0][i]).
                    return strs[0].substr(0,i);
                }
            }
        }
        return strs[0];
        
    }
};