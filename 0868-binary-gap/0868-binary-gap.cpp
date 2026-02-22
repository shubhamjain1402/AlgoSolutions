class Solution {
public:
    string tobs(int n){
        string s;
        while(n>0){
            s+=to_string(n%2);
            n=n/2;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    int binaryGap(int n) {
        string s=tobs(n);
        int gap=0;
        int ind=-1;
        for(int i=0;i<s.size();i++){
            if(s[i] == '1')   {
                ind=i;
                break;}
        }
        for(int i=ind+1;i<s.size();i++){
            if(s[i] == '1'){
                gap=max(gap,i-ind);
                ind=i;
            }
        }
        return gap;
    }
};