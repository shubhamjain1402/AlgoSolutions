class Solution {
    int cntDigits(int n){
        int cnt=0;
        while(n!= 0){
            cnt++;
            n=n/10;
        }
        return cnt;
    }
public:
    int countCommas(int n) {
        int num= cntDigits(n) / 4;
        if(num == 0)    return 0;
        else return n-999;
    }
};