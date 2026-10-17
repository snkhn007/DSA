class Solution {
public:
    bool chk(string text, string ptrn){
        int m = text.size(), n=ptrn.size();
        if( m < n ) return false;

        int j = 0;
        while (j < n && text[j] == ptrn[j]) j++;
        return j == n;

        if( j == n) return true;
        return false;
    }
    int prefixCount(vector<string>& words, string pref) {
        int res = 0;
        for(auto i : words){
            if(chk(i, pref)) {
                res++;
                // cout<<pref<<" exists in: "<<i<<endl;
            }
        }
        return res;
    }
};