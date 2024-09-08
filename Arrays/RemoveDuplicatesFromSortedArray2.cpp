Given an integer array nums sorted in non-decreasing order,
remove some duplicates in-place such that each unique 
element appears at most twice. The relative order of the 
elements should be kept the same.

Since it is impossible to change the length of the array 
in some languages, you must instead have the result be 
placed in the first part of the array nums. More formally,
if there are k elements after removing the duplicates, 
then the first k elements of nums should hold the final 
result. It does not matter what you leave beyond the 
first k elements.

Return k after placing the final result in the first k 
slots of nums.

Do not allocate extra space for another array. You must 
do this by modifying the input array in-place with O(1) 
extra memory.

//code
int removeDuplicates(vector<int>& nums){
    int i=0;
    int count = 1;
    for(int j=1;j<nums.size();j++){
        if(nums[j] == nums[i]){
            count++;
        }
        else{
            count = 1;
        }
        if(count <= 2){
            i++;
            nums[i] = nums[j];
        }
    }
    return i+1;
}

//easy approach
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (j == 1 || nums[i] != nums[j - 2]) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};