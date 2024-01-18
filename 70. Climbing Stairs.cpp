class Solution {
    int a[46];
public:
    int climbStairs(int n) {
        if(n<=3)  return a[n]=n;
        if(a[n] !=0) return a[n];
        return a[n] = climbStairs(n-1)+climbStairs(n-2);
    }
};
