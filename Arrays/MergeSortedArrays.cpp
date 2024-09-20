You are given two integer arrays nums1 and nums2, sorted 
in non-decreasing order, and two integers m and n, 
representing the number of elements in nums1 and nums2
respectively.

Merge nums1 and nums2 into a single array sorted in 
non-decreasing order.

The final sorted array should not be returned by the 
function, but instead be stored inside the array nums1.
To accommodate this, nums1 has a length of m + n, where
the first m elements denote the elements that should be
merged, and the last n elements are set to 0 and should
be ignored. nums2 has a length of n.

//code
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k] = nums1[i];
            i--;
        }
        else
        {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }
    while (j >= 0)
    {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
} 

//explanation
// //int i = m - 1;: This variable i is initialized to the 
// //last index of the initialized elements in nums1.
// //int j = n - 1;: This variable j is initialized to the 
// //last index of the initialized elements in nums2.
// //int k = m + n - 1;: This variable k is initialized to 
// //the last index of the total space available in nums1.
// //while (i >= 0 && j >= 0): This loop continues until we 
// //have processed all elements in either nums1 or nums2.
// // if (nums1[i] > nums2[j]): If the current element in 
// nums1 is greater than the current element in nums2, it is
//  placed at the current position k in nums1, and the index 
//  i is decremented.
// // else: If the current element in nums2 is greater or 
// equal, it is placed at the current position k in nums1, 
// and the index j is decremented.
// // nums1[k] = nums1[i];: The element from nums1 is placed 
// at position k in nums1, and both i and k are decremented.
// // nums1[k] = nums2[j];: The element from nums2 is placed 
// at position k in nums1, and both j and k are decremented.
// //while (j >= 0): This loop continues until all remaining elements in nums2 are copied to nums1.
// nums1[k] = nums2[j];: The remaining elements from nums2 
// are placed at position k in nums1, and both j and k are 
// decremented.
