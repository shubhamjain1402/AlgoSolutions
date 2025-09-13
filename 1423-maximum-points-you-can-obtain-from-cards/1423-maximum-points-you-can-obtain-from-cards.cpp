class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0,rsum=0,maxsum=0;
        for(int i=0;i<k;i++){
            lsum+=cardPoints[i];
            maxsum=lsum;
        }
        int rindex=cardPoints.size()-1;
        for(int i=k-1;i>=0;i--){
            lsum=lsum-cardPoints[i];
            rsum=rsum+cardPoints[rindex];
            maxsum=max(maxsum,lsum+rsum);
            rindex--;
        }
        return maxsum;
    }
};