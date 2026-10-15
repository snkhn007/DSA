class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        // for(int i=0; i<strs.size(); i++){
        //     cout<<strs[i]<<" ";
        // }
        int n = strs.size();
        string res = "";
        int i = 0;
        while(i < strs[0].length() && i < strs[n-1].length()){
            if(strs[0][i] == strs[n-1][i]) res+=strs[0][i++]; 
            else break;
        }
        return res;
    }
};