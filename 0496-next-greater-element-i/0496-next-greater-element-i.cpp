class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        unordered_map<int,int> mpp;
        mpp.reserve(n);
        stack<int> st;
        vector<int> ans;
        mpp[nums2[n-1]]=-1;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i])  st.pop();
            if(st.empty())  mpp[nums2[i]]=-1;
            else    mpp[nums2[i]]=st.top();
            st.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++)
        ans.push_back(mpp[nums1[i]]);
        return ans;
    }
};