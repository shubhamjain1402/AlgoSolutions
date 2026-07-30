class Solution {
public:
    int minimumPushes(string word) {
        vector<int> ar(26, 0);

        for (auto x : word)
            ar[x - 'a']++;

        sort(ar.rbegin(), ar.rend());

        int ans = 0;

        for (int i = 0; i < 8; i++)
            ans += ar[i] * 1;

        for (int i = 8; i < 16; i++)
            ans += ar[i] * 2;

        for (int i = 16; i < 24; i++)
            ans += ar[i] * 3;

        for (int i = 24; i < 26; i++)
            ans += ar[i] * 4;

        return ans;
    }
};
