class Solution {
public:
    int maxDepth(string s) {
        int res = 0, cnt = 0;
        for(auto i : s){
            if(i == '(') cnt++;
            else if(i == ')') cnt--;
            res = max(cnt, res);
        }
        return res;
        
    }
};