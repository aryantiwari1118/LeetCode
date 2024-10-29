class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            // Finding the mid using integer division
            int mid = low + (high - low) / 2;

            // Target value is present at the middle of the vector
            if (nums[mid] == target) {
                return mid;
            }
            // Target value is present in the low subvector
            else if (target < nums[mid]) {
                high = mid - 1;
            }
            // Target value is present in the high subvector
            else if (target > nums[mid]) {
                low = mid + 1;
            }
        }

        // Target value is not present in the vector
        return -1;
    }
};
