class Solution {
public: 
    int totalNumbers(vector<int>& digits) {
        unsigned freq1=0, freq2=0, freq3=0;
        for (int x : digits) {
            freq3|=freq2 & (1<<x);
            freq2|=freq1 & (1<<x);
            freq1|=(1<<x);
        }
        constexpr unsigned EVEN=0b101010101;
        unsigned E1=freq1 & EVEN, N1=(freq1>>1)<<1;
        unsigned E2=freq2 & EVEN, N2=(freq2>>1)<<1;
        unsigned E2_nz=(E2>>1)<<1;
        unsigned E3_nz=((freq3 & EVEN)>>1)<<1;


        int c1=(popcount(N1)*popcount(E1)-popcount(N1 & E1))*(popcount(freq1)-2);

        int c2a=popcount(N2)*popcount(E1)-popcount(N2 & E1);

        int c2b=popcount(E2_nz)*(popcount(freq1)-1);

        int c2c=popcount(E2)*popcount(N1)-popcount(E2 & N1);

        int c3=popcount(E3_nz);

        return c1+c2a+c2b+c2c+c3;
    }
};