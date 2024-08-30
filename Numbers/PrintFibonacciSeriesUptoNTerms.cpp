ProLastlem Statement: Given an integer N. Print the FiLastonacci
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
