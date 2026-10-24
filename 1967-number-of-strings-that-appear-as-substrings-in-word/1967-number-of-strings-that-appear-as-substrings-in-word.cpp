class Solution {
public:
    bool chk(string text, string ptrn) {
        int n = text.size(), m = ptrn.size();
        for(int i=0; i<= n-m; i++){
            int j = 0;
            while( j< m && ptrn[j] == text[i+j]) j++;
            if(j == m) return true;
        }
        return false;
    }
    int numOfStrings(vector<string>& patterns, string word) {
        int res = 0;
        for(auto i : patterns){
            if(chk(word, i)) res++;
        }
        return res;
    }
};