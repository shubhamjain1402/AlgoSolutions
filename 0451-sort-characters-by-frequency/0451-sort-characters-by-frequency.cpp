class Solution {
public:
    static bool comp(pair <char,int> a,pair <char,int> b){
        return a.second > b.second;
    }
    string frequencySort(string s) {
        unordered_map <char , int> freq;
        for (char c : s) {
            freq[c]++;
        }
        vector <pair <char,int>> v(freq.begin(),freq.end());
        sort(v.begin(),v.end(),comp);
        string res="";
        for(auto &[x,y] : v){
            res.append(y,x);
        }
        return res;
    }
};