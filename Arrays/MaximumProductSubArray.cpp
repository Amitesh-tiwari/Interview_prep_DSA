Problem statement
Given an array ‘Arr’ that has ‘N’ elements. You have 
to find the subarray of ‘Arr’ that has the largest 
product. You must return the product of the subarray 
with the maximum product.
 
 //code
 #include<vector>
#include<climits>
#include<limits.h>

int subarrayWithMaxProduct(vector<int> &arr){
	int n = arr.size(); //size of array.
    int pre = 1, suff = 1;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (pre == 0) pre = 1;
        if (suff == 0) suff = 1;
        pre *= arr[i];
        suff *= arr[n - i - 1];
        ans = max(ans, max(pre, suff));
    }
    return ans;
}