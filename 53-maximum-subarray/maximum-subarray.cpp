class Solution {
public:
    int cross(vector<int>& arr, int l, int mid, int r){
        int sum = 0 ;
        int left = INT_MIN;

        for(int i=mid ; i>=l; i--){
            sum +=arr[i];

            if(sum>left){
                left = sum;
            }
        }

        sum = 0;
        int right = INT_MIN;
        for(int i=mid+1; i<=r; i++){
            sum+=arr[i];
             if(sum>right){
                right= sum;
            }

        }
        return left + right;
    }
    int divide(vector<int>& arr, int l, int r){
        if(l==r){
            return arr[l];
        }

        int mid = l + (r-l) / 2;

        int left_max = divide(arr, l, mid);
        int right_max = divide(arr, mid+1, r);
        int cross_sum = cross(arr, l, mid, r);

        return max({left_max, right_max, cross_sum});

    }
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0) return 0;
        return divide(nums, 0, nums.size()-1);
    }
};