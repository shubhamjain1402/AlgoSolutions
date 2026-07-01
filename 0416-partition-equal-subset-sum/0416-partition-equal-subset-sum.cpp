class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int sum=0;
        int n=arr.size();
        for(auto &it: arr) sum+=it;
        if(sum&1) return false;
        vector <bool> prev(sum/2+1);
        vector <bool> curr(sum/2+1);
        prev[0]=curr[0]=0;
        int target=sum/2;
        for(int i=0;i<n;i++) prev[0]=1;
        if(arr[0] <= target) prev[arr[0]]=1;
        for(int i=1;i<n;i++){
            for(int k=1;k<=target;k++){
                bool notpick=prev[k];
                bool pick=false;
                if(arr[i] <= k){
                    pick=prev[k-arr[i]];
                }
                curr[k]=pick|notpick;
            }
            prev=curr;
        }
        return prev[target];
    }
};