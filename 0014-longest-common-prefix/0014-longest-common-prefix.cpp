class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        // for(int i=0; i<strs.size(); i++){
        //     cout<<strs[i]<<" ";
        // }
        string res = "";
        int i = 0;
        while(i < strs[0].length() && i < strs[strs.size()-1].length()){
            if(strs[0][i] == strs[strs.size()-1][i]) res+=strs[0][i++]; 
            else break;
        }
        return res;
    }
};