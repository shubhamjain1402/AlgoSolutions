class Solution {
public:
    int myAtoi(string s) {
        long long num = 0;
        int sign = 1;
        int flag = -1;
        for (char c : s) {
            if (c == ' ' && flag == -1)
                continue;
            else if (c == '+' && flag == -1) {
                sign = 1;
                flag = 1;
            } else if (c == '-' && flag == -1) {
                sign = -1;
                flag = 1;
            } else if (c >= '0' && c <= '9') {
                if (num > (LLONG_MAX - (c - '0')) / 10) {
                    return sign == 1 ? INT_MAX : INT_MIN;
                }
                num = num * 10LL + (long long)(c - '0');
                flag = 1;
            }
            else {
                break;
            }
        }
        num = num * sign;
        if (num > INT_MAX)
            num = INT_MAX;
        else if (num < INT_MIN)
            num = INT_MIN;
        return (int)num;
    }
};