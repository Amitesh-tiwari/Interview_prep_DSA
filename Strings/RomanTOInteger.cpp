Roman numerals are represented by seven different symbols:
I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
Given a roman numeral, convert it to an integer.
//code
int romanToString(string s){
    unordered_map<char,int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
    int ans = 0;
    for(int i=0;i<s.length(),i++){
        if(m[s[i]] < m[s[i+1]]){
            ans = ans- m[s[i]];
        }
        else{
            ans += m[s[i]];
        }
    }
    return ans;
}