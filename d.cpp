Problem statement
You have been given an array/list 'HEIGHTS' of length ‘N.
 'HEIGHTS' represents the histogram and each element of 
 'HEIGHTS' represents the height of the histogram bar. 
 Consider that the width of each histogram is 1.

You are supposed to return the area of the largest 
rectangle possible in the given histogram.

int largestRectangle(vector < int > & heights) {
    int n = heights.size();
    stack < int > s;
    int maxArea = 0;
    for (int i = 0; i <= n; i++) {
        int h = (i == n ? 0 : heights[i]);
        if (s.empty() || h >= heights[s.top()]) {
            s.push(i);
        } else {
            int tp = s.top();
            s.pop();
            maxArea = max(maxArea, heights[tp] * (s.empty() ? i : i - 1 - s.top()));
            i--;
        }
    }
    return maxArea;
}