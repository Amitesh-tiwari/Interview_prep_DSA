Problem statement
You are given an integer ‘NUM’ . Your task is to 
find out whether this number is an Armstrong number 
or not.

A k-digit number ‘NUM’ is an Armstrong number if and 
only if the k-th power of each digit sums to ‘NUM’.

//code
bool isArmstrong(int num){
    int temp = num;
    int sum = 0;
    int n = 0;
    while(temp > 0){
        n++;
        temp = temp / 10;
    }
    temp = num;
    while(temp > 0){
        int rem = temp % 10;
        sum += pow(rem, n);
        temp = temp / 10;
    }
    return sum == num;
}