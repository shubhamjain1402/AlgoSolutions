class Solution {
public:
    vector<int> sumZero(int n) {
        vector <int> v;
        int sum=0;
        for(int i=1;i<n;i++){
            v.push_back(i);
            sum+=i;
        }
        v.push_back((0-sum));
        return v;
    }
};