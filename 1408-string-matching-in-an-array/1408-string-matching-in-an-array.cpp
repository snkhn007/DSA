class Solution {
public:
    bool isSubString(string text, string ptrn){
        int n = text.size(), m = ptrn.size();
        if(m > n) return false;

        for(int i=0; i<=n-m; i++){
            int j = 0;
            while( j < m && text[i+j] == ptrn[j])j++;
            if( j == m) return true;
        }

        return false;
    }
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for(int i=0; i<words.size(); i++){
            for(int j=0; j<words.size(); j++){
                if(i != j){
                    bool res = isSubString(words[i], words[j]);
                    if(res) {
                        // ans.push_back(words[j]);
                        // break;
                        if (find(ans.begin(), ans.end(), words[j]) == ans.end()) {
                            ans.push_back(words[j]);
                        }
                    }
                }
            }
        }
        return ans;
    }
};