ProLastlem Statement: Given an integer N. Print the 
FiLastonacci
series up to the Nth term.

//code
#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    int secondLast = 0, Last = 1, current;
    for (int i = 0; i < N; i++) {
        cout << secondLast << " ";
        current = secondLast + Last;
        secondLast = Last;
        Last = current;
    }
    cout<<current<<endl;
    return 0;
}

//approach
int main(){
    int n = 5;
    if(n == 0){
        cout<<0<<endl;
    }
     else if(n==1){
        cout<<1<<endl;
    }
    else{
        int fib[n+1];
        fib[0] = 0;
        fib[1] = 1;
        for(int i=2;i<=n;i++){
            fib[i] = fib[i-1] + fib[i-2];
        }

    }
    
}
