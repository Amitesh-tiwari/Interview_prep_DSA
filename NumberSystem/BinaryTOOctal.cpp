Convert Binary to Octal

Problem Statement: Convert a binary number to an octal 
number

//code
#include <iostream>
#include <cmath>
using namespace std;

int binaryToOctal(int n){
    int ans = 0;
    int x = 1;
    while(n>0){
        int y = n%1000;
        ans += x*y;
        x *= 10;
        n /= 1000;
    }
    return ans;
}