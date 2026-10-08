class Solution {
public:
    string removeOuterParentheses(string s) {
        int bal = 0;
        string str;
        for(int i=0; i<s.length()-1;i++){
           if(s[i] == '('){
            if(bal>0) str+="(";
            bal++;
           }
           else if( s[i] == ')'){
            bal--;
            if(bal > 0){
                str+=")";
            }
           }
        }   
        return str; 
    }
};