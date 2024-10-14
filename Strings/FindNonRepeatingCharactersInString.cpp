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

//another approach

#include <iostream>
using namespace std;
int main()
{
    //Initializing variables.
    char str[100]="prepinsta";
    int i;
    int freq[256] = {0};
    
    //Calculating frequency of each character.
    for(i = 0; str[i] != '\0'; i++)
    {
        freq[str[i]]++;
    }
    cout<<"The non repeating characters are: ";
    for(i = 0; i < 256; i++)
    {
        if(freq[i] == 1)//Finding non repeating charcters and printing them.
        {
           cout<<char(i)<<"  " ;
        }
    }
    return 0;
}