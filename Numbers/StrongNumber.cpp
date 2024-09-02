Check if a number is a Strong Number or not

Problem Statement: Given an integer Print “YES” if it is
a strong number else print “NO”.

//code

int Factorial(int n){
    int fact = 1;
    for(int i = 0;i<=n;i++){
        fact = fact*i;
    }
    return fact;
}

int StrongNumber(int num){
    int sum = 0;
    while(num > 0){
        int digit = num%10;
        sum += Factorial(digit);
        num = num/10;
    }

    return sum;
}