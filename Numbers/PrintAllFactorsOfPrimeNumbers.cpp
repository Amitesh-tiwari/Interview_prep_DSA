Problem Statement: Given an integer N, print all of 
its prime factors.

//code

bool checkPrime(int n){
    int cnt = 0;
    for(int i=1;i*i < n;i++){
        if(n%i == 0){
            cnt++;
        }
        if(n/i == 0){
            cnt++;
        }
    }
    if(cnt == 2){
        return true;
    }
    return false;
}

vector<int> FactorsPrime(int n){
    vector<int> primes;
    for(int i=2;i<=n;i++){
        if(n%i == 0 && checkPrime(i)){
            primes.push_back(i);
        }
    }
}