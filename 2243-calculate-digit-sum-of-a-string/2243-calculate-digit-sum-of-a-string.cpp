class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size() > k){
            string temp = "";
            int cnt = 0, sum = 0;
            for(int i=0; i<s.size(); i++){
                cnt++;
                // sum+=stoi(s[i]);
                sum += s[i] - '0';                
                if(cnt == k){
                    temp = temp+ to_string(sum);
                    sum = 0;
                    cnt = 0;
                }            
            }
            if(cnt > 0) temp += to_string(sum);
            s = temp;
        }
        return s;
    }
};