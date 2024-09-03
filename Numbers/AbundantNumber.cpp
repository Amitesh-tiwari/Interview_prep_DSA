Problem Statement: Check if the number is an abundant 
number or not.
Definition: If the sum of divisors of a number is greater
than the number then it is called abundant number.

//code
int main(){
    int n;
    cin>>n;
    int sum = 0;
    for(int i =0;i<=n;i++){
        if(n%i == 0){
            sum += i;
        }

    }
    sum -= n;
    if(sum > n){
        cout<<"Abundant Number";
    }
    else{
        cout<<"Not an Abundant Number";
    }
}