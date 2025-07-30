class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> isPrime(n, true);
        isPrime[0]=isPrime[1]=false;
        int cnt=1;
        for (int i = 3; i< n; i+=2) {
            if (isPrime[i] == true) {
                cnt++;
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return cnt;
    }
};