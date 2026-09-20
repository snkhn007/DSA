class Solution {
public:
    int reverseDegree(string s) {

        int res = 0;
        for(int i=0; i<s.length(); i++){
            int revVal = 26 - (s[i] - 'a');
            res += revVal*(i+1);
            // cout<<mp[s[i]];
            // res += (mp[s[i]] * (i+1));
        }
        return res;
    }
};