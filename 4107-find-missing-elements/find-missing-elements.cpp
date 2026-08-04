class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        if (nums.empty()) return {};
        sort(nums.begin(), nums.end());
        int i=0;
         int sum = nums[0];
        int n = nums.size();
        vector<int> ans;
        while(i<n){
            
            if(nums[i]==sum){
                i++;
                sum++;
            }
            else if(nums[i]>sum){
                 ans.push_back(sum);
               sum++;
            }
           else{
            i++;
           }
        }
        return ans;
    }
};