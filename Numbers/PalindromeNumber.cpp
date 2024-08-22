Check whether a given number ’n’ is a palindrome number.
Note :
Palindrome numbers are the numbers that don't change 
when reversed.
You don’t need to print anything. Just implement the 
given function.

//code

bool palindrome(int n){
    int temp = n;
    int rev = 0;
    while(n > 0){
        int rem = n % 10;
        rev = rev * 10 + rem;
        n = n / 10;
    }
    return temp == rev;
}