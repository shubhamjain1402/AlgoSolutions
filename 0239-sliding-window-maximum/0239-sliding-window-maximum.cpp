class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;  // Corrected from 'dequeue' to 'deque'
        vector<int> list;
        
        for (int i = 0; i < nums.size(); i++) {
            // Remove indices that are out of the current window
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();
            
            // Maintain decreasing order in deque
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            
            dq.push_back(i);
            
            // Add the maximum for the current window
            if (i >= k - 1)
                list.push_back(nums[dq.front()]);
        }
        
        return list;
    }
};
