#include <limits.h>

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;

        double ans=1.0;
        double m=n;
        long nn=abs((long)n);
        while(nn>0){
            if(nn%2 ==1){
                ans*=x;
                nn=nn-1;
            }
            else{
                x=x*x;
                nn=nn/2;
            }
        }
        if(m<0) ans=1/ans;

        return ans;
    }
};