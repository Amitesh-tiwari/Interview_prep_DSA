Replace elements by its rank in the array

Given an array arr of N integers, the task is to replace 
each element of the array by its rank in the array. The 
rank of an element is defined as the distance between the
element with the first element of the array when the 
array is arranged in ascending order. If two or more are
same in the array then their rank is also the same as 
the rank of the first occurrence of the element. 

//code
vector<int> replaceWithRank(vector<int> &arr, int N){
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    
    unordered_map<int, int> rankMap;
    int rank = 1;
    for(int i = 0; i < N; i++){
        if(rankMap.find(sortedArr[i]) == rankMap.end()){
            rankMap[sortedArr[i]] = rank;
            rank++;
        }
    }
    vector<int> result;
    for(int i = 0; i < N; i++){
        result.push_back(rankMap[arr[i]]);
    }
    
    return result;
}