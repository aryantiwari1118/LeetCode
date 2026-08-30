#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n; 

        int min_idx = 0;
        int max_idx = 0;

        
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[min_idx]) {
                min_idx = i;
            }
            if (nums[i] > nums[max_idx]) {
                max_idx = i;
            }
        }

       
        int first = min(min_idx, max_idx);
        int second = max(min_idx, max_idx);

        
        int delete_from_left = second + 1;
        int delete_from_right = n - first;
        int delete_from_both = (first + 1) + (n - second);

        
        return min({delete_from_left, delete_from_right, delete_from_both});
    }
};
