class Solution {
public:
    int maxProduct(int n) {
        vector <int> arr;
        while(n != 0){
            int dig=n%10;
            n=n/10;
            arr.push_back(dig);
        }
        int maxi=0;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                maxi=max(maxi,arr[i]*arr[j]);
            }
        }
        return maxi;
    }
};