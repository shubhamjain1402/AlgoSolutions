class Solution {
    int findDigitProduct(int n){
        int copy=n;
        int pro=1;
        while(copy!=0){
            pro*=copy%10;
            copy=copy/10;
        }    
        return pro;
    }
    public int smallestNumber(int n, int t) {
        int num=0;
        for(int i=n;i<=n+10;i++){
            if(findDigitProduct(i) % t == 0){    num=i;break;}
        }
        return num;
    }
}