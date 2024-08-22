Problem statement
A prime number is a positive integer that is divisible 
by exactly 2 integers, 1 and the number itself.

You are given a number 'n'.
Find out whether 'n' is prime or not.

//code
bool isPrime(int n){
    if(n <= 1){
        return false;
    }
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
    
}

//same approach
//it works but with TLE the approach is right
if(n <= 1){
        return false;
    }
    for(int i = 2; i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;