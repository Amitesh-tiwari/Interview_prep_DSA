Problem statement
You have been given an array ‘a’ of ‘n’ unique non-negative integers.
Find the second largest and second smallest element from the array.
Return the two elements (second largest and second smallest) as 
another array of size 2.

//code

vector<int> getSecondOrderElements(int n, vector<int> a){
    vector<int> res;
    if(n<2){
        return res;
    }
    sort(a.begin(),a.end());
    res.push_back(a[1]);
    res.push_back(a[n-2]);
    return res;
}