Problem statement
You are given a positive integer K. Your task is to find 
out whether K is a perfect number or not.

Note :
Perfect numbers are those numbers that are equal to the 
sum of all its proper divisors.

//code
bool perfectNumber(int n){
    int sum = 0;
    for(int i=1;i*i <=n;i++){
        if(n%i == 0){
            if(i*i == n || i == 1){
                sum += i;
            }
            else{
                sum += i + n/i;
            }
        }
    }

    if(sum == n)
        return true;
    else
        return false;
}