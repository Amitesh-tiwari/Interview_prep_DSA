A sentence is a list of words that are separated by a 
single space with no leading or trailing spaces.

You are given an array of strings sentences, where each 
sentences[i] represents a single sentence.

Return the maximum number of words that appear in a single
 sentence.

 //code
    int maxNumberOfWordsInSentence(vector<string>& sentences) {
        int maxWords = 0;
        for (string sentence : sentences) {
            int words = 1;
            for (char c : sentence) {
                if (c == ' ') {
                    words++;
                }
            }
            maxWords = max(maxWords, words);
        }
        return maxWords;
    }

//easier approach
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int cnt = 0, max = 0;
        for(auto s : sentences){
            cnt = 0;
            for(auto x : s){
                if(x == ' ') cnt++;
            }
            if(++cnt > max) max = cnt;
        }
        return max;
        
    }
};