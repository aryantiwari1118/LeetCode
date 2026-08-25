class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
         int max_sum = nums[0];
         int sum1 = nums[0]; // Tracks running max subarray sum
         int min_sum = nums[0];
         int sum2 = nums[0]; // Tracks running min subarray sum

         for(int i = 1 ; i < nums.size() ; i++){
            // 1. Calculate choices for max subarray
            int v1 = sum1 + nums[i];
            sum1 = max(v1, nums[i]); // Save the winner back into running sum
            max_sum = max(max_sum, sum1); // Update global max

            // 2. Calculate choices for min subarray
            int v2 = sum2 + nums[i];
            sum2 = min(v2, nums[i]); // Save the winner back into running sum
            min_sum = min(min_sum, sum2); // Update global min
         }
         
         return max(abs(max_sum), abs(min_sum));
    }
};
