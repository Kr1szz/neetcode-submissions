class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Initialize with first element
        int currentSum = nums[0];
        int maxSum = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            // Either extend the previous subarray or start fresh from current element
            currentSum = max(nums[i], currentSum + nums[i]);
            // Update global maximum
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};