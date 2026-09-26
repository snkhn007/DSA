class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string res = "";
        bool popTemp = false;
        string temp = "";

        unordered_map<string, string> mp;
        for(auto item : knowledge) {
            mp[item[0]] = item[1];
        }

        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                popTemp = true;
                continue;
            }
            if(s[i] == ')'){
                popTemp = false;
                if(mp.find(temp) == mp.end()) res += '?';
                else res += mp[temp];
                temp = "";
                continue;
            }
            if(popTemp) {
                temp += s[i];
            }
            else {
                res += s[i];
            }

        }
        return res;
    }
};