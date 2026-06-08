class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxHeight=0;
        int left=0;
        int right = heights.size()-1;
        while (left < right) {
          
            int currentArea = min(heights[left], heights[right]) * (right - left);
            maxHeight = max(maxHeight, currentArea);
           
            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxHeight;
    }
};
