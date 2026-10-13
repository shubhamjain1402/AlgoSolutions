class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector <int> temp;
        for(auto it:nums)   temp.push_back(abs(it));
        sort(temp.begin(),temp.end());
        long long maxi=0;
        int i=nums.size()-1;
        int j=0;
        while(j<i){
            maxi+=temp[i]*temp[i];
            maxi-=temp[j]*temp[j];
            i--;
            j++;
        }
        if(i == j) maxi+=temp[i]*temp[i];
        return  maxi;
    }
};