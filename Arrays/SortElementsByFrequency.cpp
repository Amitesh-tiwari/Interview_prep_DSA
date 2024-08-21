Problem statement
You are given a list of a repeated set of integers. 
Your task for the problem is to return a list of the 
given elements in decreasing sorted order of their 
frequency of repetition in the given list with the 
element with the highest frequency of repetition first 
and so on.

Note :
If two numbers have the same frequency then keep the 
one that was present before the other in the original 
given list (array) first

//code
    // Approach:
    // 1. Create a frequency map to count the occurrences of each element.
    // 2. Sort the elements based on their frequency in descending order.
    // 3. If two elements have the same frequency, keep the one that appeared earlier in the original list.
    // 4. Return the sorted list.

    vector<int> sortByFrequency(vector<int>& nums){
        unordered_map<int, int> umap;
        for(int i = 0; i < nums.size(); i++){
            umap[nums[i]]++;
        }
        sort(nums.begin(), nums.end(), [&](int a, int b) -> bool{
            return (umap[a] != umap[b] ? umap[a] < umap[b] : a>b);
        });
        return nums;
    }
