class Solution {
public:
    bool chk(string text, string ptrn){
        int n = text.size(), m = ptrn.size();
        if(n < m) return false;
        // for(int i=0; i<=n-m; i++){
        //     int j = 0;
        //     while( j<m && text[i+j] == ptrn[j]) j++;
        //     if(j == m) return true;
        // }
        int j = 0, i = 0;
        while(j <m && text[i] == ptrn[j]){
            j++;
            i++;
        }
        if(j == m) return true;
        return false;
    }
    int isPrefixOfWord(string sentence, string searchWord) {
        int index = 1;
        string word = "";
        for(int i=0; i<sentence.size(); i++){
            if(sentence[i] != ' ') word+=sentence[i];
            else{
                bool res = chk(word, searchWord);
                if(res) return index;
                word = "";
                index++;
                // cout<<word<<" ";
                // word = "";
                // cout<<index<<" ";
            }
        }
        // cout<<word;
        // cout<<index;
        bool res = chk(word, searchWord);
        if(res) return index;
        return -1;        
    }
};