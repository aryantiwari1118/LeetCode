#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumSum(std::vector<int>& arr) {
        int n = arr.size();
        
        // State variables initialized for index 0
        int no_del = arr[0];
        int one_del = arr[0]; // Initially, no valid deletion can leave a non-empty subarray
        int max_sum = arr[0];
        
        for (int i = 1; i < n; i++) {
            // Store previous states before updating
            int prev_no_del = no_del;
            int prev_one_del = one_del;
            
            // 1. Update one_del state
            // Either delete current item (prev_no_del) OR keep it and include previous deletion (prev_one_del + arr[i])
            one_del = std::max(prev_no_del, prev_one_del + arr[i]);
            
            // 2. Update no_del state (Standard Kadane's algorithm)
            no_del = std::max(arr[i], prev_no_del + arr[i]);
            
            // 3. Track the maximum result overall
            max_sum = std::max({max_sum, no_del, one_del});
        }
        
        return max_sum;
    }
};
