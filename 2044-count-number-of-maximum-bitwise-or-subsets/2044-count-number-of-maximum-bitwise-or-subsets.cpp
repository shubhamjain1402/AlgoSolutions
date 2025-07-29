class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int targetOr=0;
        for(int i=0;i<nums.size();i++){
            targetOr |=nums[i];
        }
        return recur(0,nums,0,targetOr);
    }
    int recur(int ind,vector<int>& nums,int currOr,int targetOr){
        if(ind==nums.size()){
            return (currOr == targetOr)?1:0;
        }
        int pickCnt=recur(ind+1,nums,currOr|nums[ind],targetOr);
        int nopickCnt=recur(ind+1,nums,currOr,targetOr);
        return pickCnt+nopickCnt;

    }
};