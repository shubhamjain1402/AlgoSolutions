class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int maxarea = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxarea = max(heights[element] * (nse - pse - 1), maxarea);
            }
            st.push(i);
        }
        while (!st.empty()) {
            int nse = n;
            int element = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxarea = max(heights[element] * (nse - pse - 1), maxarea);
        }
        return maxarea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n == 0)
            return 0;
        int m = matrix[0].size();
        int maxarea = 0;
        vector<vector<int>> prefixSum(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (matrix[i][j] == '1') {
                    prefixSum[i][j] = (i == 0 ? 1 : prefixSum[i - 1][j] + 1);
                } else {
                    prefixSum[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            maxarea = max(maxarea, largestRectangleArea(prefixSum[i]));
        }

        return maxarea;
    }
};
