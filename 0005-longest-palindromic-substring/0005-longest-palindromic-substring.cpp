class Solution {
public:
    int expandString (string & str , int left , int right){
        while(left >= 0 && right < str.size() && str[left] == str[right]){
            left -- ;
            right ++;
        }
        return right - left -1 ;
    }
    string longestPalindrome(string s) {
        int start=0,end=0;
        for(int center=0 ; center < s.size() ; center ++){
            int lenOdd = expandString (s , center , center);
            int lenEven = expandString (s , center ,center + 1);
            int maxLen = max (lenOdd , lenEven);
            if(maxLen > end-start){
                start = center - (maxLen-1)/2;
                end = center + maxLen/2; 
            }
        }
        return s.substr(start , end-start + 1);
    }
};