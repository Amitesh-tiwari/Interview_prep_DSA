Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. 
The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated
 by a single space.

Note that s may contain leading or trailing spaces or 
multiple spaces between two words. The returned string 
should only have a single space separating the words. 
Do not include any extra spaces.

//code
string reverseWords(string s) {
        string ans = "";
        string word = "";
        for(int i=0;i<s.size();i++){
            if(s[i] == ' '){
                if(word.size() > 0){
                    if(ans.size() > 0){
                        ans = word + " " + ans;
                    }
                    else{
                        ans = word;
                    }
                    word = "";
                }
            }
            else{
                word += s[i];
            }
        }
        if(word.size() > 0){
            if(ans.size() > 0){
                ans = word + " " + ans;
            }
            else{
                ans = word;
            }
        }
        return ans;
}