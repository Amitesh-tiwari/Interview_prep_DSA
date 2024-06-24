You are given an integer array height of length n. 
There are n vertical lines drawn such that the 
two endpoints of the ith line are (i, 0) and 
(i, height[i]).

Find two lines that together with the x-axis 
form a container, such that the container contains 
the most water.

Return the maximum amount of water a container can 
store.

Notice that you may not slant the container.

//code
class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size();
        int i = 0,j = n-1, mx = INT_MIN;
        while(i < j){
            int water = (j-i)*min(height[i],height[j]);
            mx = max(mx,water);
            if(height[i] < height[j])
                i++;
            else
                j--;
        }
        return mx;
    }
};