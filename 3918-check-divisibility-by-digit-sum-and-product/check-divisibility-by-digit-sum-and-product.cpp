class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0 ; 
        int prod = 1 ;
        int ex = n;
        while(n>0){

            int rem = n%10;

            sum+=rem;
            prod *= rem;

            n/=10;
        }

        if(ex%(sum+prod) == 0 ){
                return true;
        }
        else {
            return false;
        }
    }
};