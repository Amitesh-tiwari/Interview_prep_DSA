Problem Statement: Check if the number is a 
Harshad(or Niven) number or not.

//code
bool isHarshadNumber(int num){
    int sum = 0;
    int temp = num;
    while(temp > 0){
        sum += temp%10;
        temp /= 10;
    }
    return num%sum == 0;
}