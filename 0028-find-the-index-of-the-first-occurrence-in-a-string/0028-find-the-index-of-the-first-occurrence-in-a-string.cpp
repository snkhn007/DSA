class Solution {
public:
    int strStr(string text, string pattern) {
        if(pattern.empty()) return 0;
        int m = pattern.size();
        vector<int> lps(m);
        lps[0] = 0;
        int len = 0, i = 1;
        while(i < m){
            if(pattern[i] == pattern[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len != 0){
                    len = lps[len-1];
                }else{
                    lps[i] = 0;
                    i++;
                }
            }
        }

        int j = 0;
        i = 0;
        while( i < text.size()){
            if(text[i] == pattern[j]){
                i++;
                j++;
                if(j == m) return i - j;
            }else{
                if(j != 0) j = lps[j-1];
                else i++;
            }
        }

        return -1;
    }
};