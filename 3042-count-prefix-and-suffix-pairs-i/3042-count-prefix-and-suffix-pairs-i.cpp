class Solution {
public:
    bool suffix(string text, string ptrn) {
        int n = text.size(), m = ptrn.size();
        if (n < m) return false;
        int j = 0;
        while (j < m && text[n - m + j] == ptrn[j]) j++;
        return j == m;
    }
    bool prefix(string text, string ptrn){
        int n = text.size(), m = ptrn.size();
        if( n < m) return false;
        int j = 0;
        while (j < m && text[j] == ptrn[j])j++;
        return j == m;
    } 
 
    int countPrefixSuffixPairs(vector<string>& word) {
        int ans = 0;
        for(int i=0; i<word.size(); i++){
            // for(int j = 0; j<word.size(); j++){
            for(int j = i + 1; j < word.size(); j++){
                if(i != j) {
                    // bool res = suffix(word[i], word[j]) && prefix(word[i], word[j]);
                    bool res = suffix(word[j], word[i]) && prefix(word[j], word[i]);
                    if( res ) ans++;
                }
            }
        }
        return ans;
        
    }
};