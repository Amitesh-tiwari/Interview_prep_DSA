Given two string arrays word1 and word2, return true if 
the two arrays represent the same string, and false 
otherwise.

A string is represented by an array if the array elements
concatenated in order forms the string.

//code
bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2)

{
    string s1 = "", s2 = "";
    for(auto x : word1) s1 += x;
    for(auto x : word2) s2 += x;
    return s1 == s2;
}

//easy approach
using namespace std;
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string wordOne = "";
        string wordTwo = "";
        for(int i = 0 ; i < word1.size();i++)
        {
            wordOne+=word1[i];
        }
        for(int i = 0 ; i < word2.size();i++)
        {
            wordTwo+=word2[i];
        }

        if(wordOne == wordTwo)
        {
            return true;
        }
        else {
            return false ;
        }
    }
};