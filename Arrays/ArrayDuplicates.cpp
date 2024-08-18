Given an array arr of size n which contains elements in 
range from 0 to n-1, you need to find all the elements 
occurring more than once in the given array. Return the 
answer in ascending order. If no such element is found, 
return list containing [-1]. 

//code
vector<int> duplicates(vector<long long> arr) {
    vector<int> res;
    for (int i = 0; i < arr.size(); i++) {
        int index = arr[i] % arr.size();
        arr[index] += arr.size();
    }
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] / arr.size() > 1) {
            res.push_back(i);
        }
    }
    if (res.size() == 0) {
        res.push_back(-1);
    }
    return res;
}