class Solution {
public:
    int n;
    inline int findSteps(vector<int>& nums, bool isInc=1){
        int s=isInc?1:n-2, e=isInc?n:-1, d=(isInc<<1)-1, i, j;
        for( i=s; i!=e; i+=d){
            if (nums[i-d]>nums[i]) break;
        }
        if (i==e) return 1-isInc; 
        if (nums[e-d]>nums[s-d]) return -1;

        for ( j=i+d; j!=e; j+=d){ 
            if (nums[j-d]>nums[j]) break; 
        }
        if (j!=e) return -1;
        int k=i+1-isInc;
        return min(k+1-isInc, n-k+1+isInc); 
    }
    int minOperations(vector<int>& nums) {
        n=nums.size();
        if (n==1) return 0;
        int step=findSteps(nums, 1);
        if (step!=-1) return step;
        return findSteps(nums, 0);
    }
};