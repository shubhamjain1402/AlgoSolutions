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

    long long sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector <int> nse=findNSE(arr,n);
        vector <int> pse=findPSEE(arr,n);
        long long total=0;
        for(int i=0;i<n;i++){
            int left=i-pse[i];
            int right=nse[i]-i;
            total=(total+(left*right*1LL*arr[i]));
        }
        return total;
    }
    vector <int> findNGE(vector <int> &arr,int n){
        stack<int> st;
        vector <int> nge(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] <= arr[i] ){
                st.pop();
            }
            nge[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nge;
    }
    vector <int> findPGEE(vector <int> &arr,int n){
        stack<int> st;
        vector <int> pge(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] < arr[i] ){
                st.pop();
            }
            pge[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return pge;
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
        int n=arr.size();
        vector <int> nse=findNGE(arr,n);
        vector <int> pse=findPGEE(arr,n);
        long long total=0;
        for(int i=0;i<n;i++){
            int left=i-pse[i];
            int right=nse[i]-i;
            total=(total+(left*right*1LL*arr[i]));
        }
        return total;
    }
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) -sumSubarrayMins(nums);
    }
};
