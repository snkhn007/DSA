class Solution {
public:
    bool checkString(string s) {
        bool chk = false;
        for(auto i : s){
            if(chk && i == 'a') return false;
            if(i == 'b') chk = true;
        }
        return true;
        
    }
};