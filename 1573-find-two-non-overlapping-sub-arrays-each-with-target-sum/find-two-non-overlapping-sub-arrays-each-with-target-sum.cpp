constexpr int N=1e5;
int lens[N];
class Solution {
public:
    static int minSumOfLengths(vector<int>& arr, int target) {
        const int n=arr.size();
        int prv=1e9, ans=1e9, sum=0;
        for(int l=0, r=0; r<n; r++){
            sum+=arr[r];
            for(; sum>target; l++)
                sum-=arr[l];
            lens[r]=prv;
            if (sum==target){
                int len=r-l+1;
                if (l>0) 
                    ans=min(ans, len+lens[l-1]);
                lens[r]=min(lens[r], len);
            }
            prv=lens[r];
        }
        return ans>=1e9?-1:ans;
    }
};