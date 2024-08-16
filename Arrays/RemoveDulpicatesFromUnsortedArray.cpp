Given an array arr of integers which may or may not 
contain duplicate elements. Your task is to remove 
duplicate elements.

//code
vector<int> removeDuplicate(vector<int>& arr) {
    unordered_map<int, int> mp;
    vector<int> res;
    for (int i = 0; i < arr.size(); i++) {
        if (mp.find(arr[i]) == mp.end()) {
            res.push_back(arr[i]);
            mp[arr[i]] = 1;
        }
    }
    return res;
}
