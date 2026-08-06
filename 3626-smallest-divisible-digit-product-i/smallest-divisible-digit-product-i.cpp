class Solution {
public:
    int fun(int num )
 {
    int prod = 1;
    if(num==0) return 0;
    while(num>0){
        prod = prod *  (num%10);
        num = num/10;

    }
    return prod;
    
 }  
    int smallestNumber(int n, int t) {
       

        while(true){
            if(fun(n)%t==0){
                return n;
            }
            else{
                n++;
            }
        }

         }
};