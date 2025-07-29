class Solution {
public:
    bool num_digits(int num) {
        int counter = 0;
        while (num != 0) {
            num /= 10;
            counter++;
        }
        if (counter % 2 == 0) {
            return true;
        }
        return false;
    }
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if(num_digits(nums[i])==true){
            count++;
            }
        }
        return count;
    }
};