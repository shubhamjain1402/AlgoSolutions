class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set <int> st;
        for(auto it: nums){
            st.insert(it);
        }
        for(int i=k;;i+=k){
            if(st.find(i) == st.end()){
                return i;
            }
        }
        return 0;
    }
};