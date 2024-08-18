Given an array arr of size n which contains elements in 
range from 0 to n-1, you need to find all the elements 
occurring more than once in the given array. Return the 
answer in ascending order. If no such element is found, 
return list containing [-1]. 

//code
vector<int> duplicates(vector<long long> arr) {
        vector<int>b;
        vector<long long> res(arr.size(),0);
        for(int i=0;i<arr.size();i++){
            res[arr[i]]++;
        }
        for(int i=0;i<res.size();i++){
            if(res[i]>1){
                b.push_back(i);
            }
        }
        if(b.empty()){
            b.push_back(-1);
        }
        return b;
}