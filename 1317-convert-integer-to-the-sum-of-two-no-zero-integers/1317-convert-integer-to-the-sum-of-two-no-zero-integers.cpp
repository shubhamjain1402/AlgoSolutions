class Solution {
public:
    bool checkZero(int n){
        int cnt=0;
        while(n!=0){
            int dig=n%10;
            n=n/10;
            if(dig == 0) cnt++;
        }
        return cnt;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<n;i++){
            if(checkZero(i) == 0 && checkZero(n-i) ==0) return {i,n-i}; 
        }
        return {-1,-1};
    }
};