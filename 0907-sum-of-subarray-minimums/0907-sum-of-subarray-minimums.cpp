class Solution {
public:
    vector <int> findNSE(vector <int> &arr,int n){
        stack<int> st;
        vector <int> nse(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i] ){
                st.pop();
            }
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nse;
    }
    vector <int> findPSEE(vector <int> &arr,int n){
        stack<int> st;
        vector <int> pse(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] > arr[i] ){
                st.pop();
            }
            pse[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return pse;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector <int> nse=findNSE(arr,n);
        vector <int> pse=findPSEE(arr,n);
        int total=0;
        int mod=(int)(pow(10,9)+7);
        for(int i=0;i<n;i++){
            int left=i-pse[i];
            int right=nse[i]-i;
            total=(total+(left*right*1LL*arr[i])%mod)%mod;
        }
        return total;
    }
};