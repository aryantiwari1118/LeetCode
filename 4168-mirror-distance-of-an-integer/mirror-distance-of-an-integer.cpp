class Solution {
public:
    int rev(int num){
       long rev;
       while(num>0){
        int d = num % 10 ;
        rev = (rev*10) + d;
        num = num /10;
       }
       return rev;
    }
    int mirrorDistance(int n) {
        return abs(n-rev(n));
    }
};