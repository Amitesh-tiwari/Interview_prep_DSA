Remove characters from a string except alphabets

Problem Statement: Write a program to remove all characters
from a string except alphabets in a given string.

//code

#include <bits/stdc++.h>
using namespace std;

string solve(string str, int n){
    string ans = "";
    for(int i=0;i<n;i++){
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')){
            ans += str[i];
        }
    }
    return ans;
}

int main(){
    string str = "a!b@c#1d$e%f^g&h*i";
    int n = str.size();
    cout<<solve(str, n);
    return 0;
}