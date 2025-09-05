class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack <int> st;
        int n=heights.size();
        int maxarea=INT_MIN;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int element = st.top();
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                maxarea=max(heights[element]*(nse-pse-1),maxarea);
            }
            st.push(i);
        }
    while(!st.empty()){
        int nse=n;
        int element=st.top();
        st.pop();
        int pse=st.empty()?-1:st.top();
        maxarea=max(heights[element]*(nse-pse-1),maxarea);
    }
    return maxarea;
    }
};