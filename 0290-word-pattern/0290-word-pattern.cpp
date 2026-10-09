
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> word;
        string wrd = "";
        for(char i:s) {
            if (i !=' ') wrd += i;
            else{
                word.push_back(wrd);
                wrd ="";
            }
        }
        word.push_back(wrd);
        if(pattern.size()!= word.size()) return false;
        // map<char, string> mp;
        // for(int i = 0; i< pattern.size(); i++) {
        //     if(mp.find(pattern[i]) == mp.end()) {
        //         mp[pattern[i]] = word[i];
        //         continue;            }

        //     if(mp[pattern[i]]!= word[i]) return false;
        // }
        map<char, string> mp;
        map<string, char> rev;
        for(int i= 0; i < pattern.size(); i++) {
            if(mp.find(pattern[i])== mp.end()) {
                if(rev.find(word[i]) != rev.end())
                    return false;
                mp[pattern[i]]= word[i];
                rev[word[i]] = pattern[i];
            }
            else {
                if(mp[pattern[i]] != word[i])
                    return false;
            }
        }

        return true;
    }
};