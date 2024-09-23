Given n non-negative integers representing an elevation 
map where the width of each bar is 1, compute how much 
water it can trap after raining.

//code
int trap(vector<int>& height){
    int n = height.size();
    int left[n];
    int right[n];
    left[0] = height[0];
    for(int i=1;i<n;i++){
        left[i] = max(left[i-1], height[i]);
    }
    right[n-1] = height[n-1];
    for(int i=n-2;i>=0;i--){
        right[i] = max(right[i+1], height[i]);
    }
    int ans = 0;
    for(int i=0;i<n;i++)
        ans += (min(left[i], right[i]) - height[i]);
    return ans;
}

//optimal approach
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int leftMax = height[left];
        int rightMax = height[right];
        int water = 0;

        while (left < right) {
            if (leftMax < rightMax) {
                left++;
                leftMax = max(leftMax, height[left]);
                water += leftMax - height[left];
            } else {
                right--;
                rightMax = max(rightMax, height[right]);
                water += rightMax - height[right];
            }
        }

        return water;        
    }
};