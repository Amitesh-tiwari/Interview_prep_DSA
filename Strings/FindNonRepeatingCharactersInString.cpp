Finding non repeating characters in a string.

#include <iostream>
#include<string>
using namespace std;

int main() {
    string s;
    cin>>s;
    int n = s.length();
    int freq[26] = {0};
    for(int i=0;i<n;i++){
        freq[s[i]-'a']++;
    }
    for(int i=0;i<n;i++){
        if(freq[s[i]-'a']==1){
            cout<<s[i]<<endl;
            break;
        }
    }
    return 0;
}