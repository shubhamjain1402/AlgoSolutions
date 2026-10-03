class Solution {
    void func(string &s, int n,vector <string> &res,int cnto, int cntc){
        if(cnto == n && cntc == n){
            res.push_back(s);
            return ;
        }
        if(cnto < n){
            s.push_back('(');
            func(s,n,res,cnto+1,cntc);
            s.pop_back();
        }
        if(cntc < cnto){
            s.push_back(')');
            func(s,n,res,cnto,cntc+1);
            s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector <string> res;
        string s="";
        func(s,n,res,0,0);
        return res;
    }
};