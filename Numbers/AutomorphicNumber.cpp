Problem Statement: Given a number, check if it is 
automorphic or not. A number is called an Automorphic 
number if and only if its square ends in the same digits 
as the number itself.

//code

bool Automorphic(int N){
    int sq = N*N;
    while(N > 0){
        if(N%10 != sq%10){
            return false;
        }
        N = N/10;
        sq = sq/10;
    }
    return true;
}